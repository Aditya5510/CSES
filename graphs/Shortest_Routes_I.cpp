#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        a = a - 1;
        b = b - 1;

        adj[a].push_back({b, w});
    }

    vector<ll> dist(n, LLONG_MAX);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, 0});

    dist[0] = 0;

    while (!pq.empty())
    {

        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &[v, w] : adj[u])
        {

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
}