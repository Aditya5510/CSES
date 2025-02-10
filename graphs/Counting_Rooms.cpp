#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<vector<bool>> &visited, const vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] != '.')
        return;

    visited[i][j] = true;
    vector<int> lr = {-1, 1, 0, 0};
    vector<int> ud = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        int dx = i + lr[k];
        int dy = j + ud[k];
        dfs(visited, grid, dx, dy, n, m);
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                dfs(visited, grid, i, j, n, m);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}