#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int boardSize = 8;

unordered_set<int> takenCols;
unordered_set<int> diag1;
unordered_set<int> diag2;
vector<string> blocked(boardSize);

int valid = 0;

void recurse(int curRow)
{
    if (curRow == boardSize)
    {
        valid++;
        return;
    }

    for (int i = 0; i < boardSize; ++i)
    {
        bool colAvailable = takenCols.count(i) == 0;
        bool diagAvailable = find(diag1.begin(), diag1.end(), i - curRow) == diag1.end() && find(diag2.begin(), diag2.end(), i + curRow) == diag2.end();
        bool unblocked = blocked[curRow][i] == '.';

        if (colAvailable && diagAvailable && unblocked)
        {
            takenCols.insert(i);
            diag1.insert(i - curRow);
            diag2.insert(i + curRow);
            recurse(curRow + 1);
            takenCols.erase(i);
            diag1.erase(i - curRow);
            diag2.erase(i + curRow);
        }
    }
}

int main()
{
    for (int i = 0; i < boardSize; ++i)
    {
        cin >> blocked[i];
    }

    recurse(0);

    cout << valid << '\n';
}
