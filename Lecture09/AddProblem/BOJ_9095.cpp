#include <iostream>
#include <vector>

using namespace std;

vector<int> initDp() {
	vector<int> dp(12);

	dp[1] = 1; //1
	dp[2] = 2; //1+1, 2
	dp[3] = 4; //1+1+1, 1+2, 2+1, 3

	//i = (i-3)+3, (i-2)+2, (i-1)+1
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	return dp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;

	//연산
	vector<int> dp = initDp();

	while (t--) {
		//입력
		cin >> n;

		//출력
		cout << dp[n] << "\n";
	}

	return 0;
}