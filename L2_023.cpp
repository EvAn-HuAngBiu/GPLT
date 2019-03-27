#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> color;


bool judge(int p) {
    for (int i : graph[p]) {
        if (color[i] == color[p])
            return false;
    }
    return true;
}

int main()
{
    int v, e, k, e1, e2, plans, c;
    scanf("%d %d %d", &v, &e, &k);
    graph.resize(v + 1);
    color.resize(v + 1);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &e1, &e2);
        graph[e1].push_back(e2);
        graph[e2].push_back(e1);
    }
    scanf("%d", &plans);
    bool error;
    for (int i = 0; i < plans; i++) {
        set<int> sc;
        error = false;
        for (int j = 1; j <= v; j++) {
            scanf("%d", &c);
            sc.insert(c);
            color[j] = c;
        }
        if (sc.size() != k) {
            printf("No\n");
            error = true;
        } else {
            for (int j = 1; j <= v; j++) {
                if (!judge(j)) {
                    printf("No\n");
                    error = true;
                    break;
                }
            }
        }

        if (!error)
            printf("Yes\n");
    }
    return 0;
}