#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool overlap = (c < b && b < d) || (c < a && a < d) || (a < c && c < b) || (a < d && d < b);  ;
    
    if (overlap) {
        cout << max(b, d) - min(a, c) << '\n';
    } else if (a == c && b == d) {
        cout << d - c << '\n';
    } else {
        cout << (b - a) + (d - c) << '\n';
    }

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}