#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int count;
    scanf("%d", &count);
    vector<set<int>> v(count);
    for (int i = 0; i < count; i++) {
        int c;
        scanf("%d", &c);
        set<int> s;
        for (int j = 0; j < c; j++) {
            int temp;
            scanf("%d", &temp);
            s.insert(temp);
        }
        v[i] = s;
    }

    int qCount;
    scanf("%d", &qCount);
    for (int i = 0; i < qCount; i++) {
        int first, second;
        scanf("%d %d", &first, &second);
        set<int> sf = v[first - 1], ss = v[second - 1];
        int common = 0, total = ss.size();
        for (auto iter = sf.begin(); iter != sf.end(); iter++)
            if (ss.find(*iter) != ss.end())
                common++;
            else
                total++;
        printf("%.2f%%\n", (double)common / total * 100);
    }
    return 0;
}