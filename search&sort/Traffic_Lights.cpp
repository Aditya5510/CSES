#include <bits/stdc++.h>
using namespace std;

// There is a street of length x whose positions are numbered 0,1,\ldots,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
// Your task is to calculate the length of the longest passage without traffic lights after each addition.
// Input
// The first input line contains two integers x and n: the length of the street and the number of sets of traffic lights.
// Then, the next line contains n integers p_1,p_2,\ldots,p_n: the position of each set of traffic lights. Each position is distinct.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    set<int> positions = {0, x};
    multiset<int> gaps = {x};

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        auto it = positions.upper_bound(p);
        int right = *it;

        // cout << right << endl;
        int left = *prev(it);

        gaps.erase(gaps.find(right - left));
        gaps.insert(p - left);
        gaps.insert(right - p);

        positions.insert(p);

        cout << *gaps.rbegin() << " ";
    }

    return 0;
}