#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> num;
int result;

void dfs(int x, int y, int depth, int sum) {
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	//종료 조건: 칸 4개 선택한 경우
	if (depth == 4) {
		result = max(result, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < num.size() && ny >= 0 && ny < num[0].size() && num[nx][ny]) {
			int temp = num[nx][ny];

			//사용
			num[nx][ny] = 0;

			//다음 칸 선택
			if (depth == 2) { //ㅜ 모양은 현재 위치에서 다시 탐색
				dfs(x, y, depth + 1, sum + temp);
			}
			dfs(nx, ny, depth + 1, sum + temp); //선택한 칸으로 이동

			//반납
			num[nx][ny] = temp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	num.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num[i][j];
		}
	}

	//연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp = num[i][j];
			num[i][j] = 0;
			dfs(i, j, 1, temp);
			num[i][j] = temp;
		}
	}

	//출력
	cout << result;

	return 0;
}