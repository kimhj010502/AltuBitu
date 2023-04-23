#include <iostream>
#include <vector>

using namespace std;

int getMaxScore(int n, vector<int>& step) {
	vector<int> dp(n + 1); //각 계단까지의 최대 점수

	dp[1] = step[1];
	dp[2] = step[1] + step[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + step[i - 1], dp[i - 2]) + step[i];
	}

	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> step(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> step[i];
	}

	//연산 & 출력
	cout << getMaxScore(n, step);

	return 0;
}