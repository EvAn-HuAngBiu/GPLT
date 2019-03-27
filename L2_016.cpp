#include <cstdio>
#include <map>
#include <vector>
#include <set>

using namespace std;

struct People {
    int id;
    char sex;
    int father, mother;
};
map<int, People> m;
vector<vector<int>> graph(100000);
set<int> r1, r2;
bool visit[100000] = {false};

void bfs(int p, int setNum) {
    for (int val : graph[p]) {
        if (!visit[val]) {
            if (setNum == 1) r1.insert(val);
            else r2.insert(val);
            visit[val] = true;
        }
    }
}

int main() {
    int cnt, query, p1, p2;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        People p;
        scanf("%d %c %d %d", &p.id, &p.sex, &p.father, &p.mother);
        m[p.id] = p;
        if (p.father != -1) {
            graph[p.id].push_back(p.father);
            m[p.father] = {p.father, 'M', -1, -1};
        }
        if (p.mother != -1) {
            graph[p.id].push_back(p.mother);
            m[p.mother] = {p.mother, 'F', -1, -1};
        }
    }
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        scanf("%d %d", &p1, &p2);
        r1.clear();
        r2.clear();
        fill(begin(visit), end(visit), false);
        if (m[p1].sex == m[p2].sex)
            printf("Never Mind\n");
        else {
            r1.insert(p1);
            int times = 4;
            while (times--) {
                for (int val : r1)
                    bfs(val, 1);
            }
            fill(begin(visit), end(visit), false);
            r2.insert(p2);
            times = 4;
            while (times--) {
                for (int val : r2)
                    bfs(val, 2);
            }
            bool flag = false;
            for (int val : r1) {
                if (r2.find(val) != r2.end()) {
                    printf("No\n");
                    flag = true;
                    break;
                }
            }
            if (!flag)
                printf("Yes\n");
        }
    }
    return 0;
}