#include <bits/stdc++.h>
using namespace std;

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack01(int wt[], int profit[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];

    // Step 1: Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - wt[i - 1]],
                               dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Step 2: Backtracking to find selected items
    int w = capacity;
    vector<int> selected;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected.push_back(i);
            w -= wt[i - 1];
        }
    }

    // Step 3: Print selected items
    cout << "Selected Items: ";
    for (int i = selected.size() - 1; i >= 0; i--)
        cout << "Item" << selected[i] << " ";
    cout << "\n";

    return dp[n][capacity];
}

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], profit[n], capacity;

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter profits of items: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    cout << "Maximum Profit (0/1 Knapsack) = "
         << knapsack01(wt, profit, n, capacity) << endl;

    return 0;
}