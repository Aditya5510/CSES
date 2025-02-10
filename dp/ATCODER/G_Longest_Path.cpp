#include <bits/stdc++.h>
using namespace std;

// longest path in a DAG

using ll = long long;

int main()
{

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    vector<ll> indeg(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<ll> q;

    for (ll i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<ll> topo;

    while (!q.empty())
    {
        ll element = q.front();
        q.pop();

        topo.push_back(element);

        for (auto neighbour : adj[element])
        {
            indeg[neighbour]--;
            if (indeg[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    // for (int i = 0; i < topo.size(); i++)
    // {
    //     cout << topo[i] << " " << endl;
    // }

    vector<ll> parent(n + 1, -1);
    vector<ll> dist(n + 1, 0);

    for (auto it : topo)
    {

        for (auto neighbour : adj[it])
        {
            if (dist[neighbour] < dist[it] + 1)
            {
                dist[neighbour] = dist[it] + 1;
                parent[neighbour] = it;
            }
        }
    }

    ll maxdist = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[maxdist])
        {
            maxdist = i;
        }
    }

    vector<ll> path;

    while (maxdist != -1)
    {
        path.push_back(maxdist);
        maxdist = parent[maxdist];
    }

    reverse(path.begin(), path.end());

    for (auto it : path)
    {
        cout << it << " ";
    }

    // cout << dist[maxdist] << endl;
}
