#include <cstdio>
#include <map>
#include <vector>
using namespace std;

struct Node {
    int addr;
    int val;
    int naddr;
};

map<int, Node> m;
vector<Node> seq;
vector<Node> newSeq;

int main()
{
    int root, cnt;
    scanf("%d %d", &root, &cnt);
    for (int i = 0; i < cnt; i++) {
        Node n;
        scanf("%d %d %d", &n.addr, &n.val, &n.naddr);
        m[n.addr] = n;
    }
    int cur = root;
    while (cur != -1) {
        seq.push_back(m[cur]);
        cur = m[cur].naddr;
    }
    int dif = 0, last = seq.size() - 1;
    while (newSeq.size() < seq.size()) {
        newSeq.push_back(seq[last - dif]);
        newSeq.push_back(seq[dif]);
        dif++;
    }
    for (int i = 0; i < last; i++)
        printf("%05d %d %05d\n", newSeq[i].addr, newSeq[i].val, newSeq[i + 1].addr);
    printf("%05d %d -1\n", newSeq[last].addr, newSeq[last].val);
    return 0;
}