#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    if (abs(a - b) == abs(b - c) == 1)
    {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }
    else if (abs(a - b) == 2 || abs(b - c) == 2)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }

    cout << max(abs(a - b), abs(b - c)) - 1 << '\n';

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}