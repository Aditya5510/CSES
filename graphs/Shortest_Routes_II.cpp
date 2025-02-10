#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    // Initialize adjacency matrix
    vector<vector<ll>> adj(n, vector<ll>(n, LLONG_MAX));

    for (int i = 0; i < n; i++)
    {
        adj[i][i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--; // Convert to 0-based indexing

        adj[a][b] = min(adj[a][b], w);
        adj[b][a] = min(adj[b][a], w);
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    // Process queries
    for (int i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        if (adj[a][b] == LLONG_MAX)
        {
            cout << -1 << endl; // No path
        }
        else
        {
            cout << adj[a][b] << endl; // Shortest path
        }
    }

    return 0;
}
