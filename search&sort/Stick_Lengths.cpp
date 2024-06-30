#include <bits/stdc++.h>

using namespace std;

// There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
// You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
// What is the minimum total cost?
// Input
// The first input line contains an integer n: the number of sticks.
// Then there are n integers: p_1,p_2,\ldots,p_n: the lengths of the sticks.
// Output
// Print one integer: the minimum total cost.

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    long long m = 0;

    if (n % 2 == 0)
    {
        m = (v[n / 2 - 1] + v[n / 2]) / 2;
    }
    else
    {
        m = v[n / 2];
    }
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += abs(v[i] - m);
    }
    cout << ans << endl;
    return 0;
}