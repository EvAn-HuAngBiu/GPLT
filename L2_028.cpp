#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

map<int, map<int, double>> rel;
int n, m;

struct Cmp {
    bool operator()(int a, int b) {
        return abs(a) > abs(b);
    }
};

int main() {
    int total, q1, q2;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &total);
        vector<int> v(total);
        for (int j = 0; j < total; j++)
            scanf("%d", &v[j]);

        for (int j = 0; j < total; j++) {
            for (int k = j + 1; k < total; k++) {
                if (rel.find(v[j]) == rel.end()) {
                    map<int, double> m;
                    m[v[k]] = 1.0 / total;
                    rel[v[j]] = m;
                } else
                    rel[v[j]][v[k]] += 1.0 / total;

                if (rel.find(v[k]) == rel.end()) {
                    map<int, double> m;
                    m[v[j]] = 1.0 / total;
                    rel[v[k]] = m;
                } else
                    rel[v[k]][v[j]] += 1.0 / total;
            }
        }
    }
    scanf("%d %d", &q1, &q2);
    double max1 = -1, max2 = -1;
    set<int, Cmp> s1, s2;
    for (auto subm : rel[q1]) {
        if (subm.second > max1) {
            s1.clear();
            s1.insert(subm.first);
        } else if (subm.second == max1)
            s1.insert(subm.first);
    }
    for (auto subm : rel[q2]) {
        if (subm.second > max2) {
            s2.clear();
            s2.insert(subm.first);
        } else if (subm.second == max2)
            s2.insert(subm.first);
    }

    if (s1.find(q2) != s1.end() && s2.find(q1) != s2.end()) {
        printf("%d %d\n", q1, q2);
    } else {
        for (auto val : s1)
            printf("%d %d\n", q1, val);
        for (auto val : s2)
            printf("%d %d\n", q2, val);
    }
    return 0;
}