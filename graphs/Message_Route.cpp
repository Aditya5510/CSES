#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{

    int n, m;

    vector<vector<int>> adj(n, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a = a - 1;
        b = b - 1;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}