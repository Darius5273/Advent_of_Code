#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;

struct Pos {
    int x, y;
    bool operator==(Pos p) { return x == p.x && y == p.y; }
};

int main() {
    vector<string> grid;
    string l;
    while (getline(in, l))
        grid.push_back(l);

    int h = grid.size(), w = grid[0].size();
    Pos start{0, 0}, end{0, 0};
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (grid[y][x] == 'S') start = {x, y};
            else if (grid[y][x] == 'E') end = {x, y};

    vector<Pos> path;
    set<pair<int, int>> vis;
    queue<Pos> q;
    q.push(start);

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Pos curr = q.front(); q.pop();
        path.push_back(curr);
        if (curr == end) break;

        vis.insert({curr.x, curr.y});
        vector<pair<int, int>> ngh;
        for (int i = 0; i < 4; ++i) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] != '#' && !vis.count({nx, ny}))
                ngh.push_back({nx, ny});
        }

        if (!ngh.empty()) q.push({ngh[0].first, ngh[0].second});
    }

    int cnt = 0;
    map<int, int> saved;

    for (size_t i = 0; i < path.size() - 1; ++i)
        for (size_t j = i + 1; j < path.size(); ++j) {
            int skips = j - i;
            if (path[i].x == path[j].x || path[i].y == path[j].y) {
                int diffX = abs(path[i].x - path[j].x), diffY = abs(path[i].y - path[j].y);
                if (diffX + diffY <= 2) {
                    int skp = skips - (diffX + diffY);
                    saved[skp]++;
                    if (skp >= 100) cnt++;
                }
            }
        }

    out << cnt;
}