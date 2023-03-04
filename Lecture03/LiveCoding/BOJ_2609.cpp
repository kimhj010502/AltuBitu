#include <iostream>

using namespace std;

int getGcd(int a, int b) {
	for (int i = b; i > 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
}

int gcdIter(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int a, b;
	cin >> a >> b;

	//연산
	int gcd = gcdIter(max(a, b), min(a, b));

	//출력
	cout << gcd << "\n" << a * b / gcd;

	return 0;
}