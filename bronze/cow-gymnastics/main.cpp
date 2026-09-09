#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main()
{
    // freopen("gymnastics.in", "r", stdin);
    // freopen("gymnastics.out", "w", stdout);

    int n, k;
    cin >> k >> n;

    set<pair<int, int>> x;
    vector<int> current(n, 0);

    int temp;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        current[i] = temp;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            x.insert(pair<int, int>{current[i], current[j]});
        }
    }

    for (int _ = 0; _ < k - 1; ++_)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            current[i] = temp;
        }

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // i / a always greater than j / b

                int a = current[i], b = current[j];

                if (x.find({b, a}) != x.end())
                {
                    x.erase({b, a});
                }
            }
        }
    }

    cout << x.size();
}

// justinhsu2011@gmail.com
// Instagram: Justinh214u

// 3 4
// 4 1 2 3
// 4 1 3 2
// 4 2 1 3