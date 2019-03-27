#include <iostream>
#include <map>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
  int count;
  cin >> count;
  map<string, int> m;
  for (int i = 0; i < count; i++) {
    string name;
    int num;
    cin >> name >> num;
    m[name] = num;
  }

  // Get average
  long sum = 0;
  for (auto iter = m.begin(); iter != m.end(); iter++)
  {
    sum += iter->second;
  }
  sum = sum / count / 2;

  string name;
  int dif = INT_MAX;
  for (auto iter = m.begin(); iter != m.end(); iter++)
  {
    if (abs(iter->second - sum) < dif)
    {
      dif = abs(iter->second - sum);
      name = iter->first;
    }
  }
  cout << sum << " " << name << endl;
  return 0;
}
