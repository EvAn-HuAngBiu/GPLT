#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

struct Node {
    int addr;
    int val;
    int next;
};

Node del[100001];

int main()
{
    int begin, count;
    scanf("%d%d", &begin, &count);
    map<int, Node> m;
    set<int> s;
    for (int i = 0; i < count; i++) {
        Node n;
        scanf("%d %d %d", &n.addr, &n.val, &n.next);
        if (s.find(abs(n.val)) == s.end()) {
            s.insert(abs(n.val));
            m[n.addr] = n;
        } else
            del[n.addr] = n;
    }

    queue<Node> qVal;
    queue<Node> qDel;
    int current = begin;
    while (current != -1) {
        if (m.find(current) != m.end()) {
            // In valid map
            if (!qVal.empty()) {
                Node before = qVal.front();
                qVal.pop();
                printf("%05d %d %05d\n", before.addr, before.val, m[current].addr);
            }
            qVal.push(m[current]);
            current = m[current].next;
        } else {
            // In deleted array
            if (!qDel.empty())
                qDel.back().next = current;
            qDel.push(del[current]);
            current = del[current].next;
        }
    }
    Node last = qVal.front();
    printf("%05d %d -1\n", last.addr, last.val);

    if (!qDel.empty()) {
        while (qDel.size() != 1) {
            Node n = qDel.front();
            qDel.pop();
            printf("%05d %d %05d\n", n.addr, n.val, n.next);
        }
        Node lastDel = qDel.front();
        printf("%05d %d -1\n", lastDel.addr, lastDel.val);
    }
    return 0;
}
