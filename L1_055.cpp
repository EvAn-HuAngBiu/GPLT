#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  string sign;
  int count;
  cin >> sign >> count;
  getchar();
  vector<string> s(count);
  for (int i = 0; i < count; i++)
  {
    getline(cin, s[i]);
  }
  bool isSame = true;
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count; j++)
    {
      if (s[i][j] != s[count - 1 - i][count - 1 - j])
      {
        isSame = false;
        break;
      }
    }
  }
  // Print
  if (isSame)
  {
    cout << "bu yong dao le" << endl;
  }
  for (int i = 0; i < count; i++)
  {
    for (int j = 0; j < count; j++)
    {
      if (s[count - 1 -i][count - 1 - j] == '@')
      {
        cout << sign;
      } else
      {
        cout << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
