#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

void minNum(int n, int m, vector<vector<int>>& field, vector<vector<bool>>& visited, queue<ii>& q) {
	//주변 4개의 방향
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	while (!q.empty()) {
		//배추가 있는 위치 선택
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = true;
		q.pop();

		//주변 4개의 방향으로 탐색
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//이웃한 배추의 위치를 visited 상태로 바꿈
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && field[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, m, k, x, y;
	cin >> t;

	while (t--) {
		//입력
		cin >> n >> m >> k;
		vector<vector<int>> field(n, vector<int>(m, 0));
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		queue<ii> q;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			field[x][y] = 1;
		}

		//연산
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == 1 && !visited[i][j]) {
					cnt++;
					q.push({ i,j });
					minNum(n, m, field, visited, q);
				}
			}
		}

		//출력
		cout << cnt << "\n";
	}

	return 0;
}
