#include <iostream>
#include <map>

using namespace std;

int main() {
	int t, n;
	string outfit, outfit_type;

	//�Է�
	cin >> t;
	while (t--) {
		int ans = 1;
		map<string, int> clothes; //���� �������� ������ �߿���
		cin >> n;
		while (n--) {
			cin >> outfit >> outfit_type;
			clothes[outfit_type]++;
		}
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			ans *= (iter->second + 1); //first: string, second: int
		}
		cout << ans - 1 << '\n';
	}

	return 0;
}