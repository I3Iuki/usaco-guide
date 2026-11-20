#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << unitbuf;

    // make sure you have the right names before submitting / / /
    // freopen("lineup.in", "r", stdin);
    // freopen("lineup.out", "w", stdout);

    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    sort(cows.begin(), cows.end());

    map<string, int> id;
    for (int i = 0; i < cows.size(); ++i)
        id[cows[i]] = i;

    int n;
    cin >> n;

    vector<vector<int>> adj(cows.size());

    for (int i = 0; i < n; ++i)
    {
        string trash, a, b;
        cin >> a >> trash >> trash >> trash >> trash >> b;

        adj[id[a]].push_back(id[b]);
        adj[id[b]].push_back(id[a]);
    }

    vector<bool> done(8, false);

    for (int i = 0; i < adj.size(); ++i)
    {
        if (done[i])
            continue;

        if (adj[i].size() == 0)
        {
            // cout << 'a' << '\n';
            cout << cows[i] << '\n';
            done[i] = true;
        }
        else if (adj[i].size() == 1)
        {
            int cur = i;
            int next = adj[cur][0];
            done[cur] = true;
            done[next] = true;
            // cout << 'b' << '\n';
            cout << cows[cur] << '\n';
            cout << cows[next] << '\n';

            while (true)
            {
                if (adj[next].size() == 2)
                {
                    if (done[adj[next][0]])
                    {
                        cout << cows[adj[next][1]] << '\n';
                        done[adj[next][1]] = true;
                        next = adj[next][1];
                    }
                    else if (done[adj[next][1]])
                    {
                        cout << cows[adj[next][0]] << '\n';
                        done[adj[next][0]] = true;
                        next = adj[next][0];
                    }
                    else
                    {
                        break;
                    }
                }
                else if (adj[next].size() == 1 && !done[adj[next][0]])
                {
                    cout << cows[adj[next][0]] << '\n';
                    done[adj[next][0]] = true;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}