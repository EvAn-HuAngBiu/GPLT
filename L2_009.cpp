#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Pocket {
    int id;
    double money = 0.0;
    int cnt = 0;
};

struct {
    bool operator()(Pocket a, Pocket b) const
    {
        if (a.money == b.money) {
            if (a.cnt == b.cnt) {
                return a.id < b.id;
            }
            return a.cnt > b.cnt;
        }
        return a.money > b.money;
    }
} cmp;

vector<Pocket> pockets(10001);

int main()
{
    int count, c, getter, getmoney;
    scanf("%d", &count);
    for (int i = 1; i <= count; i++) {
        scanf("%d", &c);
        int total = 0;
        for (int j = 0; j < c; j++) {
            scanf("%d %d", &getter, &getmoney);
            total += getmoney;
            pockets[getter].money += getmoney;
            pockets[getter].cnt++;
        }
        pockets[i].id = i;
        pockets[i].money -= total;
    }
    std::sort(pockets.begin() + 1, pockets.begin() + count + 1, cmp);
    for (int i = 1; i <= count; i++)
        printf("%d %.2f\n", pockets[i].id, pockets[i].money / 100);
    return 0;
}