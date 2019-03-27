#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cnt;
    scanf("%d", &cnt);
    vector<int> v(cnt);
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    std::sort(v.begin(), v.end());
    int size = v.size();
    int half = 0;
    for (int i = 0; i < size / 2; i++)
        half += v[i];
    int t1, t2;
    if (size % 2 == 0)
        t1 = t2 = size / 2;
    else {
        t1 = size / 2;
        t2 = size - t1;
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d",
        t2, t1, sum - half - half);
    return 0;
}