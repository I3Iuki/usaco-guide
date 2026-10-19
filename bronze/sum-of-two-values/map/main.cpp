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

    map<int, int> seen;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if (seen.count(target - temp))
        {
            cout << seen[target - temp] + 1 << " " << i + 1;
            return 0;
        }
        seen[temp] = i;
    }

    cout << "IMPOSSIBLE" << '\n';

    // REMEMBER TO CLEAN UP INPUT FOR SUBMISSION!!!
    return 0;
}