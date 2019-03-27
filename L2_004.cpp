#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *lchild;
    Node *rchild;
    Node *parent;
};
Node *root = nullptr;
vector<int> pre;
vector<int> result;
vector<int> r;

void create(Node *cur) {
    Node *temp = root;
    if (temp == nullptr) {
        root = cur;
        return;
    }
    while (true) {
        if (temp->val > cur->val) {
            if (temp->lchild != nullptr)
                temp = temp->lchild;
            else {
                temp->lchild = cur;
                cur->parent = temp;
                return;
            }
        } else {
            if (temp->rchild != nullptr)
                temp = temp->rchild;
            else {
                temp->rchild = cur;
                cur->parent = temp;
                return;
            }
        }
    }
}

void preOrder(Node *cur) {
    if (cur != nullptr) {
        result.push_back(cur->val);
        preOrder(cur->lchild);
        preOrder(cur->rchild);
    }
}

void preOrderMirror(Node* cur) {
    if (cur != nullptr) {
        result.push_back(cur->val);
        preOrderMirror(cur->rchild);
        preOrderMirror(cur->lchild);
    }
}

void postOrder(Node *cur) {
    if (cur != nullptr) {
        postOrder(cur->lchild);
        postOrder(cur->rchild);
        r.push_back(cur->val);
    }
}

void postOrderMirror(Node *cur) {
    if (cur != nullptr) {
        postOrderMirror(cur->rchild);
        postOrderMirror(cur->lchild);
        r.push_back(cur->val);
    }
}

int main() {
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        int val;
        scanf("%d", &val);
        pre.push_back(val);
        create(new Node{val, nullptr, nullptr, nullptr});
    }
    preOrder(root);
    bool mirror = false;
    for (int i = 0; i < count; i++)
        if (pre[i] != result[i]) {
            mirror = true;
            break;
        }

    bool error = false;
    if (mirror) {
        result.clear();
        preOrderMirror(root);
        for (int i = 0; i < count; i++) {
            if (pre[i] != result[i]) {
                error = true;
                break;
            }
        }
    }

    if (error) {
        printf("NO\n");
    } else {
        printf("YES\n");
        if (mirror) postOrderMirror(root);
        else postOrder(root);
        for (int i = 0; i < count - 1; i++)
            printf("%d ", r[i]);
        printf("%d\n", r[count - 1]);
    }
    return 0;
}