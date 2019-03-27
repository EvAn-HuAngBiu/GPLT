#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> cur;
bool visit[100001] = {false};
int maxLevel = 1;
unsigned long n;

void dfs(int p, int level) {
    if (!visit[p]) {
        visit[p] = true;
        if (level > maxLevel) {
            maxLevel = level;
            cur.clear();
            cur.push_back(p);
        } else if (level == maxLevel) {
            cur.push_back(p);
        }
        for (int i = 0; i < graph[p].size(); i++)
            dfs(graph[p][i], level + 1);
    }
}

int main() {
    scanf("%lu", &n);
    graph.resize(n + 1);
    int temp, root;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        if (temp == -1) root = i;
        else {
            graph[i].push_back(temp);
            graph[temp].push_back(i);
        }
    }
    dfs(root, 1);
    printf("%d\n", maxLevel);
    for (int i = 0; i < cur.size() - 1; i++)
        printf("%d ", cur[i]);
    printf("%d\n", cur[cur.size() - 1]);
    return 0;
}