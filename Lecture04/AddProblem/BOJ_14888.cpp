#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
const int MAX = 1e10;
const int MIN = -1e10;

//숫자로 입력된 연산자를 char형으로 만들어 반환하는 함수
vector<char> getOp(vector<int>& op) {
	vector<char> v{ '+','-','*','/' };

	vector<char> result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < op[i]; j++) {
			result.push_back(v[i]);
		}
	}
	return result;
}

//숫자 2개와 연산자 1개를 가지고 계산한 값을 반환하는 함수
int calNum(int n1, int n2, char op) {
	switch (op) {
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			if (n1 < 0) {
				return -1 * ((-1 * n1) / n2);
			}
			else {
				return n1 / n2;
			}
			break;
	}
}

//숫자와 연산자 벡터를 순서대로 계산하는 함수
int calculate(vector<int>& a, vector<char>& v) {
	int result = calNum(a[0], a[1], v[0]);
	for (int i = 2; i < a.size(); i++) {
		result = calNum(result, a[i], v[i - 1]);
	}
	return result;
}

//최댓값, 최솟값 반환 함수
ii solution(vector<int>& a, vector<int>& op) {
	vector<char> v = getOp(op);
	int result;
	int max_result = MIN, min_result = MAX;

	sort(v.begin(), v.end()); //next_permutation 함수 사용을 위해 정렬

	//모든 조합을 계산하여 최댓값, 최솟값 구하기
	do {
		result = calculate(a, v);
		max_result = max(max_result, result);
		min_result = min(min_result, result);
	} while (next_permutation(v.begin(), v.end()));

	return { max_result, min_result };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> op(4);
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	//연산
	ii result = solution(a, op);

	//출력
	cout << result.first << "\n" << result.second;

	return 0;
}