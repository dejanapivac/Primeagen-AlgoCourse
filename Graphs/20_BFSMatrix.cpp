#include <iostream>
#include <vector>
using namespace std;

vector<int> bfsMatrix(const vector<vector<int>> &graph, int source, int needle) {
    int rows = graph.size();
    int cols = graph[0].size();

    vector<bool> seen(vector<bool>(cols, false));
    vector<int> prev(vector<int>(cols, -1));

    seen[source] = true;
    vector<int> q;
    q.push_back(source);

    do {
        int curr = q[0];
        if(curr == needle) {
            break;
        }

        int adjs = graph[curr];
        for (int i = 0; i < graph.size(); ++i) {

        }
        seen[curr] = true;

    } while (q.size());
}

int main() {

    return 0;
}