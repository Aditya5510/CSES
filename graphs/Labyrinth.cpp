#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<char>> &visited)
{
    return i >= 0 && i < n && j >= 0 && j < m &&
           grid[i][j] != '#' && visited[i][j] == 0;
}

bool dfs(int i, int j, string &ans,
         vector<vector<char>> &visited, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    visited[i][j] = 1;

    if (grid[i][j] == 'B')
    {
        return true;
    }

    if (isValid(i - 1, j, n, m, grid, visited))
    {
        ans += 'U';
        if (dfs(i - 1, j, ans, visited, grid))
            return true;
        ans.pop_back();
    }

    if (isValid(i, j + 1, n, m, grid, visited))
    {
        ans += 'R';
        if (dfs(i, j + 1, ans, visited, grid))
            return true;
        ans.pop_back();
    }

    if (isValid(i + 1, j, n, m, grid, visited))
    {
        ans += 'D';
        if (dfs(i + 1, j, ans, visited, grid))
            return true;
        ans.pop_back();
    }

    if (isValid(i, j - 1, n, m, grid, visited))
    {
        ans += 'L';
        if (dfs(i, j - 1, ans, visited, grid))
            return true;
        ans.pop_back();
    }

    return false;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<char>> visited(n, vector<char>(m, 0));
    string ans = "";

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                if (dfs(i, j, ans, visited, grid))
                {
                    found = true;
                    cout << "YES\n"
                         << ans.length() << "\n"
                         << ans << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
                break;
            }
        }
        if (found)
            break;
    }

    return 0;
}