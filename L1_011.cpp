#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string original, replace;
  getline(cin, original);
  getline(cin, replace);
  vector<char> s;
  for (int i = 0; i < original.length(); i++)
  {
    char current = original[i];
    if (replace.find(current, 0) == string::npos)
      s.push_back(current);
  }

  for (int i = 0; i < s.size(); i++)
    cout << s[i];
  cout << endl;
  return 0;
}
