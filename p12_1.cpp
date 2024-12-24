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

void dfs(vector<vector<char>> &g, vector<vector<bool>> &v, int x, int y, char p, int &area, int &perimeter, int rows, int cols) {
    if (!valid(x, y, rows, cols) || v[x][y] || g[x][y] != p) return;

    v[x][y] = true;
    area++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!valid(nx, ny, rows, cols) || g[nx][ny] != p) perimeter++;
    }

    for (int i = 0; i < 4; i++) {
        dfs(g, v, x + dx[i], y + dy[i], p, area, perimeter, rows, cols);
    }
}

int main() {
    vector<string> lines;
    string line;
    while (getline(in, line)) {
        lines.push_back(line);
    }

    int rows = lines.size();
    int cols = lines[0].size();
    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = lines[i][j];
        }
    }

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    long long s = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j]) {
                int area = 0, perimeter = 0;
                dfs(grid, visited, i, j, grid[i][j], area, perimeter, rows, cols);
                s += (long long)area * perimeter;
            }
        }
    }

    cout << s << '\n';
    return 0;
}