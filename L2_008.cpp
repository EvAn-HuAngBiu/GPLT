#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dp(vector<vector<bool>> v, string s)
{
    int len = s.length();
    int maxLength = 0;
    for (int j = 0; j < len; j++) {
        for (int i = j; i >= 0; i--) {
            if (s[i] == s[j] && (j - i < 2 || v[i + 1][j - 1])) {
                v[i][j] = true;
                maxLength = (maxLength > j - i + 1 ? maxLength : j - i + 1);
            }
        }
    }
    return maxLength;
}

int main()
{
    string s;
    getline(cin, s);
    vector<vector<bool>> m(s.length());
    for (int i = 0; i < s.length(); i++)
        m[i].resize(s.length());
    cout << dp(m, s) << endl;
    return 0;
}