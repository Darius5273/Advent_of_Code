#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool valid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool neigh(const vector<vector<char>> &g, pair<int, int> p, int dx, int dy, char t) {
    int nx = p.first + dx, ny = p.second + dy;
    return valid(nx, ny, g.size(), g[0].size()) && g[nx][ny] == t;
}

int cntBnd(const vector<pair<char, set<pair<int, int>>>> &regions, const vector<vector<char>> &g) {
    int h = 0, v = 0;
    auto scan = [](bool match, bool &seen, auto inc) {
        if (!match) {
            if (!seen) inc();
            return true;
        }
        return false;
    };

    for (const auto &[t, plots] : regions) {
        for (int i = 0; i < g.size(); i++) {
            bool up = false, down = false;
            for (int j = 0; j < g[0].size(); j++) {
                pair<int, int> p{i, j};
                if (!plots.count(p)) {
                    up = down = false;
                    continue;
                }
                up = scan(neigh(g, p, -1, 0, t), up, [&] { h++; });
                down = scan(neigh(g, p, 1, 0, t), down, [&] { h++; });
            }
        }

        for (int j = 0; j < g[0].size(); j++) {
            bool left = false, right = false;
            for (int i = 0; i < g.size(); i++) {
                pair<int, int> p{i, j};
                if (!plots.count(p)) {
                    left = right = false;
                    continue;
                }
                left = scan(neigh(g, p, 0, -1, t), left, [&] { v++; });
                right = scan(neigh(g, p, 0, 1, t), right, [&] { v++; });
            }
        }
    }
    return h + v;
}

set<pair<int, int>> floodFill(pair<int, int> start, const vector<vector<char>> &g) {
    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    set<pair<int, int>> filled;
    queue<pair<int, int>> q;
    q.push(start);
    filled.insert(start);
    char type = g[start.first][start.second];

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next{p.first + dx[i], p.second + dy[i]};
            if (valid(next.first, next.second, g.size(), g[0].size()) && g[next.first][next.second] == type && !filled.count(next)) {
                filled.insert(next);
                q.push(next);
            }
        }
    }
    return filled;
}

vector<pair<char, set<pair<int, int>>>> findRegions(const vector<vector<char>> &g) {
    vector<pair<char, set<pair<int, int>>>> regions;
    vector<vector<bool>> seen(g.size(), vector<bool>(g[0].size(), false));

    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            if (!seen[i][j]) {
                auto connected = floodFill({static_cast<int>(i), static_cast<int>(j)}, g);
                for (const auto &p : connected) seen[p.first][p.second] = true;
                regions.push_back({g[i][j], connected});
            }
        }
    }
    return regions;
}

int main() {
    vector<string> lines;
    string line;
    while (getline(in, line))
        lines.push_back(line);

    vector<vector<char>> grid(lines.size(), vector<char>(lines[0].size()));
    for (int i = 0; i < lines.size(); i++)
        for (int j = 0; j < lines[i].size(); j++)
            grid[i][j] = lines[i][j];

    long long s = 0;
    for (const auto &region : findRegions(grid))
        s += (long long)region.second.size() * cntBnd({region}, grid);

    cout << s << '\n';
    return 0;
}