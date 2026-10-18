#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);

    int n, target;
    cin >> n >> target;

    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;

        vec[i] = {a, i};
    }

    sort(vec.begin(), vec.end());

    int l = 0, r = n - 1;

    while (l < r)
    {
        if (vec[l].first + vec[r].first == target)
        {
            cout << vec[l].second + 1 << " " << vec[r].second + 1 << '\n';
            return 0;
        }
        else if (vec[l].first + vec[r].first > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    // REMEMBER TO CLEAN UP INPUT FOR SUBMISSION!!!
    return 0;
}

//  1 2 5 7