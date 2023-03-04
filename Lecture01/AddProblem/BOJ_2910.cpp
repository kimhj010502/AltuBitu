#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& n1, const pair<int, int>& n2) {
	return n1.second > n2.second;
}

int main() {
	int n, c, input, exist;

	//입력
	cin >> n >> c;
	vector<pair<int, int>> num;

	for (int i = 0; i < n; i++) {
		cin >> input;
		exist = 0;
		for (int j = 0; j < num.size(); j++) {
			if (num[j].first == input) {
				exist = 1;
				num[j].second += 1;
			}
		}
		if (exist == 0) {
			num.push_back(make_pair(input, 1));
		}
	}

	//연산
	stable_sort(num.begin(), num.end(), cmp);

	//출력
	for (auto iter : num) {
		for (int i = 0; i < iter.second; i++) {
			cout << iter.first << ' ';
		}
	}

	return 0;
}