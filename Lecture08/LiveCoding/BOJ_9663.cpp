#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 15;

int n, ans;
vector<bool> is_queen_in_col(SIZE);
vector<bool> is_queen_in_left(SIZE * 2);
vector<bool> is_queen_in_right(SIZE * 2);

//각 row당 하나의 퀸이 존재하므로 row마다 퀸을 하나씩 놓음
void backtrack(int r) {
	//종료 조건: 모든 row에 퀸을 놓은 경우
	if (r == n) {
		ans++;
		return;
	}

	for (int c = 0; c < n; c++) {
		//겹치는 퀸이 없는 경우에만 퀸 놓음
		if (!is_queen_in_col[c] && !is_queen_in_left[r + c] && !is_queen_in_right[r - c + n]) {
			//사용
			is_queen_in_col[c] = true;
			is_queen_in_left[r + c] = true;
			is_queen_in_right[r - c + n] = true;

			//다음 행에도 놓음
			backtrack(r + 1);

			//반납
			is_queen_in_col[c] = false;
			is_queen_in_left[r + c] = false;
			is_queen_in_right[r - c + n] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;

	//연산 
	backtrack(0);

	//출력
	cout << ans;

	return 0;
}