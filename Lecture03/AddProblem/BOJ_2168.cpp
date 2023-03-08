#include <iostream>

using namespace std;

//최대공약수 구하는 함수
int gcdRecur(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcdRecur(b, a % b);
}

//대각선이 그려진 타일의 개수 구하는 함수
//a와 b가 커지면 시간초과 발생
int numTiles(long long a, long long b) {
	if (a == b) {
		return a;
	}

	//a와 b를 최대한 다 약분된 수로 바꾸기
	int gcd = gcdRecur(a, b);
	a /= gcd; b /= gcd;

	int result = 0;
	long long k = b / a;

	//좌표 비교
	for (int i = 2; i <= a; i++) {
		long long new_k = (b * i) / a;
		result += (new_k - k) + 1;
		k = new_k;
	}

	//gcd로 나눈 상태로 최소한의 연산을 한 다음 그 타일이 반복된만큼 곱해주기
	return result * gcd; 
}

int advNumTiles(int a, int b) {
	//(a + b - 1) - (gcd - 1)
	return a + b - gcdRecur(a, b);;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int a, b;
	cin >> a >> b;

	//연산 & 출력
	//NumTiles(max(a, b), min(a, b)); //시간초과
	cout << advNumTiles(max(a, b), min(a, b));

	return 0;
}