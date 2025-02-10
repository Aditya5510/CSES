#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static const string IMPOSSIBLE = "IMPOSSIBLE";

bool foundCycle = false;
vector<ll> cyclePath;

void dfs(ll node, ll parentNode,
         const vector<vector<ll>> &adj,
         vector<ll> &visited,
         vector<ll> &parent)
{
    visited[node] = 1;

    for (auto &nbr : adj[node])
    {

        if (nbr == parentNode)
            continue;

        if (!visited[nbr])
        {
            parent[nbr] = node;
            dfs(nbr, node, adj, visited, parent);

            if (foundCycle)
                return;
        }
        else if (visited[nbr] == 1)
        {

            foundCycle = true;
            vector<ll> tmpCycle;
            ll cur = node;
            tmpCycle.push_back(cur);

            while (cur != nbr)
            {
                cur = parent[cur];
                tmpCycle.push_back(cur);
            }

            reverse(tmpCycle.begin(), tmpCycle.end());

            tmpCycle.push_back(tmpCycle[0]);

            cyclePath = tmpCycle;
            return;
        }
    }
    visited[node] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> visited(n, 0);
    vector<ll> parent(n, -1);

    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, adj, visited, parent);
            if (foundCycle)
                break;
        }
    }

    if (!foundCycle)
    {
        cout << IMPOSSIBLE << "\n";
        return 0;
    }

    cout << cyclePath.size() << "\n";
    for (auto &city : cyclePath)
    {
        cout << city + 1 << " ";
    }
    cout << "\n";

    return 0;
}
