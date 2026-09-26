#include <iostream>
#include <set>
#include <string>
#include <algorithm>
 
using namespace std;
 
// aabac
string input;
set<string> results;
 
void recurse(set<int> used, string s)
{
    if (s.size() == input.size())
    {
        results.insert(s);
        return;
    }
 
    for (int i = 0; i < input.size(); ++i)
    {
        if (used.find(i) != used.end())
        {
            continue;
        }
        else
        {
            used.insert(i);
            recurse(used, s + input[i]);
            used.erase(i);
        }
    }
}
 
int main()
{
    cin >> input;
 
    recurse(set<int>{}, "");
 
    cout << results.size() << '\n';
 
    for (const string &booyeah : results)
    {
        cout << booyeah << '\n';
    }
