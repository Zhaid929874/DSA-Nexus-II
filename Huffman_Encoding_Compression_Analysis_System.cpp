#include <bits/stdc++.h>
using namespace std;

// Node structure for Huffman Tree
struct Node
{
    char character;
    int frequency;
    Node *left;
    Node *right;

    Node(char c, int f)
    {
        character = c;
        frequency = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct CompareFreq
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

// Build Huffman Tree
Node *createHuffmanTree(vector<pair<char, int>> &freqList)
{
    priority_queue<Node *, vector<Node *>, CompareFreq> pq;

    for (auto &p : freqList)
        pq.push(new Node(p.first, p.second));

    while (pq.size() > 1)
    {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *parent = new Node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }
    return pq.top();
}

// Generate Huffman codes
void generateCodes(Node *root, string code,
                   unordered_map<char, string> &codeMap,
                   unordered_map<char, int> &freqMap,
                   int &totalHuffmanBits)
{
    if (!root)
        return;

    if (root->character != '$')
    {
        codeMap[root->character] = code;
        totalHuffmanBits += freqMap[root->character] * code.size();
    }

    generateCodes(root->left, code + "0", codeMap, freqMap, totalHuffmanBits);
    generateCodes(root->right, code + "1", codeMap, freqMap, totalHuffmanBits);
}

int main()
{
    int n;
    cout << "Enter string size: ";
    cin >> n;

    string input;
    cout << "Enter the string: ";
    cin >> input;

    if (input.size() != n)
    {
        cout << "Warning: Given size does not match string length!\n";
    }

    // Frequency count
    unordered_map<char, int> freqMap;
    for (char c : input)
    {
        freqMap[c]++;
    }

    // Convert to vector
    vector<pair<char, int>> freqList(freqMap.begin(), freqMap.end());

    // Sort by frequency
    sort(freqList.begin(), freqList.end(),
         [](auto &a, auto &b)
         {
             if (a.second == b.second)
                 return a.first < b.first;
             return a.second < b.second;
         });

    // Build tree
    Node *root = createHuffmanTree(freqList);

    // Generate codes
    unordered_map<char, string> codeMap;
    int totalHuffmanBits = 0;
    generateCodes(root, "", codeMap, freqMap, totalHuffmanBits);

    // Normal encoding
    int totalChars = input.size();
    int normalBits = totalChars * 8;

    // Output
    cout << "\nCharacter Frequencies:\n";
    for (auto &p : freqList)
        cout << p.first << " : " << p.second << endl;

    cout << "\nHuffman Codes:\n";
    for (auto &p : freqList)
        cout << p.first << " : " << codeMap[p.first] << endl;

    cout << "\nNormal Bits: " << normalBits;
    cout << "\nHuffman Bits: " << totalHuffmanBits;
    cout << "\nCompression Ratio = " << normalBits << ":" << totalHuffmanBits;

    if (totalHuffmanBits < normalBits)
    {
        double ratio = (double)normalBits / totalHuffmanBits;
        cout << "\nCompression ≈ " << fixed << setprecision(2) << ratio << ":1\n";
    }
    else
    {
        cout << "\nNo compression\n";
    }

    return 0;
}