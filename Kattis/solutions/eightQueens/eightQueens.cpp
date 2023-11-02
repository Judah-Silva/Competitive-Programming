#include <iostream>
#include <vector>
using namespace std;

bool killingIntent(pair<int, int> first, pair<int, int> second);

int main()
{
    vector<pair<int, int>> queens;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            char piece;
            cin >> piece;
            if (piece == '*')
                queens.push_back({i, j});
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        for (int j = i + 1; j < 8; ++j)
        {
            if (killingIntent(queens[i], queens[j]))
            {
                cout << "invalid";
                return 0;
            }
        }
    }
    cout << "valid";
    return 0;
}

bool killingIntent(pair<int, int> a, pair<int, int> b)
{
    return ((a.first == b.first || a.second == b.second) || (abs(a.first - b.first) == abs(a.second - b.second)));
}
