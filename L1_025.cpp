#include <cstdio>
#include <vector>
#include <set>
using namespace std;

vector<set<int>> graph;
set<int> method;
int cities;

bool judge() {
    for (int i = 1; i <= cities; i++) {
        if (method.find(i) != method.end())
            continue;
        for (int val : graph[i]) {
            if (method.find(val) == method.end())
                return false;
        }
    }
    return true;
}

int main()
{
    int routes, c1, c2, q, attackCount, temp;
    scanf("%d %d", &cities, &routes);
    graph.resize(cities + 1);
    for (int i = 0; i < routes; i++) {
        scanf("%d %d", &c1, &c2);
        graph[c1].insert(c2);
        graph[c2].insert(c1);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        method.clear();
        scanf("%d", &attackCount);
        for (int j = 0; j < attackCount; j++) {
            scanf("%d", &temp);
            method.insert(temp);
        }
        if (judge()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}