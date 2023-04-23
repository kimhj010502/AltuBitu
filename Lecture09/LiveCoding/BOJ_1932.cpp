#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> num;

//Top-down 방식
int getMaxSum(int r, int c) {
	if (r == 1) {
		return num[1][1];
	}
	if (r == 0 || c == 0) {
		return 0;
	}
	if (dp[r][c] >= 0) { //dp값이 이미 존재하는 경우
		return dp[r][c];
	}
	int t = max(getMaxSum(r - 1, c - 1), getMaxSum(r - 1, c)) + num[r][c];
	return dp[r][c] = t;
}

int top_down(int n) {
	dp.assign(n + 1, vector<int>(n + 1, -1));
	int max_num = 0;
	for (int i = 1; i <= n; i++) {
		max_num = max(max_num, getMaxSum(n, i));
	}
	return max_num;
}

//Bottom-up 방식
int bottom_up(int n) {
	dp.assign(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + num[i][j];
		}
	}

	int max_num = 0;
	for (int i = 1; i <= n; i++) {
		max_num = max(max_num, dp[n][i]);
	}
	return max_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	num.assign(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[i][j];
		}
	}

	//연산 & 출력
	cout << top_down(n);

	return 0;
}