#include <iostream>
#include <vector>
using namespace std;

/*
 * 本提解法参考：https://www.liuchuo.net/archives/5082
 * 即让椅子找队员，按照队伍顺序遍历，如果当前位置的前一位置不是本校队员那么就把位置给他，
 * 因为是按队伍顺序遍历的所以当队伍数>=2时，会按照顺序把每个学校的队员分配到不连续的位置上，
 * 而当前一位置是本校队员的情况下同时本次分配又是本校队员（说明只有一个学校在等待分配了），
 * 此时把这名队员安排到当前位置的下一位置来保证不相邻。
*/
int main()
{
  // 学校数
  int n;
  cin >> n;
  // 椅子数
  int seats[10001] = {0};
  // 各学校队伍数
  int schools[101] = {0};
  // 各学校座位安排
  vector<vector<int>> teams(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> schools[i];
  // 结束标志
  bool flag = false;
  // 下一个空座位
  int cnt = 1;
  while (!flag)
  {
    // 开始时置结束标志，若没有队伍未分配则结束
    flag = true;
    for (int i = 1; i < teams.size(); i++)
    {
      if(teams[i].size() < schools[i] * 10)
      {
        if (seats[cnt - 1] != i)
        {
          seats[cnt] = i;
          teams[i].push_back(cnt++);
        }
        else
        {
          seats[cnt + 1] = i;
          teams[i].push_back(cnt + 1);
          cnt += 2;
        }
        flag = false;
      }
    }
  }

  for (int i = 1; i < teams.size(); i++)
  {
    cout << "#" << i << endl;
    for (int j = 0; j < teams[i].size(); j++)
    {
      if (j != 0 && j % 10 == 0) cout << endl;
      if (j != 0 && j % 10 != 0) cout << " ";
      cout << teams[i][j];
    }
    cout << endl;
  }
  return 0;
}
