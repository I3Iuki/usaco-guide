#include <bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    // freopen("problem.in", "r", stdin);
    // freopen("problem.out", "w", stdout);

    int n;
    cin >> n;
    
    vector<int> list(n);

    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (list[i] != list[i - 1]) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}