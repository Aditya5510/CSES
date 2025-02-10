#include <iostream>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int min_flip_cost(const string &S, int k)
{
    int n = S.length();
    int total_cost = 0;
    int diff = 0;

    // Min-heap to store the cost of flipping B's (smallest cost has the highest priority)
    priority_queue<int, vector<int>, greater<int>> candidates;

    // Iterate over the string
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 'A')
        {
            diff += 1;
        }
        else
        { // S[i] == 'B'
            diff -= 1;
            int cost = pow(2, i + 1); // Cost is 2^(1-based index)
            candidates.push(cost);
        }

        // If diff falls below k, fix it by flipping the cheapest available B
        while (diff < k && !candidates.empty())
        {
            int flip_cost = candidates.top();
            candidates.pop();
            total_cost += flip_cost;
            diff += 2; // Flipping a B changes its contribution from -1 to +1
        }

        // If no more B's can be flipped and diff < k, return -1 (impossible case)
        if (diff < k)
        {
            return -1;
        }
    }

    return total_cost;
}

int main()
{
    string S = "BBBBB"; // Example input
    int k = 1;

    int result = min_flip_cost(S, k);
    cout << "Minimum cost: " << result << endl; // Expected output: 20

    return 0;
}
