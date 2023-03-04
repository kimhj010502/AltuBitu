#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i] == true) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}	
	}
	
	return is_prime[n];
}

int eratos(int n, int k) {
	int cnt = 0;
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			if (!is_prime[j]) {
				continue;
			}
			is_prime[j] = false;
			cnt++;
			if (cnt == k) {
				return j;
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//연산 & 출력
	cout << eratos(n, k);

	return 0;
}