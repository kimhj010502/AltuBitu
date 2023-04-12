#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

//5개의 연속된 바둑알의 시작 위치 반환하는 함수
//연속된 바둑알이 없다면 { -1, -1 } 반환
ii location(vector<vector<int>>& board, queue<ii>& index, int color) {
	//탐색 방향 (오른쪽, 아래, 오른쪽아래 대각선, 오른쪽위 대각선)
	int dr[4] = { 1, 0, 1, -1 };
	int dc[4] = { 0, 1, 1, 1 };

	while (!index.empty()) {
		int r = index.front().first;
		int c = index.front().second;
		index.pop();

		//네 방향으로 탐색
		for (int i = 0; i < 4; i++) {
			int nr = r, nc = c;
			int cnt = 0; //연속된 바둑알의 개수
			//연속으로 6개까지 탐색 (6개 이상은 이긴 것이 아니므로)
			for (int j = 0; j < 6; j++) {
				if (nr >= 0 && nr < 19 && nc >= 0 && nc < 19 && board[nr][nc] == color) {
					cnt++;
					//다음에 탐색할 인덱스
					nr += dr[i];
					nc += dc[i];
				}
				else {
					break;
				}
			}

			//연속된 바둑알의 개수가 5개인 경우에 이김
			if (cnt == 5) {
				//이전 인덱스도 확인하기 (이전 인덱스까지 이어져있다면 5개를 넘으므로 안됨)
				bool prev_check = true;
				int prev_r = r - dr[i];
				int prev_c = c - dc[i];
				if (prev_r >= 0 && prev_r < 19 && prev_c >= 0 && prev_c < 19 && board[prev_r][prev_c] == color) {
					prev_check = false;
					continue;
				}

				//제일 왼쪽, 위쪽 인덱스 반환
				return { r, c };
			}
		}
	}
	//5개 연속인 바둑알이 없는 경우
	return { -1,-1 };
}

//어느 색의 바둑알이 이겼는지 구하고 위치와 함께 출력하는 함수
pair<int, ii> winColor(vector<vector<int>>& board, queue<ii>& black, queue<ii>& white) {
	ii black_location = location(board, black, 1);
	ii white_location = location(board, white, 2);

	bool black_win = true, white_win = true;
	if (black_location.first == -1 && black_location.second == -1) {
		black_win = false;
	}
	if (white_location.first == -1 && white_location.second == -1) {
		white_win = false;
	}

	//검은색이 이긴 경우
	if (black_win && !white_win) {
		return { 1, {black_location} };
	}
	//흰색이 이긴 경우
	else if (white_win && !black_win) {
		return { 2, {white_location} };
	}
	//승부가 결정나지 않은 경우
	else {
		return { 0, {-1,-1} };
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	vector<vector<int>> board(19, vector<int>(19));
	queue<ii> black; queue<ii> white;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				black.push({ i,j });
			}
			else if (board[i][j] == 2) {
				white.push({ i,j });
			}
		}
	}

	//연산 & 출력
	pair<int, ii> result = winColor(board, black, white);

	//승부가 결정나지 않은 경우
	if (result.first == 0) {
		cout << 0;
	}
	else {
		cout << result.first << "\n" << result.second.first + 1 << " " << result.second.second + 1;
	}

	return 0;
}