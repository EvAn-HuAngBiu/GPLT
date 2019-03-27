#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int val;
    int inIndex;
    int postIndex;
};

int main() {
    int count;
    scanf("%d", &count);
    vector<int> in(count), post(count);
    for (int i = 0; i < count; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < count; i++)
        scanf("%d", &in[i]);

    queue<Node> q;
    vector<int> result(count);
    int index = 0;
    int root = post[count - 1];
    int rIndex = std::distance(std::begin(in), std::find(in.begin(), in.end(), root));
    Node rNode = {root, rIndex, count - 1};
    q.push(rNode);
    Node l, r;
    while (!q.empty() && index != count) {
        l = r = {INT_MAX, -1, -1};
        Node current = q.front();
        q.pop();
        result[index++] = current.val;
        for (int i = current.postIndex - 1; i >= 0; i--) {
            auto iter = std::find(in.begin(), in.end(), post[i]);
            auto dis = std::distance(std::begin(in), iter);
            if (r.val == INT_MAX && dis > current.inIndex) {
                r.val = in[dis];
                r.inIndex = dis;
                r.postIndex = i;
            } else if (l.val == INT_MAX && dis < current.inIndex) {
                l.val = in[dis];
                l.inIndex = dis;
                l.postIndex = i;
            }
        }

        if (l.val != INT_MAX) q.push(l);
        if (r.val != INT_MAX) q.push(r);
    }

    for (int i = 0; i < count - 1; i++)
        printf("%d ", result[i]);
    printf("%d\n", result[count - 1]);
    return 0;
}