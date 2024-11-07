// Source: https://www.youtube.com/watch?v=V8DGdPkBBxg

/*
Conversions
1 hr -> 60 mins
1 min -> 60 secs
1 ft -> 12 inches

Queries
4 hrs -> ? mins (240 mins)
2 ft -> ? hours (no valid conversion)
*/
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    string unit;
    vector<pair<int, Node*>> neighbors;
};

unordered_map<string, Node*> unit_to_node;

void process_conversions(vector<tuple<string, int, string>> conversions) {
    for (auto& conversion: conversions) {

        Node* start_node;
        Node* next_node;
        if (unit_to_node.count(get<0>(conversion))) {
            start_node = unit_to_node[get<0>(conversion)];
        } else {
            start_node = unit_to_node[make]

        }

    }
}

void process_queries(vector<tuple<int, string, string>>) {
}

int main() {
}
