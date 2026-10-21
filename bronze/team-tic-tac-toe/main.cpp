#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    // freopen("tttt.in", "r", stdin);
    // freopen("tttt.out", "w", stdout);

    array<array<char, 3>, 3> grid;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> grid[i][j];
        }
    }

    set<char> singles;
    set<uint16_t> teams;

    // row
    for (int i = 0; i < 3; ++i)
    {
        set<char> s;

        for (int j = 0; j < 3; ++j)
        {
            s.insert(grid[i][j]);
        }

        if (s.size() == 1)
        {
            singles.insert(*s.begin());
        }
        else if (s.size() == 2)
        {
            char a = *s.begin();
            char b = *next(s.begin(), 1);
            teams.insert(static_cast<uint16_t>(a | b));
        }
    }

    // column
    for (int i = 0; i < 3; ++i)
    {
        set<char> s;

        for (int j = 0; j < 3; ++j)
        {
            s.insert(grid[j][i]);
        }

        if (s.size() == 1)
        {
            singles.insert(*s.begin());
        }
        else if (s.size() == 2)
        {
            char a = *s.begin();
            char b = *next(s.begin(), 1);
            teams.insert(static_cast<uint16_t>(a | b));
        }
    }

    // diagonals
    for (int i = 0; i < 2; ++i)
    {
        set<char> s;

        if (i == 0)
        {
            s.insert(grid[0][0]);
            s.insert(grid[1][1]);
            s.insert(grid[2][2]);
        }
        else
        {
            s.insert(grid[0][2]);
            s.insert(grid[1][1]);
            s.insert(grid[2][0]);
        }

        if (s.size() == 1)
        {
            singles.insert(*s.begin());
        }
        else if (s.size() == 2)
        {
            char a = *s.begin();
            char b = *next(s.begin(), 1);
            teams.insert(static_cast<uint16_t>(a | b));
        }
    }

    cout << singles.size() << '\n';
    cout << teams.size() << '\n';

    // REMEMBER TO CLEAN UP INPUT FOR SUBMISSION!!!
    return 0;
}