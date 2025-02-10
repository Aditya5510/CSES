#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    vector<vector<ll>> dist(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    dist[1].emplace_back(0);
    while (!pq.empty())
    {
        ll cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (auto &[v, w] : adj[u])
        {
            ll new_cost = cost + w;
            if (dist[v].size() < k)
            {
                dist[v].emplace_back(new_cost);
                pq.emplace(new_cost, v);
            }
            else
            {
                ll max_cost = dist[v].back();
                if (new_cost < max_cost)
                {
                    dist[v].pop_back();
                    dist[v].emplace_back(new_cost);
                    pq.emplace(new_cost, v);
                }
            }
        }
    }
    vector<ll> result = dist[n];
    sort(result.begin(), result.end());
    for (int i = 0; i < k; i++)
        cout << result[i] << (i < k - 1 ? ' ' : '\n');
}
