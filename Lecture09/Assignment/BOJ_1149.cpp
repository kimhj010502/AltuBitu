#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0, G = 1, B = 2;

int getMinCost(int n, vector<vector<int>>& cost) {
	vector<vector<int>> dp(n, vector<int>(3));
	dp[0] = cost[0];
	for (int i = 1; i < n; i++) {
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + cost[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + cost[i][B];
	}

	return min({ dp[n - 1][R], dp[n - 1][G], dp[n - 1][B] });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<int>> cost(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	//연산 & 출력
	cout << getMinCost(n, cost);

	return 0;
}