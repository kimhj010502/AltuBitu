#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;
	string input;
	int num;

	while (n--) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			q.push(num);
		}
		else if (input == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (input == "size") {
			cout << q.size() << '\n';
		}
		else if (input == "empty") {
			cout << q.empty() << '\n';
		}
		else if (input == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (input == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}

	return 0;
}