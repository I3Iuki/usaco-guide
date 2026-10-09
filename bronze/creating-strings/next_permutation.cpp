#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string line;
    cin >> line;
    sort(line.begin(), line.end());

    vector<string> lines;

    int count = 0;

    do
    {
        count++;
        lines.push_back(line);
    } while (next_permutation(line.begin(), line.end()));

    cout << count << '\n';

    for (string s : lines)
    {
        cout << s << '\n';
    }
}