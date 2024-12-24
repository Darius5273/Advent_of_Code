#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");
string s;
int cnt=0;

int main() {

    string s;
    long long sum = 0;

    while (getline(in, s)) {
        int len = s.size();

        for (int idx = 0; idx < len - 3; ++idx) {
            if (s[idx] == 'm' && s[idx + 1] == 'u' && s[idx + 2] == 'l' && s[idx + 3] == '(') {
                int pos = idx + 4;
                string firstNum, secondNum;

                while (pos < len && isdigit(s[pos])) {
                    firstNum += s[pos];
                    ++pos;
                }

                if (pos >= len || s[pos] != ',' || firstNum.size() > 3) {
                    continue;
                }
                ++pos;

                while (pos < len && isdigit(s[pos])) {
                    secondNum += s[pos];
                    ++pos;
                }

                if (pos >= len || s[pos] != ')' || secondNum.size() > 3) {
                    continue;
                }

                if (!firstNum.empty() && !secondNum.empty()) {
                    long long num1 = stoll(firstNum);
                    long long num2 = stoll(secondNum);

                    if (num1 <= 999 && num2 <= 999) {
                        sum += num1 * num2;  
                    }
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
