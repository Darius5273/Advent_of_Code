#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
int main() {
    vector<string> map_grid;
    string input_line;

    while (getline(in, input_line)) {
            map_grid.push_back(input_line);
    }

    int row_count = map_grid.size();
    int col_count = map_grid[0].size();

    unordered_map<char, vector<pair<int, int>>> ch_pos;

    for (int row = 0; row < row_count; row++) {
        for (int col = 0; col < col_count; col++) {
            if (map_grid[row][col] != '.') {
                ch_pos[map_grid[row][col]].emplace_back(col, row);
            }
        }
    }

    set<pair<int, int>> res;

    for (auto& entry : ch_pos) {
        vector<pair<int, int>> positions = entry.second;

        if (positions.size() < 2) continue;

        for (int row = 0; row < row_count; row++) {
            for (int col = 0; col < col_count; col++) {
                bool valid = false;

                for (size_t i = 0; i < positions.size(); i++) {
                    for (size_t j = i + 1; j < positions.size(); j++) {
                        int x1 = positions[i].first, y1 = positions[i].second;
                        int x2 = positions[j].first, y2 = positions[j].second;

                        long long det = (long long)(x2 - x1) * (row - y1) -
                                                (long long)(y2 - y1) * (col - x1);

                        if (det == 0) {
                            res.insert({col, row});
                            valid = true;
                            break;
                        }
                    }
                    if (valid) break;
                }
            }
        }
    }

    cout << res.size() << endl;

    return 0;
}