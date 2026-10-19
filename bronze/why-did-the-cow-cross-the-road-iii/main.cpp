#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        cows[i] = {a, b};
    }

    sort(cows.begin(), cows.end());

    int min_time = cows[0].first + cows[0].second;

    for (int i = 1; i < n; ++i)
    {
        int a = cows[i].first;
        int b = cows[i].second;

        if (a >= min_time)
        {
            min_time = a;
        }

        min_time += b;
    }

    cout << min_time;

    return 0;
}