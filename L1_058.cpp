#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

vector<char> temp;

void deal() {
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (isdigit(temp[i]) && temp[i] == '6') cnt++;
        else {
            flag = true;
            break;
        }
    }
    if (flag || cnt < 4) {
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i];
    } else if (cnt >= 9)
        cout << 27;
    else
        cout << 9;
    temp.clear();
}

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ')
            temp.push_back(s[i]);
        else {
            deal();
            cout << " ";
        }
    }
    if (!temp.empty()) deal();
    return 0;
}