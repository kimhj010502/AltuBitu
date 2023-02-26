#include <iostream>
#include <vector>

#define MAX_SIZE 10000

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(MAX_SIZE);
	int front = 0, back = 0;

	string input;
	int num;

	while (n--) {
		cin >> input;

		if (input == "push_front") {
			cin >> num;
			front = (front + 1) % MAX_SIZE;
			arr[front] = num;
		}
		else if (input == "push_back") {
			cin >> num;
			arr[back] = num;
			back = (back - 1 + MAX_SIZE) % MAX_SIZE;
		}
		else if (input == "pop_front") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[front] << '\n';
				front = (front - 1 + MAX_SIZE) % MAX_SIZE;
			}
		}
		else if (input == "pop_back") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[(back + 1) % MAX_SIZE] << '\n';
				back = (back + 1) % MAX_SIZE;
			}
		}
		else if (input == "size") {
			cout << (front - back + MAX_SIZE) % MAX_SIZE << '\n';
		}
		else if (input == "empty") {
			if (front == back) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (input == "front") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[front] << '\n';
			}
		}
		else if (input == "back") {
			if (front == back) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[(back + 1) % MAX_SIZE] << '\n';
			}
		}
	}

	return 0;
}