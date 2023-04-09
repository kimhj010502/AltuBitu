#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 8;

int n, m;
vector<int> sequence(MAX_N + 1);

//수열을 출력하는 함수
void printSequence() {
	for (int i = 0; i < m; i++) {
		cout << sequence[i] << " ";
	}
	cout << "\n";
}

//백트래킹 함수
void backtrack(int cnt, int num) { //cnt: 현재까지 뽑은 숫자의 개수, num: 시작 숫자
	//종료 조건: M개의 숫자를 뽑은 경우
	if (cnt == m) {
		printSequence();
		return;
	}

	for (int i = num; i <= n; i++) {
		//사용
		sequence[cnt] = i;

		//다음 숫자 선택
		backtrack(cnt + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m;

	//연산 & 출력
	backtrack(0, 1);

	return 0;
}