#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int input;
	vector<int> num;

	//입력
	while (cin >> input) {
		num.push_back(input);
	}

	int n = num.back();
	num.pop_back();
	
	//연산
	vector<pair<int, int>> num_pair;
	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {
		if (num[i] > n / 2) {
			break;
		}
		for (int j = i + 1; j < num.size(); j++) {
			if (num[i] + num[j] == n) {
				num_pair.push_back(make_pair(num[i], num[j]));
			}
		}
	}

	num_pair.erase(unique(num_pair.begin(), num_pair.end()), num_pair.end()); //중복 제거
	sort(num_pair.begin(), num_pair.end()); //정렬

	//출력
	for (auto iter : num_pair) {
		cout << iter.first << ' ' << iter.second << '\n';
	}
	cout << num_pair.size();

	return 0;
}