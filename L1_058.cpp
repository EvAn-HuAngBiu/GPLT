#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int cnt = 0;
    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == '6') cnt++;
        else {
            if (cnt >= 9) cout << 27;
            else if (cnt >= 4) cout << 9;
            else while (cnt--) cout << 6;
            cnt = 0;
            if (i < str.size()) cout << str[i];
        }
    }
    return 0;
}