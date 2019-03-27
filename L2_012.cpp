#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> heap(1e3, 0);
int cnt = 0;
const char *r1 = "root", *r2 = "siblings", *r3 = "parent", *r4 = "child";

void swim(int n)
{
    while (n > 1 && heap[n] < heap[n / 2]) {
        int temp = heap[n / 2];
        heap[n / 2] = heap[n];
        heap[n] = temp;
        n /= 2;
    }
}

void insert(int val) {
    heap[++cnt] = val;
    swim(cnt);
}

int find(int val) {
    for (int i = 1; i <= cnt; i++)
        if (heap[i] == val)
            return i;
    return -1;
}

void judge(string s) {
    stringstream ss(s);
    int val;
    ss >> val;
    int index1 = find(val);
    string temp;
    int interval, val2, index2;
    if (s.find(r1) != string::npos) {
        if (index1 == 1) cout << "T" << endl;
        else cout << "F" << endl;
    } else if (s.find(r2) != string::npos) {
        ss >> temp;
        ss >> val2;
        index2 = find(val2);
        if (index1 / 2 == index2 / 2) cout << "T" << endl;
        else cout << "F" << endl;
    } else if (s.find(r3) != string::npos) {
        interval = 4;
        while (interval--) ss >> temp;
        ss >> val2;
        index2 = find(val2);
        if (index2 / 2 == index1) cout << "T" << endl;
        else cout << "F" << endl;
    } else if(s.find(r4) != string::npos) {
        interval = 4;
        while (interval--) ss >> temp;
        ss >> val2;
        index2 = find(val2);
        if (index1 / 2 == index2) cout << "T" << endl;
        else cout << "F" << endl;
    } else {
        cout << "F" << endl;
    }
}

int main()
{
    int count, query;
    cin >> count >> query;
    for (int i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        insert(temp);
    }
    cin.get();
    for (int i = 0; i < query; i++) {
        string s;
        getline(cin, s);
        judge(s);
    }
    return 0;
}