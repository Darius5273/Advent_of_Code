#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");
string s;
int cnt=0;

int main() {

    string s;
    long long sum = 0;
    bool en = true; 

    while (getline(in, s)) {
        int idx = 0;

        while (idx < s.size()) {
            if (idx + 3 < s.size() && s[idx] == 'd' &&
                s[idx + 1] == 'o' && s[idx + 2] == '(' &&
                s[idx + 3] == ')') {
                en = true;  
                idx += 4;  
                continue;  
            }

            if (idx + 5 < s.size() && s[idx] == 'd' &&
                s[idx + 1] == 'o' && s[idx + 2] == 'n' &&
                s[idx + 3] == '\'' && s[idx + 4] == 't' &&
                s[idx + 5] == '(' && s[idx + 6] == ')') {
                en = false; 
                idx += 7;  
                continue; 
            }

            if (!en) {
                idx++;
                continue;
            }

            if (idx + 3 < s.size() && s[idx] == 'm' &&
                s[idx + 1] == 'u' && s[idx + 2] == 'l' &&
                s[idx + 3] == '(') {
                int st = idx + 4;  
                string first, second;

                while (st < s.size() && isdigit(s[st])) {
                    first += s[st];
                    ++st;
                }

                if (st >= s.size() || s[st] != ',' || first.size() > 3) {
                    idx = st;
                    continue;
                }
                st++; 

                while (st < s.size() && isdigit(s[st])) {
                    second += s[st];
                    ++st;
                }

                if (st >= s.size() || s[st] != ')') {
                    idx = st;
                    continue;
                }

                if (!first.empty() && !second.empty()) {
                    long long num1 = stoll(first);
                    long long num2 = stoll(second);
                    if (num1 <= 999 && num2 <= 999) {
                        sum += num1 * num2;
                    }
                }

                idx = st;
                continue;
            }

            idx++;  // Move to the next character
        }
    }

    cout << sum << endl;
    return 0;
}
