#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

using namespace std;
long long concatenate(long long x, long long y) {
    string y_str = to_string(y);
    return stoll(to_string(x) + y_str);
}

bool possible(long long val, vector<long long>& numbers) {
    int num_count = numbers.size();
    if (num_count == 1) {
        return numbers[0] == val;
    }

    for (int mask = 0; mask < pow(3, num_count - 1); mask++) {
        long long result = numbers[0];
        int current_mask = mask;

        for (int i = 1; i < num_count; i++) {
            int operation = current_mask % 3;
            current_mask /= 3;

            if (operation == 0) {
                result += numbers[i];
            } else if (operation == 1) {
                result *= numbers[i];
            } else {
                result = concatenate(result, numbers[i]);
            }
        }

        if (result == val) {
            return true;
        }
    }
    return false;
}

int main() {
    string line;
    long long s = 0;

    while (getline(in, line)) {
        stringstream ss(line);
        long long val;
        ss >> val;

        char sep;
        ss >> sep;  

        vector<long long> num_list;
        long long number;
        while (ss >> number) {
            num_list.push_back(number);
        }

        if (possible(val, num_list)) {
            s += val;
        }
    }

    out << s << endl;
    return 0;
}