#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct People {
    string name;
    set<int> good;
    int cnt;
};

struct {
    bool operator()(People p1, People p2) const {
        if (p1.good.size() != p2.good.size())
            return p1.good.size() > p2.good.size();
        return 1.0 * p1.cnt / p1.good.size() < 1.0 * p2.cnt / p2.good.size();
    }
} cmp;

int main()
{
    int people, tempInt, cnt;
    cin >> people;
    cin.get();
    string temp;
    vector<People> v(people);
    for (int i = 0; i < people; i++) {
        People p;
        cin >> p.name >> cnt;
        p.cnt = cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> tempInt;
            p.good.insert(tempInt);
        }
        v[i] = p;
    }
    sort(v.begin(), v.end(), cmp);
    int m = min(people, 3);
    for (int i = 0; i < m; i++) {
        if (i != 0)
            cout << " ";
        cout << v[i].name;
    }
    for (int i = 0; i < 3 - m; i++)
        cout << " " << "-";
    return 0;
}