#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 8;

int n, m;
vector<int> sequence(MAX_N);
vector<bool> is_used(MAX_N + 1);

//수열을 출력하는 함수
void printSequence() {
	for (int i = 0; i < m; i++) {
		cout << sequence[i] << " ";
	}
	cout << "\n";
}

//백트래킹 함수
void backtrack(int cnt) { //cnt: 현재까지 뽑은 숫자의 개수
	//종료 조건: M개의 숫자를 뽑은 경우
	if (cnt == m) {
		printSequence();
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (is_used[i]) {
			continue;
		}

		//사용
		sequence[cnt] = i;
		is_used[i] = true;

		//다음 숫자 선택
		backtrack(cnt + 1);

		//반납
		is_used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m;

	//연산 & 출력
	backtrack(0);

	return 0;
}