#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
    int people, send;
    scanf("%d", &people);
    set<const char*> all, possible;
    map<string, int> good;
    char* temp;
    for (int i = 0; i < people; i++) {
        scanf("%s", &temp);
        all.insert(temp);
    }
    scanf("%d", &send);
    char* name;
    int times, total = 0, cnt = 0;
    for (int i = 0; i < send; i++) {
        scanf("%s %d", &name, &times);
        good[name] = times;
        if (all.find(name) == all.end())
            possible.insert(name);
        total += times;
        cnt++;
    }
    double avg = total * 1.0 / cnt;
    for (auto iter = possible.begin(); iter != possible.end(); iter++) {
        if (good[*iter] < avg)
            possible.erase(iter);
    }
    for (auto iter = possible.begin(); iter != possible.end(); iter++)
        printf("%s\n", *iter);
    return 0;
}