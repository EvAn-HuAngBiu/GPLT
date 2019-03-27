#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> v1, v2, r;

int main()
{
    unsigned n1, n2;
    int e, maxa = -1, maxb = -1;
    double c;
    scanf("%d", &n1);
    v1.resize(n1 + 1);
    for (int i = 0; i < n1; i++) {
        scanf("%d %lf", &e, &c);
        v1[e] = c;
        maxa = (e > maxa ? e : maxa);
    }
    scanf("%d", &n2);
    v2.resize(n2 + 1);
    for (int i = 0; i < n2; i++) {
        scanf("%d %lf", &e, &c);
        v2[e] = c;
        maxb = (e > maxb ? e : maxb);
    }
    r.resize(max(n1, n2) + 1);

    int t1 = maxa, t2 = maxb;
    while (t1 >= t2) {
        double fac = v1[t1] / v2[t2];
        r[t1 - t2] = fac;
        for (int i = t1, j = t2; j >= 0; i--, j--)
            v1[i] -= v2[j] * fac;
        while (abs(v1[t1]) < 1e-6)
            t1--;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = maxa - maxb; i >= 0; i--)
        if (abs(r[i]) + 0.05 >= 0.1) cnt1++;
    printf("%d", cnt1);
    if (cnt1 == 0)
        printf(" 0 0.0");
    else {
        for (int i = maxa - maxb; i >= 0; i--)
            if (abs(r[i]) + 0.05 >= 0.1)
                printf(" %d %.1lf", i, r[i]);
    }

    printf("\n");
    for (int i = t1; i >= 0; i--)
        if (abs(v1[i]) + 0.05 >= 0.1) cnt2++;
    printf("%d", cnt2);
    if (cnt2 == 0)
        printf(" 0 0.0");
    else {
        for (int i = t1; i >= 0; i--)
            if (abs(v1[i]) + 0.05 >= 0.1)
                printf(" %d %.1lf", i, v1[i]);
    }
    return 0;
}
