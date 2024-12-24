#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

bool stuck(const vector<string>& base_grid, pair<int, int> initial_pos, pair<int, int> block_pos) {
    vector<string> modified_grid = base_grid;
    modified_grid[block_pos.second][block_pos.first] = '#';

    pair<int, int> current_pos = initial_pos;
    int direction = 0;
    const vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<tuple<int, int, int>> visited_states;

    while (true) {
        auto current_state = make_tuple(current_pos.first, current_pos.second, direction);
        if (visited_states.count(current_state))
            return true;
        visited_states.insert(current_state);

        int new_y = current_pos.second + moves[direction].first;
        int new_x = current_pos.first + moves[direction].second;

        if (new_y < 0 || new_y >= (int)modified_grid.size() || new_x < 0 ||
            new_x >= (int)modified_grid[0].size()) {
            return false;
        }

        if (modified_grid[new_y][new_x] == '#') {
            direction = (direction + 1) % 4;
        } else {
            current_pos = {new_x, new_y};
        }

        if (visited_states.size() > 10000)
            return true;
    }
}

int main() {
    vector<string> mp;
    string input;
    while (getline(in, input)) {
        mp.push_back(input);
    }

    pair<int, int> start_point;
    for (int row = 0; row < mp.size(); row++) {
        for (int col = 0; col < mp[row].size(); col++) {
            if (mp[row][col] == '^') {
                start_point = {col, row};
                break;
            }
        }
    }

    int loops = 0;
    for (int y = 0; y < mp.size(); y++) {
        for (int x = 0; x < mp[0].size(); x++) {
            if (mp[y][x] == '#' ||
                (x == (int)start_point.first && y == (int)start_point.second)) {
                continue;
            }
            if (stuck(mp, start_point, {x, y})) {
                loops++;
            }
        }
    }

    out << loops << endl;

    return 0;
}