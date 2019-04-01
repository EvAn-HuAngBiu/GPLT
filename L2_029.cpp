#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

vector<set<int> > rel(10010);
vector<int> possible;

int judge(int val) {
    int temp = val, cnt = 0;
    set<int> s;
    while (temp != 1) {
        int total = 0, var = temp, bit;
        while (var != 0) {
            bit = var % 10;
            total += bit * bit;
            var /= 10;
        }

        if (s.find(total) != s.end()) return -1;
        else {
            s.insert(total);
            temp = total;
            cnt++;
        }
    }
    rel[val] = s;
    return cnt;
}

bool isPrime(int val) {
    for (int i = 2; i <= sqrt(val); i++)
        if (val % i == 0) return false;
    return true;
}

bool consist(int val) {
    for (int i = 0; i < rel.size(); i++) {
        const set<int>& s = rel[i];
        if (possible[i] == val) continue;
        else if (s.find(val) != s.end()) return false;
    }
    return true;
}

int main() {
    int beg, end;
    cin >> beg >> end;
    int cnt = 0;
    vector<int> record;
    for (int i = beg; i <= end; i++) {
        int j = judge(i);
        if (j != -1) {
            possible.push_back(i);
            record.push_back(j);
            cnt++;
        }
    }
    if (cnt == 0) cout << "SAD" << endl;
    else {
        for (int i = 0; i < possible.size(); i++) {
            if (consist(possible[i])) {
                cout << possible[i] << " ";
                if (isPrime(possible[i])) cout << 2 * record[i] << endl;
                else cout << record[i] << endl;
            }
        }
    }
    return 0;
}