#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5000000;

vector<int> getPrime() {
	vector<int> prime_num(MAX + 1, 0);

	for (int i = 2; i * i <= MAX; i++) {
		if (prime_num[i]) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			if (!prime_num[j]) {
				prime_num[j] = i;
			}
		}
	}

	return prime_num;
}

void factorization(vector<int>& prime_num, int k) {
	while (prime_num[k] != 0) {
		cout << prime_num[k] << " ";
		k /= prime_num[k];
	}
	cout << k << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n;

	vector<int> prime_num = getPrime();
	
	while (n--) {
		cin >> k;
		factorization(prime_num, k);
	}

	return 0;
}