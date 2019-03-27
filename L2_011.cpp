#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* lchild;
    Node* rchild;
};
vector<int> pre, in, result;

Node* construct(int preStart, int inStart, int len)
{
    if (len == 0) return nullptr;
    int root = pre[preStart];
    if (len == 1) {
        Node* n = new Node {root, nullptr, nullptr};
        return n;
    }

    int i = 0;
    while (root != in[inStart + i]) i++;
    Node* n = new Node {root, nullptr, nullptr};
    n->lchild = construct(preStart + 1, inStart, i);
    n->rchild = construct(preStart + i + 1, inStart + i + 1, len - i - 1);
    return n;
}

void level(Node* cur) {
    queue<Node*> q;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        result.push_back(cur->val);
        if (cur->rchild) q.push(cur->rchild);
        if (cur->lchild) q.push(cur->lchild);
    }
}

int main()
{
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int temp;
        scanf("%d", &temp);
        in.push_back(temp);
    }
    for (int i = 0; i < cnt; i++) {
        int temp;
        scanf("%d", &temp);
        pre.push_back(temp);
    }
    Node* root = construct(0, 0, cnt);
    level(root);

    for (int i = 0; i < cnt - 1; i++)
        printf("%d ", result[i]);
    printf("%d\n", result[cnt - 1]);
    return 0;
}