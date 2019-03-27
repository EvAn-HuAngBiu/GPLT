#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int fathers[10001] = {0};
bool visit[10001] = {false};

struct Home {
    int id, father, mother, kid, house, area;
    int kids[6] = {0};
} data[10001];

struct Result {
    int id, cnt;
    double avgCount, avgArea;
    bool isRoot;
} result[10001];

struct {
    bool operator()(Result a, Result b) const {
        if (a.avgArea == b.avgArea)
            return a.id < b.id;
        return a.avgArea > b.avgArea;
    }
} cmp;

int Find(int p) {
    while (fathers[p] != p)
        p = fathers[p];
    return p;
}

void Union(int p1, int p2) {
    int f1 = Find(p1), f2 = Find(p2);
    if (f1 > f2)
        fathers[f1] = f2;
    else if (f1 < f2)
        fathers[f2] = f1;
}

int main() {
    for (int i = 0; i < 10001; i++)
        fathers[i] = i;
    int count, roots = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        Home h;
        scanf("%d %d %d %d", &h.id, &h.father, &h.mother, &h.kid);
        if (h.father != -1) {
            visit[h.father] = true;
            Union(h.father, h.id);
        }
        if (h.mother != -1) {
            visit[h.mother] = true;
            Union(h.mother, h.id);
        }
        for (int j = 0; j < h.kid; j++) {
            scanf("%d", &h.kids[j]);
            visit[h.kids[j]] = true;
            Union(h.kids[j], h.id);
        }
        scanf("%d %d", &h.house, &h.area);
        data[i] = h;
        visit[h.id] = true;
    }
    for (int i = 0; i < count; i++) {
        int id = Find(data[i].id);
        result[id].id = id;
        result[id].avgCount += data[i].house;
        result[id].avgArea += data[i].area;
        result[id].isRoot = true;
    }
    for (int i = 0; i < 10001; i++) {
        if (visit[i])
            result[Find(i)].cnt++;
        if (result[i].isRoot)
            roots++;
    }
    for (int i = 0 ; i < 10001; i++) {
        if (result[i].isRoot) {
            result[i].avgCount = result[i].avgCount * 1.0 / result[i].cnt;
            result[i].avgArea = result[i].avgArea * 1.0 / result[i].cnt;
        }
    }
    std::sort(result, result + 10001, cmp);
    printf("%d\n", roots);
    for (int i = 0; i < roots; i++) {
        printf("%04d %d %.3f %.3f\n", result[i].id, result[i].cnt, result[i].avgCount, result[i].avgArea);
    }
    return 0;
}