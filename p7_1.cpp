#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;

bool target(long long val, vector<long long>& numbers) {
    int length = numbers.size();
    if (length == 1) {
        return numbers[0] == val;
    }

    for (int mask = 0; mask < (1 << (length - 1)); mask++) {
        long long result = numbers[0];
        for (int i = 1; i < length; i++) {
            if (mask & (1 << (i - 1))) {
                result *= numbers[i];
            } else {
                result += numbers[i];
            }
        }
        if (result == val) {
            return true;
        }
    }
    return false;
}

int main() {
    string input_line;
    long long s = 0;

    while (getline(in, input_line)) {

        stringstream ss(input_line);
        long long val;
        char separator;
        ss >> val >> separator;

        vector<long long> numbers;
        long long number;
        while (ss >> number) {
            numbers.push_back(number);
        }

        if (target(val, numbers)) {
            s += val;
        }
    }

    cout << s << endl;
    return 0;
}