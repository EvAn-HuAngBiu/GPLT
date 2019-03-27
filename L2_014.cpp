#include <cstdio>
#include <set>
using namespace std;

int main() {
    int cnt, c;
    scanf("%d", &cnt);
    set<int> s;
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &c);
        auto iter = s.upper_bound(c);
        if (iter != s.end()) {
            s.erase(iter);
        }
        s.insert(c);
    }
    printf("%lu", s.size());
    return 0;
}