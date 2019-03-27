#include <iostream>
using namespace std;

int main()
{
  int count;
  cin >> count;
  int record[1001] = {0};
  for (int i = 0; i < count; i++)
  {
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
      int input;
      cin >> input;
      record[input]++;
    }
  }

  int index = 0, value = 0;
  for (int i = 1; i < 1001; i++)
  {
    if (record[i] >= value)
    {
      value = record[i];
      index = i;
    }
  }
  cout << index << " " << value << endl;
  return 0;
}
