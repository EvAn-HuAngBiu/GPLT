#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  // Input
  int teamCount;
  cin >> teamCount;
  vector<int> team(teamCount);
  for (int i = 0; i < teamCount; i++)
    cin >> team[i];

  vector<bool> finished(teamCount);
  vector<vector<int>> result(teamCount);
  for (int i = 0; i < teamCount; i++)
  {
    vector<int> v(team[i] * 10);
    result[i] = v;
  }
  int lastIndex = 0;
  int finishCount = 1;
  int f = 0;
  int total = 0;

  while (f < teamCount)
  {
    auto minValueIter = min_element(std::begin(team), std::end(team));
    int minIndex = distance(std::begin(team), minValueIter);
    int amount = *minValueIter * 10;
    int dif = amount - total;
    int interval = (team.size() >= 2 ? team.size() : 2);
    team.erase(minValueIter);

    for (int i = 0; i < teamCount; i++)
    {
      if (finished[i])
        continue;
      for (int j = 0; j < dif; j++)
      {
        result[i][j + lastIndex] = finishCount + (interval * j);
      }
      finishCount++;
    }

    // 完成工作
    finished[minIndex] = true;
    lastIndex += dif;
    total = amount;
    finishCount += dif * interval - interval;
    f++;
  }

  for (int i = 0; i < teamCount; i++)
  {
    cout << "#" << i + 1 << endl;
    for (int j = 0; j < result[i].size(); j++)
    {
      if (j != 0 && j % 10 == 0) {
        cout << endl;
      }
      if (j != 0 && j % 10 != 0) {
        cout << " ";
      }
      cout << result[i][j];
    }
    cout << endl;
  }
  return 0;
}
