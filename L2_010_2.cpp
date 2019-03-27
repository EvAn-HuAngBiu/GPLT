#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> friends;
int enemy[101][101];

int Find(int p)
{
    while (p != friends[p])
        p = friends[p];
    return p;
}

void Union(int p1, int p2) {
    int f1 = Find(p1), f2 = Find(p2);
    if (f1 != f2)
        friends[f1] = f2;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    friends.resize(n + 1);
    for (int i = 0; i <= n; i++)
        friends[i] = i;
    int p1, p2, r;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &p1, &p2, &r);
        if (r == 1)
            Union(p1, p2);
        else
            enemy[p1][p2] = enemy[p2][p1] = 1;
    }

    int f1, f2;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &p1, &p2);
        f1 = Find(p1);
        f2 = Find(p2);
        if (enemy[p1][p2] == 1) {
            if (f1 != f2)
                printf("No way\n");
            else
                printf("OK but...\n");
        }
        else {
            if (f1 == f2)
                printf("No problem\n");
            else
                printf("OK\n");
        }
    }
    return 0;
}