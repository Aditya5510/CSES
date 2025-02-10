#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = a - 1;
        b = b - 1;

        adj[a].push_back(b);
    }

    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto x : adj[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto x : ans)
    {
        cout << x + 1 << " ";
    }
    cout << "\n";

    return 0;
}