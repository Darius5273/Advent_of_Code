#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
bool f(string d, const vector<string> &p, unordered_map<string, bool> &m) {
    if (d.empty()) return true;
    if (m.count(d)) return m[d];

    for (auto &pat : p) {
        if (d.substr(0, pat.size()) == pat) {
            if (f(d.substr(pat.size()), p, m)) {
                m[d] = true;
                return true;
            }
        }
    }

    m[d] = false;
    return false;
}

int main() {
    string str, line;
    while (getline(in, line)) str += line + "\n";

    size_t pos = str.find("\n\n");
    string patStr = str.substr(0, pos), desStr = str.substr(pos + 2);

    vector<string> p, d;
    stringstream ss(patStr), ds(desStr);
    string temp;

    while (getline(ss, temp, ',')) p.push_back(temp.substr(temp.find_first_not_of(" ")));
    while (getline(ds, temp)) if (!temp.empty()) d.push_back(temp);

    int count = 0;
    unordered_map<string, bool> m;

    for (auto &x : d) if (f(x, p, m)) count++;

    out << count;
}