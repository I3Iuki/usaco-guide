#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    cin >> n;

    vector<char> letters(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> letters[i];
    }

    int k = 1;

    while (k <= n)
    {
        deque<char> window(letters.begin(), letters.begin() + k);
        set<string> s;

        bool good = true;

        for (int i = k; i < n + 1; ++i)
        {
            string line(window.begin(), window.end());

            if (s.count(line))
            {
                good = false;
                break;
            }
            else
            {
                s.insert(line);
            }

            window.pop_front();
            window.push_back(letters[i]);
        }

        if (good)
        {
            break;
        }

        k++;
    }

    cout << k << '\n';

    // REMEMBER TO CLEAN UP INPUT FOR SUBMISSION!!!
    return 0;
}