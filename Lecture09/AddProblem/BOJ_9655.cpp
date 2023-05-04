#include <iostream>

using namespace std;

string game(int n) {
	//n이 홀수인 경우 상근이 승리
	if (n % 2 == 1) {
		return "SK";
	}
	//n이 짝수인 경우 창영이 승리
	return "CY";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << game(n);

	return 0;
}