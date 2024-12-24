#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
 int dl[] = {-1, 0, 1, 0};
 int dc[] = {0, 1, 0, -1};

bool ins_grid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void dfs(int x, int y, int height, const vector<string>& grid, vector<vector<bool>>& visited, set<pair<int, int>>& reachablePositions, int rows, int cols) {
    if (!ins_grid(x, y, rows, cols) || visited[x][y])
        return;

    int currentHeight = grid[x][y] - '0';
    if (currentHeight != height)
        return;

    visited[x][y] = true;

    if (currentHeight == 9) {
        reachablePositions.insert({x, y});
        return;
    }

    for (int dir = 0; dir < 4; ++dir) {
        int newX = x + dl[dir];
        int newY = y + dc[dir];
        dfs(newX, newY, height + 1, grid, visited, reachablePositions, rows, cols);
    }
}

int find9(int startX, int startY, const vector<string>& grid, int rows, int cols) {
    set<pair<int, int>> reachable;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    dfs(startX, startY, 0, grid, visited, reachable, rows, cols);

    return reachable.size();
}

int main() {
    string line;
    vector<string> grid;

    while (getline(in, line)) {
            grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int scr = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '0') {
                int score = find9(i, j, grid, rows, cols);
                scr += score;
            }
        }
    }

    cout << scr << endl;

    return 0;
}