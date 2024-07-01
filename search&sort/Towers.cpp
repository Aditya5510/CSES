#include <bits/stdc++.h>
using namespace std;

// You are given n cubes in a certain order, and your task is to build towers using them. Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
// You must process the cubes in the given order. You can always either place the cube on top of an existing tower, or begin a new tower. What is the minimum possible number of towers?
// Input
// The first input line contains an integer n: the number of cubes.
// The next line contains n integers k_1,k_2,\ldots,k_n: the sizes of the cubes.
// Output
// Print one integer: the minimum number of towers.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<int> towers;

    for (int i = 0; i < n; i++)
    {
        int cube;
        cin >> cube;

        auto it = towers.upper_bound(cube);
        if (it != towers.end())
        {
            towers.erase(it);
        }
        towers.insert(cube);
    }

    cout << towers.size() << "\n";

    return 0;
}