#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
bool reach(const vector<vector<bool>> &g) {
    int gSize = g.size();
    vector<vector<bool>> visited(gSize, vector<bool>(gSize, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [currentY, currentX] = q.front();
        q.pop();

        if (currentY == gSize - 1 && currentX == gSize - 1) {
            return true;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nextY = currentY + dy[dir];
            int nextX = currentX + dx[dir];

            if (nextY >= 0 && nextY < gSize && nextX >= 0 && nextX < gSize && !g[nextY][nextX] && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX});
            }
        }
    }
    return false;
}

int main() {
    vector<pair<int, int>> pos;
    int xCoord, yCoord;
    char separator;

    while (in >> xCoord >> separator >> yCoord) {
        pos.push_back({xCoord, yCoord});
    }

    const int g_SIZE = 71;
    vector<vector<bool>> g(g_SIZE, vector<bool>(g_SIZE, false));

    for (size_t i = 0; i < pos.size(); ++i) {
        g[pos[i].second][pos[i].first] = true;

        if (!reach(g)) {
            out << pos[i].first << "," << pos[i].second << endl;
            break;
        }
    }

    return 0;
}