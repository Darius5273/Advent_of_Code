#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
int digitCount(long long x) {
    int c = 0;
    if (x == 0) return 1;
    while (x) {
        x /= 10;
        c++;
    }
    return c;
}

pair<long long, long long> divide(long long x) {
    string s = to_string(x);
    int mid = s.length() / 2;
    return {stoll(s.substr(0, mid)), stoll(s.substr(mid))};
}

int main() {
    vector<pair<long long, int>> data;
    long long num;

    while (in >> num) {
        data.push_back({num, 1});
    }

    for (int i = 0; i < 25; i++) {
        vector<pair<long long, int>> temp;
        for (auto [val, cnt] : data) {
            if (val == 0) {
                temp.push_back({1, cnt});
            } else if (digitCount(val) % 2 == 0) {
                auto [l, r] = divide(val);
                temp.push_back({l, cnt});
                temp.push_back({r, cnt});
            } else {
                temp.push_back({val * 2024LL, cnt});
            }
        }
        data = temp;
    }

    long long s = 0;
    for (auto [_, cnt] : data) {
        s += cnt;
    }

    cout << s << '\n';
    return 0;
}