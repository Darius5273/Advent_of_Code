#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

const int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

bool check(const vector<string>& grid, int row, int col, int dl, int dc) {
    string pattern = "XMAS";
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < 4; ++i) {
        int nrow = row + i * dl;
        int ncol = col + i * dc;
        if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || grid[nrow][ncol] != pattern[i]) {
            return false;
        }
    }
    return true;
}

int sol(const vector<string>& grid) {
    int cnt = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (grid[row][col] == 'X') {
                for (int i = 0; i < 8; ++i) {
                    int dl = dir[i][0];
                    int dc = dir[i][1];
                    if (check(grid, row, col, dl, dc)) {
                        ++cnt;
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    string s;
    vector<string> grid;

    while (gets(in, s)) {
            grid.push_back(s);
    }

    out <<sol(grid);

    return 0;
}