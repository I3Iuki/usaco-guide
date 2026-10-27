#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
    char ch;

    void print()
    {
        for (int i = 0; i < this->y; ++i)
        {
            for (int j = 0; j < this->x; ++j)
            {
                cout << this->ch;
            }
            cout << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);

    Point a, b, c;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    a.ch = 'A';
    b.ch = 'B';
    c.ch = 'C';

    if (a.y > a.x)
        swap(a.x, a.y);
    if (b.y > b.x)
        swap(b.x, b.y);
    if (c.y > c.x)
        swap(c.x, c.y);

    if (a.x < b.x)
        swap(a, b);
    if (b.x < c.x)
        swap(b, c);
    if (a.x < b.x)
        swap(a, b);

    if ((a.x * a.y) + (b.x * b.y) + (c.x * c.y) != a.x * a.x)
    {
        cout << -1 << '\n';
        return 0;
    }
    // two cases:
    // E
    // T

    if (a.x == b.x && b.x == c.x)
    {
        cout << a.x << '\n';
        a.print();
        b.print();
        c.print();
        return 0;
    }

    int remaining_y = a.x - a.y;

    if (b.x == remaining_y)
        swap(b.x, b.y);
    if (c.x == remaining_y)
        swap(c.x, c.y);

    if (b.x + c.x != a.x || b.y != remaining_y || c.y != remaining_y)
    {
        cout << -1 << '\n';
        return 0;
    }

    cout << a.x << '\n';
    a.print();

    for (int i = 0; i < remaining_y; ++i)
    {
        for (int j = 0; j < b.x; ++j)
            cout << b.ch;
        for (int j = 0; j < c.x; ++j)
            cout << c.ch;
        cout << '\n';
    }

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}