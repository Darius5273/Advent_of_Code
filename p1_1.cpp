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

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int d = 0;
    for (int i = 0; i < left.size(); ++i) {
        d += abs(left[i] - right[i]);
    }

    out << d << endl;
    return 0;
}
