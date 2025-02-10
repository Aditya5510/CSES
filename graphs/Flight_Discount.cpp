#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dijk(int n, int m, vector<vector<pair<int, int>>> &graph)
{
    vector<vector<long long>> dist(n + 1, vector<long long>(2, LLONG_MAX));
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> pq;
    pq.push({0, {1, 0}}); // cost, node, used
    dist[1][0] = 0;       // start node

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        ll cost = node.first;
        int curr = node.second.first;
        int used = node.second.second;

        if (cost > dist[curr][used])
            continue;

        for (auto &edge : graph[curr])
        {
            int next = edge.first;
            int fcost = edge.second;

            ll ncost = cost + fcost;

            if (ncost < dist[next][used])
            {
                dist[next][used] = ncost;
                pq.push({ncost, {next, used}});
            }

            if (!used)
            {
                ll disc = cost + fcost / 2;
                if (disc < dist[next][1])
                {
                    dist[next][1] = disc;
                    pq.push({disc, {next, 1}});
                }
            }
        }
    }
    return min(dist[n][0], dist[n][1]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cout << dijk(n, m, graph) << endl;
    return 0;
}
