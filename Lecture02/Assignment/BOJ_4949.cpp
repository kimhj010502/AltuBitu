#include <iostream>
#include <string>
#include <stack>

using namespace std;

string check(string& input, stack<char>& s) {
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(' || input[i] == '[') {
			s.push(input[i]);
		}
		else if (input[i] == ')') {
			if (s.empty()) {
				return "no";
			}
			else {
				if (s.top() == '(') {
					s.pop();
				}
				else {
					return "no";
				}
			}
		}
		else if (input[i] == ']') {
			if (s.empty()) {
				return "no";
			}
			else {
				if (s.top() == '[') {
					s.pop();
				}
				else {
					return "no";
				}
			}
		}
	}

	if (s.empty()) {
		return "yes";
	}
	else {
		return "no";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	
	while (true) {
		getline(cin, input);
		stack<char> s;
		if (input == ".") {
			break;
		}
		cout << check(input, s) << "\n";
	}
	
	return 0;
}