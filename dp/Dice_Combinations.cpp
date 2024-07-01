#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

int n;
vector<int> dp(MAX_N, -1);

int countWays(int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (dp[sum] != -1)
        return dp[sum];

    int ways = 0;
    for (int i = 1; i <= 6; i++)
    {
        ways = (ways + countWays(sum - i)) % MOD;
    }

    return dp[sum] = ways;
}

int main()
{
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}