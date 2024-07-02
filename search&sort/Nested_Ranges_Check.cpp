#include <bits/stdc++.h>
using namespace std;

// couldnt solve it , not in my abilities yet , will come back to it later
// https://cses.fi/problemset/task/2168

void range_containment(int n, vector<pair<int, int>> &ranges)
{
    // Step 1: Sort ranges by starting point, and by ending point descending if starting points are the same
    vector<tuple<int, int, int>> sorted_ranges;
    for (int i = 0; i < n; ++i)
    {
        sorted_ranges.push_back({ranges[i].first, ranges[i].second, i});
    }
    sort(sorted_ranges.begin(), sorted_ranges.end(), [](const auto &a, const auto &b)
         {
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b); });

    // Initialize the results
    vector<int> contains(n, 0);
    vector<int> contained_by(n, 0);

    // Step 2: Track the maximum ending point encountered so far
    int max_end = -1;
    for (const auto &[start, end, index] : sorted_ranges)
    {
        if (end <= max_end)
        {
            contained_by[index] = 1;
        }
        max_end = max(max_end, end);
    }

    // Track the minimum ending point encountered so far (for the reverse check)
    int min_end = INT_MAX;
    for (auto it = sorted_ranges.rbegin(); it != sorted_ranges.rend(); ++it)
    {
        int start, end, index;
        tie(start, end, index) = *it;
        if (end >= min_end)
        {
            contains[index] = 1;
        }
        min_end = min(min_end, end);
    }

    // Step 3: Output the results
    for (int i = 0; i < n; ++i)
    {
        cout << contains[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << contained_by[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> ranges[i].first >> ranges[i].second;
    }
    range_containment(n, ranges);
    return 0;
}
