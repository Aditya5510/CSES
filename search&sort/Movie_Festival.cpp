#include <bits/stdc++.h>

// In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
// Input
// The first input line has an integer n: the number of movies.
// After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(movies.begin(), movies.end());

    int count = 0;
    int lastEnd = 0;

    for (auto movie : movies)
    {
        if (movie.second >= lastEnd)
        {
            count++;
            lastEnd = movie.first;
        }
    }

    cout << count << endl;

    return 0;
}