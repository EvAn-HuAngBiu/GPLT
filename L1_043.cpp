#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
  int days;
  cin >> days;
  map<int, int> m;
  int dayCount = 0, totalCount = 0;
  int duration = 0;
  while (dayCount < days)
  {
    // Get input
    int book;
    char type;
    string time;
    cin >> book >> type >> time;
    // Get minutes
    int minutes = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
    // Judge
    if (0 == book)
    {
      dayCount++;
      if (totalCount != 0)
      {
        int total = 1.0 * duration / totalCount + 0.5;
        cout << totalCount << " " << total << endl;
      }
      else
        cout << "0 0" << endl;
      // Reset
      duration = 0;
      totalCount = 0;
      m.clear();
    }
    else
    {
      if ('S' == type)
        m[book] = minutes;
      else
      {
        auto before = m.find(book);
        if (before != m.end())
        {
          duration += minutes - before->second;
          m.erase(before);
          totalCount++;
        }
      }
    }
  }
  return 0;
}
