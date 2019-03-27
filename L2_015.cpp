#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, k, m, temp, total;
    for (int t = 0; t < n; t++) {
    scanf("%d %d %d", &n, &k, &m);
    vector<set<int>> v(n);
    set<double> result;
    for (int i = 0; i < n; i++) {
        set<int> s;
        v[i] = s;
    }
    for (int i = 0; i < n; i++) {
        set<int> current = v[i];
        total = 0;
        for (int j = 0; j < k; j++) {
            scanf("%d", &temp);
            current.insert(temp);
        }
        for (auto iter = current.begin() + 1;
            iter != current.end() - 1; iter++) {
            total += *iter;
        }
        result.insert(total * 1.0 / (k - 2));
    }
    for (auto i : result) {
        printf("%.3f\n", i);
    }
}
    return 0;
}