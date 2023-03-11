#include <iostream>
#include <string>

using namespace std;

string solution(int n) {
	for (int i = 1; i < n; i++) {
		string num = to_string(i);
		int sum_num = i;
		for (int j = 0; j < num.size(); j++) {
			sum_num += num[j] - '0';
		}
		if (sum_num == n) {
			return num;
		}
	}
	return "0";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << solution(n);

	return 0;
}