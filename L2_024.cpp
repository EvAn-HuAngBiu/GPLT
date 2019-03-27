#include <cstdio>
#include <set>
using namespace std;

int friends[10001] = {0};
set<int> people;

int Find(int p) {
    while (friends[p] != p)
        p = friends[p];
    return p;
}

void Union(int p1, int p2) {
    people.insert(p1);
    people.insert(p2);
    int f1 = Find(p1), f2 = Find(p2);
    if (f1 > f2)
        friends[f1] = f2;
    else if (f1 < f2)
        friends[f2] = f1;
}

int main()
{
    for (int i = 0; i < 10001; i++)
        friends[i] = i;
    int groups, cnt, p1, p2;
    scanf("%d", &groups);
    for (int i = 0; i < groups; i++) {
        scanf("%d %d", &cnt, &p1);
        if (cnt == 1)
            people.insert(p1);
        else {
            for (int j = 1; j < cnt; j++) {
                scanf("%d", &p2);
                Union(p1, p2);
            }
        }
    }
    set<int> group;
    for (auto i : people)
        group.insert(Find(i));
    printf("%lu %lu\n", people.size(), group.size());
    int query, q1, q2;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        scanf("%d %d", &q1, &q2);
        if (Find(q1) == Find(q2))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}