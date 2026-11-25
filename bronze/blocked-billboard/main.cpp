#include <bits/stdc++.h>

using namespace std;

// struct Rectangle
// {
//     array<int, 4> coords;

//     Rectangle(array<int, 4> arr) : coords(arr) {}
// };

struct Rectangle
{
    int x1, y1, x2, y2;

    Rectangle(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}

    int area()
    {
        return (x2 - x1) * (y2 - y1);
    }
};

int intersection(Rectangle a, Rectangle b)
{
    return max(0, min(a.y2, b.y2) - max(a.y1, b.y1)) * max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle a = Rectangle(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle b = Rectangle(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle truck = Rectangle(x1, y1, x2, y2);

    // [x1, y1, x2, y2]
    // (x1, y1) = lower-left corner
    // (x2, y2) = upper-right corner
    // x1 = left edge
    // x2 = right edge
    // y1 = bottom edge
    // y2 = top edge

    cout << a.area() + b.area() - intersection(a, truck) - intersection(b, truck) << '\n';

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}