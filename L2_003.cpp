#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cnt, need, sold = 0;
    double total = 0.0;
    scanf("%d %d", &cnt, &need);
    vector<double> weight(cnt), prices(cnt), per(cnt);
    for (int i = 0; i < cnt; i++)
        scanf("%lf", &weight[i]);
    for (int i = 0; i < cnt; i++) {
        scanf("%lf", &prices[i]);
        per[i] = prices[i] / weight[i];
    }
    while (true) {
        auto minIter = std::max_element(per.begin(), per.end());
        long dis = std::distance(per.begin(), minIter);
        if (weight[dis] <= need - sold) {
            total += prices[dis];
            sold += weight[dis];
        } else {
            int l = need - sold;
            total += l * *minIter;
            break;
        }
        per[dis] = -1;
    }
    printf("%.2f\n", total);
    return 0;
}