#include <bits/stdc++.h>
using namespace std;

struct zahid {
    int u, v, w;
};

int main()
{
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    vector<zahid> graph(edges);

    map<char, int> mp;      // char → index
    vector<char> rev;       // index → char
    int index = 0;

    cout << "Enter edges (u v w) using characters:\n";

    for (int i = 0; i < edges; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;

        if (mp.find(u) == mp.end())
        {
            mp[u] = index++;
            rev.push_back(u);
        }
        if (mp.find(v) == mp.end())
        {
            mp[v] = index++;
            rev.push_back(v);
        }

        graph[i].u = mp[u];
        graph[i].v = mp[v];
        graph[i].w = w;
    }

    char sourceChar;
    cout << "Enter source node: ";
    cin >> sourceChar;

    int V = index;
    vector<int> dist(V, INT_MAX);

    int source = mp[sourceChar];
    dist[source] = 0;

    // Bellman-Ford relaxation
    for (int i = 1; i <= V - 1; i++)
    {
        for (auto &e : graph)
        {
            if (dist[e.u] != INT_MAX &&
                dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Negative cycle check
    for (auto &e : graph)
    {
        if (dist[e.u] != INT_MAX &&
            dist[e.v] > dist[e.u] + e.w)
        {
            cout << "Negative weight cycle detected!\n";
            return 0;
        }
    }

    cout << "\nShortest distances from source:\n";
    for (int i = 0; i < V; i++)
    {
        cout << rev[i] << " -> ";
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}