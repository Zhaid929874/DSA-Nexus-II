#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman Tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparison object for priority queue (min-heap)
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq; // min-heap
    }
};

// Print Huffman Codes recursively
void printHuffmanCodes(Node *root, string str)
{
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch << ": " << str << endl;
    }

    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

// Build Huffman Tree and print codes
void huffmanCoding(unordered_map<char, int> &freqMap)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    // Create leaf nodes for each character
    for (auto pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Root node
    Node *root = pq.top();

    // Print Huffman Codes
    printHuffmanCodes(root, "");
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    unordered_map<char, int> freqMap;
    cout << "Enter characters and their frequency:\n";
    for (int i = 0; i < n; i++)
    {
        char c;
        int f;
        cin >> c >> f;
        freqMap[c] = f;
    }

    cout << "\nHuffman Codes:\n";
    huffmanCoding(freqMap);

    return 0;
}
