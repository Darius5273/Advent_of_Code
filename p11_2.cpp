#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
vector<long long> transform(long long x) {
    if (x == 0) return {1};

    string s = to_string(x);
    int len = s.length();

    if (len % 2 == 0) {
        int mid = len / 2;
        return {stoll(s.substr(0, mid)), stoll(s.substr(mid))};
    } else {
        return {x * 2024};
    }
}

string add(const string& num1, const string& num2) {
    int len1 = num1.size(), len2 = num2.size();
    int carry = 0;
    string result;

    int i = len1 - 1, j = len2 - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        result = char('0' + (sum % 10)) + result;
    }
    return result;
}

int main() {
    map<long long, long long> counts;
    long long num;
    while (cin >> num) {
        counts[num]++;
    }

    string s = "0"; 

    for (int i = 0; i < 75; i++) {
        map<long long, long long> next;

        for (auto [num, cnt] : counts) {
            vector<long long> new_nums = transform(num);
            for (long long n : new_nums) {
                next[n] += cnt;
            }
        }

        counts = next;
    }

    for (auto [_, cnt] : counts) {
        string cnt = to_string(cnt);
        s = add(s, cnt); 
    }

    cout << s;  
    return 0;
}