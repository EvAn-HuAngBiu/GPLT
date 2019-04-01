#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    vector<string> v1, v2;
    for (int i = 0; i < cnt; i++) {
        v1.clear();
        v2.clear();
        string temp;
        cin >> temp;
        while (temp.find(",") == string::npos) {
            v1.push_back(temp);
        }
        v1.push_back(temp);
        bool v1hasOng = false;
        if (temp.substr(temp.size() - 4) == "ong,") v1hasOng = true;

        cin >> temp;
        while (temp.find(".") == string::npos) {
            v2.push_back(temp);
        }
        v2.push_back(temp);
        
        if (v1hasOng && temp.substr(temp.size() - 4) == "ong.") {
            for (int i = 0; i < v1.size(); i++) {
                if (i != 0) cout << " ";
                cout << v1[i];
            }

            for (int i = 0; i < v2.size() - 3; i++) {
                if (i != 0) cout << " ";
                cout << v2[i];
            }
            cout << " qiao ben zhong." << endl;
        } else {
            cout << "Skipped" << endl;
        }
    }
    return 0;
}