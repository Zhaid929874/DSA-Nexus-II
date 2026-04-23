#include <bits/stdc++.h>
using namespace std;

// ===== Function to perform Topological Sort using Kahn's Algorithm =====
void topologicalSort(vector<vector<int>> &graph, int V)
{
    vector<int> indegree(V, 0);

    // Step 1: indegree calculate
    for (int u = 0; u < V; u++)
    {
        for (int v : graph[u])
            indegree[v]++;
    }

    // Step 2: queue for nodes with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topoOrder;

    // Step 3: BFS process
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topoOrder.push_back(u);

        for (int v : graph[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Step 4: cycle check
    if (topoOrder.size() != V)
        cout << "Graph has a cycle! Topological sort not possible." << endl;
    else
    {
        cout << "Topological Sort Order: ";
        for (int node : topoOrder)
            cout << node << " ";
        cout << endl;
    }
}

// ===== Main Function =====
int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter edges (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    topologicalSort(graph, V);

    return 0;
}