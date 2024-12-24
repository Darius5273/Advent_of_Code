#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
int main() {
    vector<string> grid;
    string line;

    while (getline(in, line)) {
            grid.push_back(line);
    }

    int h = grid.size();
    int w = grid[0].size();

    map<char, vector<pair<int, int>>> pos_mp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] != '.') {
                pos_mp[grid[i][j]].push_back({j, i});
            }
        }
    }

    set<pair<int, int>> un_nod;

    for (auto& entry : pos_mp) {
        vector<pair<int, int>> positions = entry.second;
        for (size_t i = 0; i < positions.size(); i++) {
            for (size_t j = i + 1; j < positions.size(); j++) {
                int x1 = positions[i].first, y1 = positions[i].second;
                int x2 = positions[j].first, y2 = positions[j].second;

                int dx = x2 - x1;
                int dy = y2 - y1;

                vector<pair<int, int>> nodes;

                int mid_x = x1 + dx / 2;
                int mid_y = y1 + dy / 2;
                if (dx % 2 == 0 && dy % 2 == 0) {
                    nodes.push_back({mid_x, mid_y});
                }

                int double_x1 = x2 + dx;
                int double_y1 = y2 + dy;
                int double_x2 = x1 - dx;
                int double_y2 = y1 - dy;

                nodes.push_back({double_x1, double_y1});
                nodes.push_back({double_x2, double_y2});

                for (auto& node : nodes) {
                    int x = node.first, y = node.second;
                    if (x >= 0 && x < w && y >= 0 && y < h) {
                        un_nod.insert({x, y});
                    }
                }
            }
        }
    }

    cout << un_nod.size() << '\n';

    return 0;
}