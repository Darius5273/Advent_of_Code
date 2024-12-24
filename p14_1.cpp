#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
struct R {
    double x, y;
    int vx, vy;

    void move() {
        x += vx;
        y += vy;
        if (x < 0) x += 101;
        if (y < 0) y += 103;
        x = fmod(x + 101, 101);
        y = fmod(y + 103, 103);
    }

    pair<int, int> getPos() const {
        return make_pair(round(x), round(y));
    }
};

int main() {
    int w = 101, h = 103, t = 100; 
    vector<R> robots;
    string line;

    while (getline(in, line)) {
        R r;
        sscanf(line.c_str(), "p=%lf,%lf v=%d,%d", &r.x, &r.y, &r.vx, &r.vy);
        robots.push_back(r);
    }

    for (int i = 0; i < t; ++i) {
        for (auto& r : robots) {
            r.move();
        }
    }

    vector<int> quadrants(4, 0);
    for (const auto& r : robots) {
        auto pos = r.getPos();
        int x = pos.first;
        int y = pos.second;

        if (x == w / 2 || y == h / 2) continue;

        int qIndex = (x > w / 2 ? 1 : 0) + (y > h / 2 ? 2 : 0);
        quadrants[qIndex]++;
    }

    long long result = 1;
    for (int count : quadrants) {
        result *= count;
    }

    out << result;
    return 0;
}