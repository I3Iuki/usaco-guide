#include <iostream>
#include <cstdio>


using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int largest = 0;
    for (int i = 0; i <= m; i += x) {
        int cur = i + ((m - i) / y) * y; 
        
        if (cur > largest) {
            largest = cur;
        }
    }

    cout << largest << '\n';

    return 0;
}