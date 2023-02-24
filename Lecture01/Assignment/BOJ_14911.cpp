#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int input;
	vector<int> num;

	while (!cin.eof()) {
		cin >> input;
		num.push_back(input);
	}

	int n;
	cin >> n;

	for (auto iter : num) {
		cout << iter << '\n';
	}
	return 0;
}