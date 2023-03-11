#include <iostream>
#include <vector>

using namespace std;

vector<int> isPrime(int n) {
	vector<int> is_prime(n + 1, true);
	
	for (int i = 2; i * i <= n; i++) {
		if (!is_prime[i]) { //소수가 아니면 넘어감
			continue;
		}
		for (int j = i * 2; j <= n; j += i) { //소수의 배수 다 지우기
			if (!is_prime[j]) { //이미 지워졌으면 넘어감
				continue;
			}
			is_prime[j] = false; //소수가 아님
		}
	}
	return is_prime;
}

void factorization(int n) {
	vector<int> is_prime = isPrime(n);

	for (int i = 2; i <= n; i++) {
		if (n == 1) {
			break;
		}
		if (!is_prime[i]) {
			continue;
		}
		while (n % i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	factorization(n);

	return 0;
}