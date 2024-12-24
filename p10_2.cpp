#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
const int dl[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

bool ins_grid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void dfs(int x, int y, int height, string& path, const vector<string>& grid, vector<vector<bool>>& visited, set<string>& paths, int rows, int cols) {
    if (!ins_grid(x, y, rows, cols) || visited[x][y])
        return;

    int curr_h = grid[x][y] - '0';
    if (curr_h != height)
        return;

    visited[x][y] = true;
    path += to_string(x) + "," + to_string(y) + ";";

    if (curr_h == 9) {
        paths.insert(path);
    } else {
        for (int dir = 0; dir < 4; ++dir) {
            int newX = x + dl[dir];
            int newY = y + dc[dir];
            dfs(newX, newY, height + 1, path, grid, visited, paths, rows, cols);
        }
    }

    path = path.substr(0, path.length() - (to_string(x).length() + to_string(y).length() + 2));
    visited[x][y] = false;
}

int countDistinctPaths(int startX, int startY, const vector<string>& grid, int rows, int cols) {
    set<string> paths;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    string currentPath;
    dfs(startX, startY, 0, currentPath, grid, visited, paths, rows, cols);

    return paths.size();
}

int main() {
    string line;
    vector<string> grid;

    while (getline(in, line)) {
            grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();
    long long s = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '0') {
                int rating = countDistinctPaths(i, j, grid, rows, cols);
                s += rating;
            }
        }
    }

    out << s;

    return 0;
}