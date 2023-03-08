#include <iostream>

using namespace std;

int gcdRecur(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecur(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int a, b;
	char temp;
	cin >> a >> temp >> b;

	//연산
	int gcd = gcdRecur(max(a, b), min(a, b));

	//출력
	cout << a / gcd << ":" << b / gcd;

	return 0;
}