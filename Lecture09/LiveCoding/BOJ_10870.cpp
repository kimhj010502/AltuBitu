#include <iostream>

using namespace std;

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	
	//연산 & 출력
	cout << fibonacci(n);

	return 0;
}