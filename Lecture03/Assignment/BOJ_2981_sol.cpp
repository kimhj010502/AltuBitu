#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//최대공약수 구하기
int getGcdIter(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int getGcdRecur(int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcdRecur(b, a % b);
}

vector<int> solution(int n, vector<int>& numbers) {
	vector<int> result; //모든 M 저장
	sort(numbers.begin(), numbers.end());

	//1. 검문소 사이 간격의 최대공약수(gcd) 계산
	int gcd = numbers[1] - numbers[0];
	for (int i = 2; i < n; i++) {
		int a = max(gcd, numbers[i] - numbers[i - 1]);
		int b = min(gcd, numbers[i] - numbers[i - 1]);
		gcd = getGcdRecur(a, b);
	}

	//2. gcd의 모든 약수 구하기 -> 모든 M 구하기
	for (int i = 2; i * 2 <= gcd; i++) {
		//i가 gcd의 약수이면
		if (gcd % i == 0) {
			result.push_back(i);
		}
	}
	result.push_back(gcd);

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	//연산
	vector<int> result = solution(n, numbers);

	//출력
	for (auto iter : result) {
		cout << iter << " ";
	}

	return 0;
}