#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* lchild;
    Node* rchild;
};

vector<int> post, in, result;

Node* restoreTree(int postEnd, int inStart, int len) {
    if (len == 0)
        return nullptr;
    int root = post[postEnd];
    if (len == 1)
        return new Node{root, nullptr, nullptr};
    int i = 0;
    while (root != in[inStart + i]) i++;
    Node* n = new Node{root, nullptr, nullptr};
    n->lchild = restoreTree(postEnd - (len - i - 1) - 1, inStart, i);
    n->rchild = restoreTree(postEnd - 1, inStart + i + 1, len - i - 1);
    return n;
}

void level(Node* cur) {
    queue<Node*> q;
    q.push(cur);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        result.push_back(cur->val);
        if (cur->lchild) q.push(cur->lchild);
        if (cur->rchild) q.push(cur->rchild);
    }
}

int main()
{
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        in.push_back(temp);
    }
    Node* root = restoreTree(n - 1, 0, n);
    level(root);
    for (int i = 0; i < n - 1; i++)
        printf("%d ", result[i]);
    printf("%d\n", result[n - 1]);
    return 0;
}