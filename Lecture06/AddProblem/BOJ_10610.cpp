#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//30의 배수가 될 조건
//1. 3의 배수 (각 자리수의 합이 3의 배수)
//2. 일의 자리가 0인 수
string solution(string n) {
	sort(n.rbegin(), n.rend()); //내림차순으로 정렬

	int sum_num = 0;
	for (int i = 0; i < n.size(); i++) {
		sum_num += n[i] - '0';
	}
	
	//3의 배수가 아니거나, 10의 배수가 아니면 30의 배수가 존재하지 않으므로 -1 출력
	if (sum_num % 3 != 0 || n[n.size() - 1] != '0') {
		return "-1";
	}
	
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string n;
	cin >> n;

	//연산 & 출력
	cout << solution(n);

	return 0;
}