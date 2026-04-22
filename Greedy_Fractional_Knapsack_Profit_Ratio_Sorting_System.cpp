#include <bits/stdc++.h>
using namespace std;

struct Node
{
    float weight, profit, perweightProfit;
};

// Sort by profit/weight ratio (descending)
bool compareProfit(Node a, Node b)
{
    return a.perweightProfit > b.perweightProfit;
}

int main()
{
    int n, capacity;

    cout << "Enter Knapsack Capacity: ";
    cin >> capacity;

    cout << "Enter Number of Items: ";
    cin >> n;

    Node ara[n];

    cout << "Enter items weight and Profit: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i].weight >> ara[i].profit;
    }

    // Calculate profit per weight
    for (int i = 0; i < n; i++)
    {
        ara[i].perweightProfit = ara[i].profit / ara[i].weight;
    }

    // Sort by ratio
    sort(ara, ara + n, compareProfit);

    float current_weight = 0, current_profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_weight >= capacity)
            break;

        if (ara[i].weight <= capacity - current_weight)
        {
            current_weight += ara[i].weight;
            current_profit += ara[i].profit;
        }
        else
        {
            float weightLeft = capacity - current_weight;
            current_profit += ara[i].perweightProfit * weightLeft;
            current_weight = capacity;
            break;
        }
    }

    cout << "\nWeight Taken: " << current_weight;
    cout << "\nProfit Taken: " << current_profit;

    return 0;
}