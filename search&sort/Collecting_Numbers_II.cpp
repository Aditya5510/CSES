#include <bits/stdc++.h>
using namespace std;

// will solve this solme other time

// You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
// On each round, you go through the array from left to right and collect as many numbers as possible.
// Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.
// Input
// The first line has two integers n and m: the array size and the number of operations.
// The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
// Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<pair<int, int>> num_index(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        num_index[i] = {arr[i], i};
    }

    // Sort based on the number
    sort(num_index.begin(), num_index.end());

    // Calculate the initial number of groups
    int groups = 1;
    for (int i = 1; i < n; ++i)
    {
        if (num_index[i].second < num_index[i - 1].second)
        {
            ++groups;
        }
    }

    // Function to update groups count based on positions a and b
    auto update_groups = [&](int a, int b, int &groups)
    {
        int vals[4] = {arr[a], arr[b]};
        for (int val : vals)
        {
            if (val > 1)
            {
                int pos1 = num_index[val - 1].second;
                int pos2 = num_index[val - 2].second;
                if (pos1 < pos2 && (a == pos1 || b == pos1))
                    ++groups;
                if (pos1 > pos2 && (a == pos1 || b == pos1))
                    --groups;
            }
            if (val < n)
            {
                int pos1 = num_index[val].second;
                int pos2 = num_index[val - 1].second;
                if (pos1 < pos2 && (a == pos1 || b == pos1))
                    ++groups;
                if (pos1 > pos2 && (a == pos1 || b == pos1))
                    --groups;
            }
        }
    };

    // Output initial groups
    // cout << groups << '\n';

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        if (arr[a] > arr[b])
            swap(a, b);

        update_groups(a, b, groups);

        swap(arr[a], arr[b]);
        swap(num_index[arr[a] - 1].second, num_index[arr[b] - 1].second);

        update_groups(a, b, groups);

        // cout << groups << '\n';
    }

    return 0;
}
