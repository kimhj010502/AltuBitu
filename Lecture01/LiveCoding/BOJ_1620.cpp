#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string input;
	map<int, string> num;
	map<string, int> name;

	//입력 & 연산
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		num[i] = input;
		name[input] = i;
	}

	//출력
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (isdigit(input[0])) {
			cout << num[stoi(input)] << '\n'; //stoi: string to int
		}
		else {
			cout << name[input] << '\n';
		}
	}

	return 0;
}