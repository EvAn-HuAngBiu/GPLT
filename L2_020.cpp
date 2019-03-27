#include <cstdio>
#include <map>
#include <vector>
using namespace std;

vector<vector<int>> graph;
int people;
double original, discount;
double result = 0.0;
map<int, int> s;

void dfs(int index, double power) {
    if (s.find(index) != s.end()) {
        result += power * s[index];
        return;
    }
    for (int i : graph[index]) {
        dfs(i, power * (1 - discount / 100));
    }
}

int main()
{
    scanf("%d %lf %lf", &people, &original, &discount);
    graph.resize(people);
    int stuCount, stu;
    for (int i = 0; i < people; i++) {
        scanf("%d", &stuCount);
        for (int j = 0; j < stuCount; j++) {
            scanf("%d", &stu);
            graph[i].push_back(stu);
        }
        if (stuCount == 0) {
            // Record s student
            scanf("%d", &s[i]);
        }
    }
    dfs(0, original);
    printf("%d\n", (int)result);
    return 0;
}