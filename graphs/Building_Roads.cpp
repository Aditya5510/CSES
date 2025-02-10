#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);

    vector<int> representatives;

    for (int city = 1; city <= n; city++)
    {
        if (!visited[city])
        {
            representatives.push_back(city);

            queue<int> q;
            q.push(city);
            visited[city] = true;

            while (!q.empty())
            {
                int current = q.front();
                q.pop();
                for (int neighbor : graph[current])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    int k = (int)representatives.size() - 1;
    cout << k << "\n";

    for (int i = 1; i < (int)representatives.size(); i++)
    {
        cout << representatives[0] << " " << representatives[i] << "\n";
    }

    return 0;
}
