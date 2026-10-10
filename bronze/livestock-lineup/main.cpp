#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(1000, '\n');

    string line;
    vector<string> cows = {
        "Bessie",
        "Buttercup",
        "Belinda",
        "Beatrice",
        "Bella",
        "Blue",
        "Betsy",
        "Sue"};

    sort(cows.begin(), cows.end());

    unordered_map<string, vector<string>> constraints;

    for (int i = 0; i < n; ++i)
    {
        getline(cin, line);
        stringstream ss(line);

        string a, b;

        ss >> a;
        for (int j = 0; j < 4; ++j)
        {
            ss >> line;
        }
        ss >> b;

        auto it = constraints.find(a);

        if (it != constraints.end())
        {
            it->second.push_back(b);
        }
        else
        {
            constraints[a] = {b};
        }
    }

    do
    {
        bool yeah = true;

        for (int i = 0; i < 8; ++i)
        {
            for (const auto &[first, second] : constraints)
            {
                if (first == cows[i])
                {
                    for (int j = 0; j < second.size(); ++j)
                    {
                        bool x = i != 0 && cows[i - 1] == second[j];
                        bool y = i != 7 && cows[i + 1] == second[j];
                        if (!x && !y)
                        {
                            yeah = false;
                            break;
                        }
                    }
                }
            }

            if (!yeah)
            {
                break;
            }
        }

        if (yeah)
        {
            break;
        }
    } while (next_permutation(cows.begin(), cows.end()));

    for (const string &cow : cows)
    {
        cout << cow << '\n';
    }

    return 0;
}