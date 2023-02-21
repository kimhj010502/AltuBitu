#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	// ����� �ӵ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string input;
	map<int, string> num;
	map<string, int> name;

	//�Է� & ����
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		num[i] = input;
		name[input] = i;
	}

	//���
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