#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

vector<string> read_grid() {
    vector<string> grid;
    string line;
    while (getline(in, line)) {
        grid.push_back(line);
    }
    return grid;
}

pair<int, int> find_startition(const vector<string>& grid) {
    for (size_t row = 0; row < grid.size(); ++row) {
        for (size_t col = 0; col < grid[row].size(); ++col) {
            if (grid[row][col] == '^') {
                return {col, row};  
            }
        }
    }
    return {-1, -1};  
}

bool valid_move(int x, int y, const vector<string>& grid) {
    return x >= 0 && y >= 0 && y < grid.size() && x < grid[0].size();
}

void explore_grid(vector<string>& grid, pair<int, int>& start) {
    const vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  
    int current_direction = 0;  
    set<pair<int, int>> visited;  
    visited.insert(start);  

    pair<int, int> current_pos = start;

    while (true) {
        int new_y = current_pos.second + directions[current_direction].first;
        int new_x = current_pos.first + directions[current_direction].second;

        if (!valid_move(new_x, new_y, grid)) {
            break;  
        }

        if (grid[new_y][new_x] == '#') {
            current_direction = (current_direction + 1) % 4;
        } else {
            current_pos = {new_x, new_y};
            visited.insert(current_pos);
        }
    }

    cout << visited.size() << endl;  
}

int main() {
    vector<string> grid = read_grid();  
    pair<int, int> start = find_startition(grid);
    if (start.first == -1 || start.second == -1) {
        cout << 0 << endl; 
        return 0;
    }

    explore_grid(grid, start);  

    return 0;
}