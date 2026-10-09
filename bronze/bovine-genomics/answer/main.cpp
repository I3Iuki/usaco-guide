#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    // n = cows
    // m = genomes per cow
    int n, m;
    cin >> n >> m;

    vector<unordered_set<char>> spotty(m, unordered_set<char>{});
    vector<unordered_set<char>> plain(m, unordered_set<char>{});

    char temp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> temp;
            spotty[j].insert(temp);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> temp;
            plain[j].insert(temp);
        }
    }

    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        count++;
        for (const char &c : spotty[i])
        {
            if (plain[i].find(c) != plain[i].end())
            {
                count--;
                break;
                ;
            }
        }
    }

    cout << count;
}