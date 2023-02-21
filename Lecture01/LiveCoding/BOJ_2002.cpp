#include <iostream>
#include <map>
#include <vector>

using namespace std;

int overtake(int n, vector<int>& order_out) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (order_out[j] < order_out[i]) {
				ans++;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int n;
	string input;
	map<string, int> order_in;
	vector<int> order_out;

	//�Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		order_in[input] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> input;
		order_out.push_back(order_in[input]);
	}

	//���� & ���
	cout << overtake(n, order_out) << '\n';

	return 0;
}