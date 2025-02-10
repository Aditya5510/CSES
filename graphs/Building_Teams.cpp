#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool dfs(ll col, vector<ll> &vis, vector<vector<ll>> &al, ll node)
{
    vis[node] = col;

    for (auto newnode : al[node])
    {

        if (!vis[newnode])
        {
            if (!dfs(!col, vis, al, newnode))
            {
                return false;
            }
        }
        else if (vis[newnode] && vis[newnode] == col)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(n, vector<ll>());

    // input

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a = a - 1;
        b = b - 1;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    // adj
    vector<ll> vis(n, 0);
    bool isbi = true;

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (!dfs(0, vis, al, i))
            {
                isbi = false;
            }
        }
    }

    if (isbi)
    {
        for (auto it : vis)
        {
            cout << it + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}