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

    // make sure you have the right names before submitting
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle a = Rectangle(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle b = Rectangle(x1, y1, x2, y2);

    // if it covers the entire width
    if (
        (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y2 < a.y2 && b.y1 > a.y1) ||
        (b.y1 <= a.y1 && b.y2 >= a.y2 && b.x2 < a.x2 && b.x1 > a.x1))
    {

        cout << a.area() << '\n';
    } 
    else if (b.x1 <= a.x1 && b.x2 >= a.x2 && b.y2 >= a.y1 && b.y1 <= a.y2)
    {
        cout << a.area() - (a.x2 - a.x1) * (min(b.y2, a.y2) - max(b.y1, a.y1)) << '\n';
    }
    else if (b.y1 <= a.y1 && b.y2 >= a.y2 && b.x2 >= a.x1 && b.x1 <= a.x2)
    {
        cout << a.area() - (a.y2 - a.y1) * (min(b.x2, a.x2) - max(b.x1, a.x1)) << '\n';
    }
    else
    {
        // print the area of a
        cout << a.area() << '\n';
    }

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}