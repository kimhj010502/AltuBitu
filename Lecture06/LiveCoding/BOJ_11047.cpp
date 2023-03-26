#include <iostream>
#include <vector>

using namespace std;

int countCoin(vector<int>& coin, int k) {
	int cnt = 0;
	for (int i = coin.size() - 1; i >= 0; i--) {
		cnt += k / coin[i];
		k %= coin[i];
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	//연산 & 출력
	cout << countCoin(coin, k);

	return 0;
}