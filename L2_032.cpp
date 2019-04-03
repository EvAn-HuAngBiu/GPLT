#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, m, k, cur;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        stack<int> desk;
        int last = 0;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[i];
        }
        int cur = 0;
        while (last < n) {
            if (v[cur] == last + 1) {
                last++;
                cur++;
            } else if (!desk.empty() && desk.top() == last + 1) {
                last++;
                desk.pop();
            } else if (desk.size() >= m) break;
            else if (cur < m) desk.push(v[cur++]);
            else break;
        }

        if (desk.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
        // for (int j = 0; j < n; j++) {
        //     cin >> cur;
        //     if (flag) continue;
        //     if (last == 0 && cur == 1) last = 1;
        //     else if (cur - last == 1) last = cur;
        //     else if (!desk.empty() && desk.top() - last == 1) {
        //         last = desk.top();
        //         desk.pop();
        //         desk.push(cur);
        //     } else if (desk.size() < m) desk.push(cur);
        //     else flag = true;
        // }
        // if (flag) cout << "NO" << endl;
        // else {
        //     while (!desk.empty()) {
        //         if (desk.top() - last == 1) {
        //             last = desk.top();
        //             desk.pop();
        //         } else break;
        //     }

        //     if (last == n) cout << "YES" << endl;
        //     else cout << "NO" << endl;
        // }
    }
    return 0;
}