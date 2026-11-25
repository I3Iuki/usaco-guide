#include <bits/stdc++.h>

using namespace std;

struct Rectangle
{
    int x1, y1, x2, y2;

    Rectangle(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}

    int area()
    {
        return (x2 - x1) * (y2 - y1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle a = Rectangle(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle b = Rectangle(x1, y1, x2, y2);

    cout << pow(max(max(a.x2, b.x2) - min(a.x1, b.x1), max(a.y2, b.y2) - min(a.y1, b.y1)), 2) << '\n';

    return 0;
}