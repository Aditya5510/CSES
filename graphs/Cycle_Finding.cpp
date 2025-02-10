#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    struct Edge
    {
        int from;
        int to;
        ll cost;
    };
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    vector<ll> dist(n + 1, 0);
    vector<int> pred(n + 1, -1);
    int last = -1;

    for (int i = 1; i <= n; i++)
    {
        last = -1;
        for (auto &e : edges)
        {
            if (dist[e.from] + e.cost < dist[e.to])
            {
                dist[e.to] = dist[e.from] + e.cost;
                pred[e.to] = e.from;
                last = e.to;
            }
        }
    }
    if (last == -1)
    {
        cout << "NO";
    }
    else
    {
        int x = last;
        for (int i = 0; i < n; i++)
            x = pred[x];
        vector<int> cycle;
        int start = x;
        cycle.push_back(start);
        x = pred[x];
        while (x != start)
        {
            cycle.push_back(x);
            x = pred[x];
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for (int i = 0; i < cycle.size(); i++)
            cout << cycle[i] << (i < cycle.size() - 1 ? ' ' : '\n');
    }
}
