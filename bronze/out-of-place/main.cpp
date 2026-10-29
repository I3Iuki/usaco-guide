#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> cows;

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        if (i == 0 || cows.back() != temp)
        {
            cows.push_back(temp);
        }
    }

    int result = 0;

    for (int i = 0; i < cows.size() - 1; ++i)
    {
        int cur = cows[i];
        int next = cows[i + 1];


        if (cur > next)
        {
            swap(cows[i], cows[i + 1]);
            result++;
        }
    }


    for (int i = cows.size() - 1; i > 0; --i)
    {
        int cur = cows[i];
        int next = cows[i - 1];


        if (cur < next)
        {
            swap(cows[i], cows[i - 1]);
            result++;
        }
    }

    cout << result << '\n';

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}