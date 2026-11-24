#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    // 1-based NOT 0-based; add 1 to index
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> pastures(n + 1, 0);

    for (int i = 1; i < n + 1; ++i)
    {
        array<bool, 5> used = {false, false, false, false, false};

        for (const int &x : adj[i])
        {
            used[pastures[x]] = true;
        }

        for (int j = 1; j < n + 1; ++j)
        {
            if (!used[j])
            {
                cout << j;
                pastures[i] = j;
                break;
            }
        }
    }

    cout << '\n';

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}