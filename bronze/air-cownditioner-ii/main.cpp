#include <bits/stdc++.h>

using namespace std;

struct AirConditioner
{
    int stallStart;
    int stallEnd;
    int cooling;
    int cost;

    AirConditioner(int a, int b, int c, int d) : stallStart(a), stallEnd(b), cooling(c), cost(d) {}
};

int n, m;
vector<int> needed(100, 0);
vector<AirConditioner> acs;

int lowestCost = INT_MAX;

void recurse(int index, int curCost, vector<int> cur)
{
    if (index == m)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (cur[i] < needed[i])
            {
                return;
            }
        }

        if (curCost < lowestCost)
        {
            lowestCost = curCost;
        }
        return;
    }

    recurse(index + 1, curCost, cur);
    for (int i = acs[index].stallStart - 1; i < acs[index].stallEnd; ++i)
    {
        cur[i] += acs[index].cooling;
    }
    recurse(index + 1, curCost + acs[index].cost, cur);
}

int main()
{
    // make sure you have the right names before submitting / / /
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        // cows
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = a - 1; j < b; ++j)
        {
            needed[j] = c;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        acs.emplace_back(a, b, c, d);
    }

    recurse(0, 0, vector<int>(100, 0));

    cout << lowestCost << '\n';

    return 0;
}
