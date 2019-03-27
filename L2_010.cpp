#include <cstdio>
using namespace std;

int rel[101][101] = {0};
int total;

void query(int p1, int p2) {
    int r = rel[p1][p2];
    if (r == 1)
        printf("No problem\n");
    else if (r == 0) {
        for (int i = 1; i <= total; i++) {
            if (rel[p1][i] == 1 && rel[p2][i] == 1) {
                printf("No problem\n");
                return;
            }
        }
        printf("OK\n");
    }
    else {
        for (int i = 1; i <= total; i++) {
            if (rel[p1][i] == 1 && rel[p2][i] == 1) {
                printf("OK but...\n");
                return;
            }
        }
        printf("No way\n");
    }
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    total = n;
    int p1, p2, r;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &p1, &p2, &r);
        if (rel[p1][p2] == 0) {
            rel[p1][p2] = r;
            rel[p2][p1] = r;
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &p1, &p2);
        query(p1, p2);
    }
    return 0;
}