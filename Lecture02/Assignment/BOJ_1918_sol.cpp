#include <iostream>
#include <stack>

using namespace std;

int priority(char ch) { //연산자 우선순위 반환
	switch (ch) {
		case '*': case '/': return 2;
		case '+': case '-': return 1;
		case '(': return 0;
	}
}

string postfix(string input) { //중위 표기식 → 후위 표기식
	string result = "";
	stack<char> op;

	for (int i = 0; i < input.length(); i++) {
		/*연산자가 나오는 경우, 우선순위 비교하기
		피연산자가 나오는 경우, 곧바로 결과에 추가하기*/

		char curr = input[i];
		switch (curr) {
			case '(': //여는 괄호: 곧바로 스택에 추가
				op.push(curr);
				break;
			case ')': //닫는 괄호: 여는 괄호가 나오기 전까지 스택의 연산자 결과에 추가하기
				while (!op.empty() && op.top() != '(') {
					result += op.top();
					op.pop();
				}
				op.pop(); //여는 괄호 삭제
				break;

			case '+': case '-': case '*': case'/': //연산자 우선순위 비교
				//curr 연산자를 넣으려면, curr 연산자보다 높은 우선순위를 가지는 연산자를 pop해야 함
				while (!op.empty() && priority(curr) <= priority(op.top())) {
					result += op.top();
					op.pop();
				}
				op.push(curr); //현재 연산자 넣기
				break;

			default: //피연산자
				result += curr;
		}
	}

	while (!op.empty()) {
		result += op.top();
		op.pop();
	}

	return result;
}

int main() {
	//입력
	string input; //중위 표기식 입력값
	cin >> input;

	//연산 & 출력
	cout << postfix(input); //후위 표기식 출력값

	return 0;
}