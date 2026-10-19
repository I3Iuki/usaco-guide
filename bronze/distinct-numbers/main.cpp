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
    
    unordered_set<int> thing;

    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        thing.insert(temp);
    }

    cout << thing.size() << '\n';

    return 0;
}