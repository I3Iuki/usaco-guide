#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);

    int n;
    cin >> n;

    deque<int> weights(n * 2);

    for (int i = 0; i < n * 2; ++i)
    {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int minInstability = INT_MAX;

    for (int i = 0; i < weights.size() - 1; ++i)
    {
        for (int j = i + 1; j < weights.size(); ++j)
        {

            int total = 0;
            int prev = -1;

            for (int k = 0; k < weights.size(); ++k)
            {
                if (k == i || k == j)
                {
                    continue;
                }

                if (prev == -1)
                {
                    prev = k;
                }
                else
                {
                    total += weights[k] - weights[prev];
                    prev = - 1;
                }
            }

            if (total < minInstability)
            {
                minInstability = total;
            }
        }
    }

    cout << minInstability;

    return 0;
}