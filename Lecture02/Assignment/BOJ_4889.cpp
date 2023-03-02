#include <iostream>
#include <string>
#include <stack>

using namespace std;

int numCal(string input) {
	int left = 0, right = 0;
	stack<char> s;

	for (int i = 0; i < input.size(); i++) {
		char c = input[i];
		switch (c) {
		case '{':
			s.push(c);
			left++;
			break;
		case '}':
			if (!s.empty() && s.top() == '{') {
				s.pop();
				left--;
			}
			else {
				s.push(c);
				right++;
			}
		}
	}

	int result = left / 2 + right / 2 + left % 2 + right % 2;
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	int t = 1;

	while (true) {
		//입력
		getline(cin, input);
		if (input[0] == '-') {
			break;
		}

		//연산 & 출력
		cout << t << ". " << numCal(input) << "\n";
		t++;
	}

	return 0;
}