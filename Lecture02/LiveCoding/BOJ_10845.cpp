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
	int front = 0, rear = 0;

	string input;
	int num;

	while (n--) {
		cin >> input;

		if (input == "push") {
			cin >> num;
			rear = (rear + 1) % MAX_SIZE;
			arr[rear] = num;
		}
		else if (input == "pop") {
			if (front == rear) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[(front + 1) % MAX_SIZE] << '\n';
				front = (front + 1) % MAX_SIZE;
			}
		}
		else if (input == "size") {
			cout << rear - front << '\n';
		}
		else if (input == "empty") {
			if (front == rear) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (input == "front") {
			if (front == rear) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[(front + 1) % MAX_SIZE] << '\n';
			}
		}
		else if (input == "back") {
			if (front == rear) {
				cout << -1 << '\n';
			}
			else {
				cout << arr[rear] << '\n';
			}
		}
	}

	return 0;
}