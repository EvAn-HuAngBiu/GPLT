#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > graph;

int bfs(int begin) {
    queue<int> q;
    q.push(begin);
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++)
            q.push(graph[cur][i]);
    }
    return cur;
}

int main() {
    int nodes, cnt, val;
    cin >> nodes;
    graph.resize(nodes + 1);
    vector<int> outer(nodes + 1);
    for (int i = 1; i <= nodes; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> val;
            graph[i].push_back(val);
            outer[val]++;
        }
    }
    int begin;
    for (int i = 1; i <= nodes; i++) {
        if (outer[i] == 0) {
            begin = i;
            break;
        }
    }
    cout << bfs(begin) << endl;
    return 0;
}