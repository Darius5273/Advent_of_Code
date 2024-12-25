#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
const int INF = 1e9;
const vector<pair<int, int>> D = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct P {
    int y, x, d, c;
    P(int y, int x, int d, int c) : y(y), x(x), d(d), c(c) {}
    bool operator>(const P& other) const { return c > other.c; }
};

int main() {
    vector<string> g;
    string l;
    while (getline(in, l)) 
        g.push_back(l);

    int n = g.size(), m = g[0].size();
    pair<int, int> s, e;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'S') s = {i, j};
            if (g[i][j] == 'E') e = {i, j};
        }
    }

    vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(4, INF)));
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(s.first, s.second, 1, 0));

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int y = p.y, x = p.x, dir = p.d, cost = p.c;

        if (d[y][x][dir] < cost) continue;
        if (make_pair(y, x) == e) {
            cout << cost << "\n";
            return 0;
        }

        for (int newDir = 0; newDir < 4; newDir++) {
            int rotCost = 0;
            if (dir != newDir) {
                int diff = abs(newDir - dir);
                rotCost = (diff == 3 ? 1 : diff) * 1000;
            }

            int ny = y + D[newDir].first;
            int nx = x + D[newDir].second;

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && g[ny][nx] != '#') {
                int newCost = cost + rotCost + 1;
                if (newCost < d[ny][nx][newDir]) {
                    d[ny][nx][newDir] = newCost;
                    pq.push(P(ny, nx, newDir, newCost));
                }
            }
        }
    }

    return 0;
}