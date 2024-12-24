#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
int main() {
    string seq;
    in >> seq;

    vector<int> blks;
    int curr_id = 0;

    for (int idx = 0; idx < seq.length(); idx++) {
        int repeat_count = seq[idx] - '0';
        if (idx % 2 == 0) {
            for (int i = 0; i < repeat_count; i++) {
                blks.push_back(curr_id);
            }
            curr_id++;
        } else {
            for (int i = 0; i < repeat_count; i++) {
                blks.push_back(-1);
            }
        }
    }

    while (true) {
        int end = blks.size() - 1;
        while (end >= 0 && blks[end] == -1) {
            end--;
        }
        if (end < 0) break;

        int start = 0;
        while (start < blks.size() && blks[start] != -1) {
            start++;
        }
        if (start >= end) break;

        blks[start] = blks[end];
        blks[end] = -1;
    }

    long long s = 0;
    for (int idx = 0; idx < blks.size(); idx++) {
        if (blks[idx] != -1) {
            s += (long long)idx * blks[idx];
        }
    }

    cout << s << endl;
    return 0;
}