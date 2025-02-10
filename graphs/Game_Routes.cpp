#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> in_degree;
vector<int> topo_order;

void topological_sort(int n)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo_order.push_back(node);

        for (int neighbor : adj[node])
        {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0)
                q.push(neighbor);
        }
    }
}

int count_paths(int n)
{
    vector<long long> ways(n, 0);
    ways[0] = 1;

    for (int node : topo_order)
    {
        for (int neighbor : adj[node])
        {
            ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
        }
    }

    return ways[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    in_degree.resize(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    topological_sort(n);
    cout << count_paths(n) << endl;

    return 0;
}
