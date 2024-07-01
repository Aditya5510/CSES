#include <bits/stdc++.h>
using namespace std;

// will do it tomorrow

// Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. During the game, every other child is removed from the circle until there are no children left. In which order will the children be removed?
// Input
// The only input line has an integer n.
// Output
// Print n integers: the removal order.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr;
    int i = 2;

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}