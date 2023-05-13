#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	//연산
	vector<int> sum(n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + num[i - 1];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		//출력
		cout << sum[j] - sum[i - 1] << "\n";
	}

	return 0;
}
