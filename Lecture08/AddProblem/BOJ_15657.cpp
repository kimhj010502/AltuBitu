#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> number;
vector<int> sequence;

//수열을 출력하는 함수
void printSequence() {
	for (auto iter : sequence) {
		cout << iter << " ";
	}
	cout << "\n";
}

//cnt: 수열에 있는 숫자의 개수, idx: 다음 숫자의 시작 인덱스
void backtracking(int cnt, int idx) {
	//종료 조건: 수열의 길이가 m이 된 경우
	if (cnt == m) {
		printSequence();
		return;
	}

	for (int i = idx; i < n; i++) {
		//사용
		sequence[cnt] = number[i];

		//다음 숫자 선택 (자기보다 작은 수는 못들어오게 함 -> 비내림차순)
		backtracking(cnt + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> m;

	number.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number.begin(), number.end()); //비내림차순으로 정렬
	
	//연산 & 출력
	sequence.assign(m, 0);
	backtracking(0, 0);

	return 0;
}