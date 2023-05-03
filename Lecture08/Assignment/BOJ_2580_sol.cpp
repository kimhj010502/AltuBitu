#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;

bool is_finished = false; //모든 칸이 채워졌는지의 여부
vector<vector<int>> sudoku(MAX, vector<int>(MAX));
vector<vector<bool>> is_in_row(MAX, vector<bool>(MAX + 1)); //is_in_row[r][n]: r번 행에 n이 존재하는지의 여부
vector<vector<bool>> is_in_col(MAX, vector<bool>(MAX + 1)); // is_in_col[c][n]: c번 열에 n이 존재하는지의 여부
vector<vector<bool>> is_in_square(MAX, vector<bool>(MAX + 1)); // is_in_square[s][n]: s번 정사각형에 n이 존재하는지의 여부

//(r, c)가 몇 번 정사각형인지 반환
int calcSquare(int r, int c) {
	return (r / 3) * 3 + (c / 3);
}

//(r, c)에 n을 넣는 함수
void fill(int r, int c, int n) {
	sudoku[r][c] = n;
	is_in_row[r][n] = true;
	is_in_col[c][n] = true;
	is_in_square[calcSquare(r, c)][n] = true;
}

//(r, c) 비우는 함수
void empty(int r, int c) {
	int n = sudoku[r][c];
	sudoku[r][c] = 0;
	is_in_row[r][n] = false;
	is_in_col[c][n] = false;
	is_in_square[calcSquare(r, c)][n] = false;
}

//(r, c)에 n이 들어갈 수 있는지 확인하는 함수
bool check(int r, int c, int n) {
	return !is_in_row[r][n] && !is_in_col[c][n] && !is_in_square[calcSquare(r, c)][n];
}

//idx: 현재 채우려는 칸의 번호, r * 9 + c
void fillSudoku(int idx) {
	//종료 조건: 모든 칸을 다 채운 경우
	if (idx == MAX * MAX) {
		is_finished = true;
		return;
	}

	int r = idx / MAX;
	int c = idx % MAX;

	//빈 칸이 아닌 경우
	if (sudoku[r][c] != 0) {
		//다음 칸으로 넘어가기
		fillSudoku(idx + 1);
	}
	//빈 칸인 경우
	else {
		for (int i = 1; i <= 9; i++) {
			//불가능한 경우
			if (!check(r, c, i)) {
				continue;
			}

			//사용
			fill(r, c, i);

			//다음 칸 채우기
			fillSudoku(idx + 1);

			if (is_finished) {
				return;
			}

			//반납
			empty(r, c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> n;
			fill(i, j, n);
		}
	}

	//연산
	fillSudoku(0);

	//출력
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}