#include <bits/stdc++.h>

using namespace std;

// You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
// Input
// The first input line has two integers n and x: the array size and the target sum.
// The second line has n integers a_1,a_2,\dots,a_n: the array values.

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size() - 1;

    while (j >= i)
    {
        if (i == j)
        {
            cout << "IMPOSSIBLE" << endl;
            break;
        }

        if (v[i].first + v[j].first == k)
        {
            cout << v[j].second + 1 << " " << v[i].second + 1 << endl;
            break;
        }
        else if (v[i].first + v[j].first > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}