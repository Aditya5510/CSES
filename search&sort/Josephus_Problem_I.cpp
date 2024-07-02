#include <bits/stdc++.h>
using namespace std;

// Consider a game where there are n children(numbered 1, 2,\dots, n)
// in a circle.During the game, every other child is removed from the circle until there are no children left.In which order will the children be removed ?

int main()
{
    int n;
    cin >> n;

    list<int> children;
    for (int i = 1; i <= n; i++)
    {
        children.push_back(i);
    }

    auto it = children.begin();

    while (children.empty() == false)
    {
        ++it;
        if (it == children.end())
        {
            it = children.begin();
        }

        cout << *it << " ";
        it = children.erase(it);

        if (it == children.end())
        {
            it = children.begin();
        }
    }

    return 0;
}