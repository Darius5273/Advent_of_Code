#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
struct R {
    double x, y;
    int vx, vy;

    pair<int, int> posAtTime(int t) const {
        double nx = fmod(x + vx * t + 101, 101);
        double ny = fmod(y + vy * t + 103, 103);

        if (nx < 0) nx += 101;
        if (ny < 0) ny += 103;

        return {round(nx), round(ny)};
    }
};

int countadj(const vector<R> &robots, int t) {
    set<pair<int, int>> pos;
    for (const auto& r : robots) {
        pos.insert(r.posAtTime(t));
    }

    int cnt = 0;
    for (int y = 0; y < 103; y++) {
        for (int x = 0; x < 101 - 1; x++) {
            if (pos.count({x, y}) && pos.count({x + 1, y})) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    vector<R> robots;
    string line;

    while (getline(in, line)) {
        R r;
        sscanf(line.c_str(), "p=%lf,%lf v=%d,%d", &r.x, &r.y, &r.vx, &r.vy);
        robots.push_back(r);
    }

    for (int t = 0; t < 10000; t++) {
        int adj = countadj(robots, t);
        if (adj > 200) {
            cout << t << endl;
            break;
        }
    }
    return 0;
}