#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
int main() {
    vector<pair<int, int>> coord;
    int xCoord, yCoord;
    char sep;

    while (in >> xCoord >> sep >> yCoord) {
        coord.push_back({xCoord, yCoord});
    }

    const int SIZE = 71;
    vector<vector<bool>> map(SIZE, vector<bool>(SIZE, false));

    for (size_t i = 0; i < min<size_t>(1024, coord.size()); ++i) {
        map[coord[i].second][coord[i].first] = true;
    }

    vector<vector<int>> d(SIZE, vector<int>(SIZE, INT_MAX));
    queue<pair<int, int>> q;
    q.push({0, 0});
    d[0][0] = 0;

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [currY, currX] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newY = currY + dy[i];
            int newX = currX + dx[i];

            if (newY >= 0 && newY < SIZE && newX >= 0 && newX < SIZE && !map[newY][newX] && d[newY][newX] == INT_MAX) {
                d[newY][newX] = d[currY][currX] + 1;
                q.push({newY, newX});
            }
        }
    }

    out << d[SIZE - 1][SIZE - 1] << endl;

    return 0;
}