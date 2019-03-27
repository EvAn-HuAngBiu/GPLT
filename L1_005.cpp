#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
  int count;
  cin >> count;
  map<int, string> stus;
  for (int i = 0; i < count; i++)
  {
    string id;
    int test, exam;
    cin >> id >> test >> exam;
    stringstream ss;
    ss << id << " " << exam;
    stus[test] = ss.str();
  }
  int want;
  cin >> want;
  for (int i = 0; i < want; i++)
  {
    int current;
    cin >> current;
    cout << stus[current] << endl;
  }

  return 0;
}
