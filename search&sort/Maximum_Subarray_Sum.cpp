#include <bits/stdc++.h>

using namespace std;

// Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
// Input
// The first input line has an integer n: the size of the array.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    long long i = 0;
    long long j = 0;
    long long maxi = LLONG_MIN;
    long long curr_sum = 0;

    while (j < n)
    {
        curr_sum += v[j];

        maxi = max(maxi, curr_sum);

        // if(maxi>curr_sum)
        while (curr_sum < 0 && j >= i)
        {
            curr_sum -= v[i];
            i++;
        }

        j++;
    }

    cout << maxi << endl;

    return 0;
}