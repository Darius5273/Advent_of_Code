#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;

long long g(string d, const vector<string> &p, unordered_map<string, long long> &m) {
    if (d.empty()) return 1;
    if (m.count(d)) return m[d];

    long long res = 0;
    for (auto &pat : p) {
        if (d.substr(0, pat.size()) == pat)
            res += g(d.substr(pat.size()), p, m);
    }

    m[d] = res;
    return res;
}

int main() {
    string str, temp;
    while (getline(in, temp)) str += temp + "\n";

    size_t pos = str.find("\n\n");
    string pStr = str.substr(0, pos), dStr = str.substr(pos + 2);

    vector<string> p, d;
    stringstream ps(pStr), ds(dStr);

    while (getline(ps, temp, ',')) p.push_back(temp.substr(temp.find_first_not_of(" ")));
    while (getline(ds, temp)) if (!temp.empty()) d.push_back(temp);

    long long res = 0;
    unordered_map<string, long long> m;

    for (auto &x : d) res += g(x, p, m);

    cout << res << "\n";
}