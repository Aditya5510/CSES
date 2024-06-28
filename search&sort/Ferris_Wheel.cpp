#include <bits/stdc++.h>

// There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
// Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
// What is the minimum number of gondolas needed for the children?
// Input
// The first input line contains two integers n and x: the number of children and the maximum allowed weight.
// The next line contains n integers p_1,p_2,\ldots,p_n: the weight of each child.
// Output
// Print one integer: the minimum number of gondolas.

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end(), greater<int>());

    int gondolas = 0;
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        if (left == right)
        {

            gondolas++;
            break;
        }

        if (v[left] + v[right] <= x)
        {

            left++;
            right--;
        }
        else
        {

            left++;
        }
        gondolas++;
    }

    cout << gondolas << endl;
    return 0;
}