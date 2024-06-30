#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long long sum = 0;
    for (int coin : coins)
    {
        if (coin > sum + 1)
        {
            break;
        }
        sum += coin;
    }

    cout << sum + 1 << endl;

    return 0;
}