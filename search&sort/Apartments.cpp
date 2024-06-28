
// There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
// Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
// Input
// The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
// The next line contains n integers a_1, a_2, \ldots, a_n: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k.
// The last line contains m integers b_1, b_2, \ldots, b_m: the size of each apartment.
// Output
// Print one integer: the number of applicants who will get an apartment

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired_sizes(n);
    vector<int> apartment_sizes(m);

    for (int i = 0; i < n; ++i)
    {
        cin >> desired_sizes[i];
    }
    for (int j = 0; j < m; ++j)
    {
        cin >> apartment_sizes[j];
    }

    sort(desired_sizes.begin(), desired_sizes.end());
    sort(apartment_sizes.begin(), apartment_sizes.end());

    int i = 0, j = 0, count = 0;

    while (i < n && j < m)
    {
        if (apartment_sizes[j] >= desired_sizes[i] - k && apartment_sizes[j] <= desired_sizes[i] + k)
        {
            count++;
            i++;
            j++;
        }
        else if (apartment_sizes[j] < desired_sizes[i] - k)
        {

            j++;
        }
        else
        {
            i++;
        }
    }

    cout << count << endl;

    return 0;
}
