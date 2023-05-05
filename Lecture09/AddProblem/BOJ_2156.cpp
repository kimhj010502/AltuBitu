#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(int n, vector<int>& wine) {
	//예외 처리
	if (n == 1) {
		return wine[0];
	}
	if (n == 2) {
		return wine[0] + wine[1];
	}
	if (n == 3) {
		return max({ wine[0] + wine[1], wine[1] + wine[2], wine[0] + wine[2] });
	}

	//dp[i]: i번째 포도주까지 마실 수 있는 최대의 양
	vector<int> dp(n);

	dp[0] = wine[0];
	dp[1] = wine[0] + wine[1];
	dp[2] = max({ wine[0] + wine[1], wine[1] + wine[2], wine[0] + wine[2] });

	for (int i = 3; i < n; i++) {
		dp[i] = max({ dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i], dp[i - 1] });
	}

	//최댓값 반환
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> wine(n);
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	//연산 & 출력
	cout << getMax(n, wine);

	return 0;
}