#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{

    // I didn't understand the problem and solved for the wrong problem.
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    // n = cows
    // m = genomes per cow
    int n, m;
    cin >> n >> m;

    vector<vector<char>> spotty(m, vector<char>(n));
    vector<vector<char>> plain(m, vector<char>(n));

    char c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            spotty[j][i] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            plain[j][i] = c;
        }
    }

    int count = 0;

    // iterate through positions of
    for (int i = 0; i < m; ++i)
    {

        count++;

        // true = good / go ahead
        // false = bad / don't do it
        bool yeah = true;

        if (spotty[i][0] == spotty[i][1])
        {
            for (int j = 2; j < n; ++j)
            {
                if (spotty[i][j] != spotty[i][j - 1])
                {
                    yeah = false;
                    break;
                }
            }

            if (yeah)
            {
                char lookFor = spotty[i][0];

                for (int j = 0; j < n; ++j)
                {
                    if (plain[i][j] == lookFor)
                    {
                        yeah = false;
                        break;
                    }
                }
            }
            else
            {
                yeah = true;
            }
        }

        if (!yeah)
        {
            count--;
            break;
        }

        if (plain[i][0] == plain[i][1])
        {
            for (int j = 2; j < n; ++j)
            {
                if (plain[i][j] != plain[i][j - 1])
                {
                    yeah = false;
                    break;
                }
            }

            if (yeah)
            {
                char lookFor = plain[i][0];

                for (int j = 0; j < n; ++j)
                {
                    if (spotty[i][j] == lookFor)
                    {
                        yeah = false;
                        break;
                    }
                }
            } 
        }
        else
        {
            yeah = false;
        }

        if (!yeah)
        {
            count--;
        }

    }

    cout << count;

    return 0;
}