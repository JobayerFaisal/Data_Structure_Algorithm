#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> start_time, finish_time;
int timer = 0;

void dfs(int u, int parent)
{
    visited[u] = true;
    start_time[u] = timer++;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            cout << u << "->" << v << ": tree edge\n";
            dfs(v, u);
        }
        else if (v == parent)
        {

            continue;
        }
        else if (start_time[v] < start_time[u])
        {
            cout << u << "->" << v << ": back edge\n";
        }
        else if (finish_time[v] == -1)
        {
            cout << u << "->" << v << ": forward edge\n";
        }
        else
        {
            cout << u << "->" << v << ": cross edge\n";
        }
    }
    finish_time[u] = timer++;
}

int main()
{
    int n = 4;
    int m = 4;

    adj = {
        {1, 0},
        {0, 2},
        {1, 2},
        {3, 2}};

    visited.assign(n, false);
    start_time.assign(n, -1);
    finish_time.assign(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    return 0;
}
