#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");
string s;
int cnt=0;

int main() {

    vector<int> left, right;
    string s;
    int l,r;
    while (getline(in, s)) {
        char* p = &s[0];
        sscanf(p,"%d %d",&l,&r);
        left.push_back(l);
        right.push_back(r);
    }

    unordered_map<int, int> freq;
    for (int num : right) {
        freq[num]++;
    }

    int d = 0;
    for (int num : left) {
        d += num * freq[num];
    }

    out << d << endl;

    return 0;
}
