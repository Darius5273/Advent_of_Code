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
    vector<string> g;
    string l;
    while (getline(in, l))
        g.push_back(l);

    int h = g.size(), w = g[0].size();
    Pos start{0, 0}, end{0, 0};
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (g[y][x] == 'S') start = {x, y};
            else if (g[y][x] == 'E') end = {x, y};

    vector<Pos> path;
    set<pair<int, int>> vis;
    queue<Pos> q;
    q.push(start);

    const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (!q.empty()) {
        Pos p = q.front(); q.pop();
        path.push_back(p);
        if (p == end) break;

        vis.insert({p.x, p.y});
        vector<pair<int, int>> n;
        for (int i = 0; i < 8; ++i) {
            int nx = p.x + dx[i], ny = p.y + dy[i];
            if (nx >= 0 && nx < w && ny >= 0 && ny < h && g[ny][nx] != '#' && !vis.count({nx, ny}))
                n.push_back({nx, ny});
        }

        if (!n.empty()) q.push({n[0].first, n[0].second});
    }

    int cnt = 0;
    map<int, int> saved;

    for (size_t i = 0; i < path.size() - 1; ++i)
        for (size_t j = i + 1; j < path.size(); ++j) {
            int diff = j - i;
            int dx = abs(path[i].x - path[j].x), dy = abs(path[i].y - path[j].y);
            if (dx + dy <= 20) {
                int s = diff - (dx + dy);
                if (s >= 100) {
                    cnt++;
                    saved[s]++;
                }
            }
        }

    out << cnt;
}