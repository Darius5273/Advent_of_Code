#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

bool validate_sequence(const vector<int> seq, const map<int, set<int>> dep) {
    for (size_t i = 0; i < seq.size(); ++i) {
        auto it = dep.find(seq[i]);
        if (it == dep.end()) continue;  // No dep for this number

        for (int dependent : it->second) {
            auto found_pos = find(seq.begin(), seq.end(), dependent);
            if (found_pos != seq.end() && distance(seq.begin(), found_pos) <= static_cast<long>(i)) {
                return false;  // Invalid because dependent appears too early
            }
        }
    }
    return true;
}

int calculate_valid_sum(const vector<vector<int>> &sequences, const vector<pair<int, int>> &rules) {
    map<int, set<int>> dependency_map;
    for (const auto &rule : rules) {
        dependency_map[rule.first].insert(rule.second);
    }

    int total = 0;
    for (const auto &seq : sequences) {
        if (validate_sequence(seq, dependency_map)) {
            total += seq[seq.size() / 2];
        }
    }
    return total;
}

int main() {
    string s;
    vector<pair<int, int>> rule_pairs;
    vector<vector<int>> number_sequences;
    bool reading_rules = true;

    while (gets(in, s)) {
        if (s.empty()) continue;

        if (reading_rules && s.find('|') != string::npos) {
            stringstream ss(s);
            int first, second;
            char delimiter;
            ss >> first >> delimiter >> second;
            rule_pairs.emplace_back(first, second);
        } else {
            reading_rules = false;
            stringstream ss(s);
            vector<int> sequence;
            int number;
            while (ss >> number) {
                sequence.push_back(number);
                if (ss.peek() == ',') ss.ignore();  // Ignore commas
            }
            if (!sequence.empty()) number_sequences.push_back(sequence);
        }
    }

    cout << calculate_valid_sum(number_sequences, rule_pairs) << '\n';

    return 0;
}