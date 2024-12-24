#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
int main() {
    string s;
    in >> s;

    vector<int> ids;
    vector<int> sizes;
    vector<int> st_pos;
    vector<int> end_pos;

    int fileId = 0;
    int pos = 0;

    for (int i = 0; i < s.length(); i++) {
        int len = s[i] - '0';
        if (i % 2 == 0) {
            ids.push_back(fileId++);
            sizes.push_back(len);
            st_pos.push_back(pos);
            end_pos.push_back(pos + len - 1);
            pos += len;
        } else {
            pos += len;
        }
    }

    vector<int> blcks(pos, -1);
    for (int i = 0; i < ids.size(); i++) {
        for (int j = st_pos[i]; j <= end_pos[i]; j++) {
            blcks[j] = ids[i];
        }
    }

    for (int idx = ids.size() - 1; idx >= 0; idx--) {
        int fileSize = sizes[idx];
        int bestPos = -1;
        int curr_start = -1;
        int length = 0;

        for (int i = 0; i < st_pos[idx]; i++) {
            if (blcks[i] == -1) {
                if (curr_start == -1)
                    curr_start = i;
                length++;
                if (length >= fileSize) {
                    bestPos = curr_start;
                    break;
                }
            } else {
                curr_start = -1;
                length = 0;
            }
        }

        if (bestPos != -1) {
            vector<int> fileblcks(blcks.begin() + st_pos[idx],
                                        blcks.begin() + end_pos[idx] + 1);
            for (int i = st_pos[idx]; i <= end_pos[idx]; i++) {
                blcks[i] = -1;
            }
            for (int i = 0; i < fileSize; i++) {
                blcks[bestPos + i] = fileblcks[i];
            }
        }
    }

    long long checksum = 0;
    for (int i = 0; i < blcks.size(); i++) {
        if (blcks[i] != -1) {
            checksum += (long long)i * blcks[i];
        }
    }

    out << checksum << endl;
    return 0;
}