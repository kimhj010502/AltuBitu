#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1000000, 0); //0으로 초기화

//Top-down 방식
int top_down(int n) {
	if (n <= 1) {
		return n;
	}
	if (dp[n]) { //dp값이 이미 존재하는 경우
		return dp[n];
	}
	return dp[n] = (top_down(n - 1) + top_down(n - 2)) % 1000000007;
}

//Bottom-up 방식
int bottom_up(int n) {
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << bottom_up(n);

	return 0;
}