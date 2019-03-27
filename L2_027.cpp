#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Student {
    string email;
    int score;
};

struct StudentCmp {
    bool operator()(Student s1, Student s2) const {
        if (s1.score == s2.score)
            return s1.email < s2.email;
        return s1.score > s2.score;
    }
};

set<Student, StudentCmp> stus;
int total = 0;

int main()
{
    int n, g, k;
    cin >> n >> g >> k;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s.email >> s.score;
        stus.insert(s);
        if (s.score >= 60) total += 20;
        if (s.score >= g) total += 30;
    }
    cout << total << endl;
    int cnt = 0, pre = -1, currentCount = 0;
    auto iter = stus.begin();
    while (cnt <= k) {
        if (pre == iter->score) {
            currentCount++;
            cout << cnt << " ";
        } else {
            cnt += currentCount + 1;
            if (cnt > k) break;
            cout << cnt << " ";
            pre = iter->score;
            currentCount = 0;
        }
        cout << iter->email << " " << iter->score << endl;
        iter++;
    }
    return 0;
}