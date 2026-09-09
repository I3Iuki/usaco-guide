#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    int temp;

    vector<int> sizes;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        sizes.push_back(temp);
    }

    sort(sizes.begin(), sizes.end(), [](const int &a, const int &b)
         { return a < b; });

    int max = 1;
    int l = 0;
    for (int r = 1; r < n; ++r)
    {
        while (sizes[r] - sizes[l] > k)
        {
            l++;
        }

        if (r - l > max)
        {
            max = r - l;
        }
    }

    cout << max + 1 << '\n';

    return 0;
}