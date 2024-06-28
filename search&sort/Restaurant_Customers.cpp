
// You are given the arrival and leaving times of n customers in a restaurant.
// What was the maximum number of customers in the restaurant at any time?
// Input
// The first input line has an integer n: the number of customers.
// After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and leaving times of a customer.
// You may assume that all arrival and leaving times are distinct.
// Output
// Print one integer: the maximum number of customers.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, +1});
        p.push_back({y, -1});
    }

    sort(p.begin(), p.end());
    int sum = 0;
    int maxi = 0;
    for (auto c : p)
    {
        sum += c.second;
        maxi = max(maxi, sum);
    }
    cout << maxi;

    return 0;
}