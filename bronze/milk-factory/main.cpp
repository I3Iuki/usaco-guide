#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    // {in degree, out degree}
    vector<pair<int, int>> stations(n + 1, {0, 0});

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        stations[a].second++;
        stations[b].first++;
    }

    int result = -1;

    for (int i = 1; i < n + 1; ++i)
    {
        if (stations[i].second == 0)
        {
            if (result == -1)
            {
                result = i;
            }
            else
            {
                result = -1;
                break;
            }
        }
    }

    cout << result << '\n';

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}