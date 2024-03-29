﻿#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> s;
	string input;
	int num;

	while (n--) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			s.push(num);
		}
		else if (input == "pop") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (input == "size") {
			cout << s.size() << '\n';
		}
		else if (input == "empty") {
			cout << s.empty() << '\n';
		}
		else if (input == "top") {
			if (s.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << s.top() << '\n';
			}
		}
	}

	return 0;
}