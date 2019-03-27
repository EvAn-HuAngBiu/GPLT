#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int M;
int N;
vector<int> coin;
int dp[101];
int path[10001][101];
 
int cmp(int a,int b) {
	return a > b;
}
 
int main()
{
	//freopen("data.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
	// 将硬币从小到大排序
	sort(coin.begin(), coin.end(),cmp);
 
	// 动态规划，用path将路径记录下来
	for (int i = 0; i < N; i++) {
		for (int j = M; j >= coin[i]; j--) {
			if (dp[j] <= dp[j - coin[i]] + coin[i]) {
				path[i][j] = 1;
				dp[j] = dp[j - coin[i]] + coin[i];
			}
		}
	}
	// 从[N-1][M]开始倒着输出
	if (dp[M] != M) {
		cout << "No Solution" << endl;
	}
	else {
		int j = M;
		int i = N - 1;
		while (j > 0) {
			if (path[i][j] == 1) {
				if (j != M) {
					cout << " ";
				}
				cout << coin[i];
				j -= coin[i];
			}
			i--;
		}
	}
	return 0;
}