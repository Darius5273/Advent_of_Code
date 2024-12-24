#include <bits/stdc++.h>

using namespace std;
ifstream in("in");
ofstream out("out");

bool is_valid_sequence( vector<int> sequence,  map<int, set<int>> dep) {
    for (size_t i = 0; i < sequence.size(); ++i) {
        auto it = dep.find(sequence[i]);
        if (it == dep.end()) continue;  

        for (int dependent : it->second) {
            auto found_pos = find(sequence.begin(), sequence.end(), dependent);
            if (found_pos != sequence.end() && distance(sequence.begin(), found_pos) <= static_cast<long>(i)) {
                return false; 
            }
        }
    }
    return true;
}

vector<int> topo_sort( vector<int> sequence,  map<int, set<int>> dep) {
    map<int, vector<int>> graph;
    set<int> nodes_set(sequence.begin(), sequence.end());

    for (int node : sequence) {
        auto it = dep.find(node);
        if (it != dep.end()) {
            for (int succ : it->second) {
                if (nodes_set.count(succ)) {
                    graph[node].push_back(succ);
                }
            }
        }
    }

    vector<int> sorted_result;
    set<int> visited, temp_set;

    function<bool(int)> dfs = [&](int node) {
        if (temp_set.count(node)) return false;
        if (visited.count(node)) return true;

        temp_set.insert(node);
        for (int succ : graph[node]) {
            if (!dfs(succ)) return false;
        }
        temp_set.erase(node);
        visited.insert(node);
        sorted_result.push_back(node);
        return true;
    };

    for (int node : sequence) {
        if (!visited.count(node) && !dfs(node)) {
            return {};  
        }
    }

    reverse(sorted_result.begin(), sorted_result.end());
    return sorted_result;
}

int calculate_corrected_sum( vector<vector<int>> sequences,  vector<pair<int, int>> rules) {
    map<int, set<int>> dependency_map;
    for (const auto& rule : rules) {
        dependency_map[rule.first].insert(rule.second);
    }

    int total = 0;
    for (const auto& seq : sequences) {
        if (!is_valid_sequence(seq, dependency_map)) {
            vector<int> sorted = topo_sort(seq, dependency_map);
            if (!sorted.empty()) {
                total += sorted[sorted.size() / 2];
            }
        }
    }
    return total;
}

int main() {
    string s;
    vector<pair<int, int>> rules;
    vector<vector<int>> sequences;
    bool parsing_rules = true;

    while (getline(in, s)) {
        if (s.empty()) continue;

        if (parsing_rules && s.find('|') != string::npos) {
            stringstream ss(s);
            int first, second;
            char delimiter;
            ss >> first >> delimiter >> second;
            rules.emplace_back(first, second);
        } else {
            parsing_rules = false;
            stringstream ss(s);
            vector<int> sequence;
            int number;
            while (ss >> number) {
                sequence.push_back(number);
                if (ss.peek() == ',') ss.ignore();  
            }
            if (!sequence.empty()) sequences.push_back(sequence);
        }
    }

    out << calculate_corrected_sum(sequences, rules) << '\n';

    return 0;
}