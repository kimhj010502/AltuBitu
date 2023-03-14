#include <iostream>
#include <vector>

using namespace std;

vector<int> dr{ 1,0 };
vector<int> dc{ 0,1 };

int maxCount(int n, int r, int c, int dir, vector<vector<char>>& board) {
	int result = 0;
	int count = 0;
	char prev = ' '; //이전 사탕

	while(r < n && c < n) {
		//인접한 사탕과 색이 같은 경우
		if (prev == board[r][c]) {
			count++;
			result = max(result, count);
		}
		else {
			count = 1; //1로 초기화
			prev = board[r][c];
		}
		r += dr[dir];
		c += dc[dir];
	}
	return result;
}

int countCandy(int n, vector<vector<char>>& board) {
	int result = 0;

	for (int i = 0; i < n; i++) {
		result = max(result, maxCount(n, i, 0, 1, board)); //행 방향
		result = max(result, maxCount(n, 0, i, 0, board)); //열 방향
	}
	return result;
}

int solution(int r, int c, int n, vector<vector<char>>& board) {
	int result = 0;

	for (int i = 0; i < 2; i++) {
		int nr = r + dr[i]; int nc = c + dc[i];
		//사탕의 색이 다른 인접한 칸 사탕끼리 교환
		if (nr < n && nc < n && board[nr][nc] != board[r][c]) {
			swap(board[nr][nc], board[r][c]);
			result = max(result, countCandy(n, board));
			swap(board[nr][nc], board[r][c]); //원상복구
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	//연산
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, solution(i, j, n, board));
		}
	}

	//출력
	cout << result;

	return 0;
}