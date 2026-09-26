#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

// make sure you have the right names before submitting / / /
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string line;
    getline(cin, line);

    stringstream ss(line);
    
    vector<char> paths;
    bool skip = false;
    
    for (int i = 0; i < 52; i++)
    {   
        if (paths[i] = paths[i + 1]) {
            paths.erase(paths.begin() + i);
            paths.erase(paths.begin() + i + 1);
            i++;
        }
    }
    
    

    return 0;
}