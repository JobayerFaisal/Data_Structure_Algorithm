#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<vector<int>> &adj,
                         vector<bool> &visited,
                         stack<int> &Stack)
{
    visited[v] = true;

    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    Stack.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int V)
{
    stack<int> Stack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{

    int V = 4;

    vector<vector<int>> edges = {{1, 0}, {0, 2}, {1, 2}, {3, 2}};

    vector<vector<int>> adj(V);

    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);

    return 0;
}