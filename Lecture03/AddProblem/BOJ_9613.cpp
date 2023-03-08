#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcdRecur(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecur(b, a % b);
}

long long sumGcd(vector<int>& num) {
	long long sum_gcd = 0;
	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {
		for (int j = i + 1; j < num.size(); j++) {
			sum_gcd += gcdRecur(num[i], num[j]);
		}
	}

	return sum_gcd;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--) {
		//입력
		cin >> n;
		vector<int> num(n);
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		//연산 & 출력
		cout << sumGcd(num) << "\n";
	}

	return 0;
}