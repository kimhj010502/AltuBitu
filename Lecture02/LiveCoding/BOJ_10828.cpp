﻿#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(MAX_SIZE);
	int top = -1;

	string input;
	int num;

	while (n--) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			arr[++top] = num;
		}
		else if (input == "pop") {
			if (top == -1) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[top--] << '\n';
			}
		}
		else if (input == "size") {
			cout << top + 1 << '\n';
		}
		else if (input == "empty") {
			if (top == -1) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (input == "top") {
			if (top == -1) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[top] << '\n';
			}
		}
	}

	return 0;
}