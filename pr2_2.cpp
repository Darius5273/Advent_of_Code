#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");
string s;
int cnt=0;
int safe(vector<int> v)
{
    int n=v.size();
    bool incr = (v[0] - v[1] < 0);

    for (int i = 1; i < n ; ++i) {
        int diff = v[i] - v[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }

        if (diff < 0 && incr) {
            return false;
        } else if (diff > 0 && !incr) {
            return false;
        }
    }

    return true;
}
bool safe2(vector<int> v) {
    int n = v.size();

    if (safe(v)) {
        return true;
    }

    for (int i = 0; i < n; ++i) {
        vector<int> mod = v;
        mod.erase(mod.begin() + i);

        if (safe(mod)) {
            return true;
        }
    }

    return false;
}
int main() {

    while(getline(in,s))
    {
        vector<int> v;
        char* p = &s[0];
        char* token = std::strtok(p, " ");
        while (token != nullptr) {
            int nr = stoi(token);
            token = strtok(nullptr, " ");
            v.push_back(nr);
        }
        cnt+=safe2(v);
    }
    out<<cnt;
    return 0;
}
