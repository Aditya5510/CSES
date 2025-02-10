#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll INF = 1e15; // or use something like 1e9, just to mark impossible states

// We'll store dp[u] = length of longest path from u to n
// par[u] = the child of u on that path
ll dfs(ll u, ll n, vector<ll> adj[], vector<ll> &dp, vector<ll> &par)
{
    // If we've already computed dp[u], return it
    if (dp[u] != -1)
        return dp[u];

    // Base case
    if (u == n)
    {
        dp[u] = 0;
        return 0;
    }

    // Otherwise, try all children
    ll best = -INF;
    ll best_child = -1;
    for (auto v : adj[u])
    {
        ll val = dfs(v, n, adj, dp, par);
        if (val >= 0 && 1 + val > best)
        {
            best = 1 + val;
            best_child = v;
        }
    }

    dp[u] = best; // might remain -INF if no child leads to n
    if (best_child != -1)
    {
        par[u] = best_child;
    }
    return dp[u];
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        // directed edge a -> b
        adj[a].push_back(b);
    }

    vector<ll> dp(n + 1, -1), par(n + 1, -1);

    // run DFS from 1
    ll ans = dfs(1, n, adj, dp, par);

    // if dp[1] is still negative, no path
    if (ans < 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // The length of the path in terms of nodes
    cout << ans + 1 << "\n";

    // Reconstruct from 1 going forward
    ll cur = 1;
    vector<ll> path;
    while (cur != -1)
    {
        path.push_back(cur);
        if (cur == n)
            break;
        cur = par[cur];
    }

    for (auto &x : path)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    fast;
    // ttt can be changed if multiple testcases
    int ttt = 1;
    // cin >> ttt;
    while (ttt--)
    {
        solve();
    }
    return 0;
}
