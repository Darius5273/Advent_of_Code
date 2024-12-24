#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

const int dir[2][2] = {{-1, -1}, {1, 1}}; 

bool check(const vector<string> grid, int row, int col, int dl, int dc, bool reverse) {
    string pat = reverse ? "SAM" : "MAS";
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < 3; ++i) {
        int nrow = row + i * dl;
        int ncol = col + i * dc;
        if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || grid[nrow][ncol] != pat[i]) {
            return false;
        }
    }

    for (int i = 0; i < 3; ++i) {
        int nrow = row - i * dl;
        int ncol = col - i * dc;
        if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= cols || grid[nrow][ncol] != pat[i]) {
            return false;
        }
    }

    return true;
}

int sol(const vector<string> grid) {
    int cnt = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int row = 1; row < rows - 1; ++row) {
        for (int col = 1; col < cols - 1; ++col) {
            if (grid[row][col] != 'A') continue;  

            for (const auto& d : dir) {
                for (int rev1 = 0; rev1 <= 1; ++rev1) {
                    if (check(grid, row, col, d[0], d[1], rev1)) {
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
    while (getline(in, s)) {
            grid.push_back(s);
    }
    out << sol(grid) << endl;

    return 0;
}
