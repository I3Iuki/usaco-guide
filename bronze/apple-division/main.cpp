#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> apples;

long long recurse(int index, long long sum1, long long sum2)
{
    if (index == n)
    {
        return abs(sum1 - sum2);
    }

    return min(
        recurse(index + 1, sum1 + apples[index], sum2),
        recurse(index + 1, sum1, sum2 + apples[index]));
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        apples.push_back(0);
        cin >> apples[i];
    }

    cout << recurse(0, 0, 0) << '\n';
}
