#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // make sure you have the right names before submitting / / /
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int n;
    string line;
    cin >> n >> line;

    if (line.find('1') == string::npos)
    {
        cout << line.size() - 1 << '\n';
        return 0;
    }

    int edge_d1 = 0;
    int edge_d2 = 0;

    int thirds = -1;
    int halves = -1;
    int edges = -1;
    int split = -1;
    int single_edge = -1;

    bool hasEdge_1 = line.front() == '0';
    bool hasEdge_2 = line.back() == '0';

    if (hasEdge_1)
        edge_d1 = line.find('1');
    if (hasEdge_2)
        edge_d2 = line.rfind('1');

    vector<string> zeros;
    string cur = "";

    int original_min = INT_MAX;
    int idx = -1;
    for (int i = 0; i < line.size(); ++i)
    {
        char c = line[i];
        if (c == '1')
        {
            if (cur.size() > 0)
                zeros.push_back(cur);
            cur = "";

            if (idx > -1)
            {
                original_min = min(original_min, i - idx);
            }
            idx = i;
        }
        else
        {
            cur += '0';
        }
    }

    if (cur.size() > 0)
        zeros.push_back(cur);

    sort(zeros.begin(), zeros.end(), [](const auto &a, const auto &b)
         { return a.size() > b.size(); });

    thirds = ceil(static_cast<double>(zeros[0].size()) / 3.0);
    split = min(static_cast<int>(ceil(static_cast<double>(zeros[0].size()) / 2.0)), max(edge_d1, edge_d2));
    if (zeros.size() > 1)
        halves = ceil(static_cast<double>(zeros[1].size()) / 2.0);
    if (zeros.size() == 1 && (hasEdge_1 || hasEdge_2))
        single_edge = floor(static_cast<double>(zeros[0].size()) / 2.0);

    if (edge_d1)
        edges = edge_d1;
    if (edge_d2)
        edges = min(edges, edge_d2);

    cout << min(max(max(max(thirds, halves), max(split, edges)), single_edge), original_min) << '\n';

    // cases:
    // thirds
    // two halves
    // two edges
    // one edge one half
    // no 1's (thirds guaranteed)

    // REMEMBER TO CLEAN UP OUTPUT FOR SUBMISSION!!!
    return 0;
}
