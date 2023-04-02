#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int bfs(int n, int m, int raw, queue<ii>& q, vector<vector<int>>& box) {
	int t; //토마토가 모두 익는 데까지 걸리는 시간
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		t = box[r][c];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			//주변 토마토가 아직 익지 않은 경우
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && box[nr][nc] == 0) {
				//이웃 토마토 익힘
				q.push({ nr, nc });
				box[nr][nc] = t + 1;
				raw--;
			}
		}
	}

	//모든 토마토가 익은 경우
	if (raw == 0) {
		return t - 1; //첫 날을 빼줘야 함
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int m, n;
	cin >> m >> n;

	int raw = 0;
	queue<ii> q; //익은 토마토 저장
	vector<vector<int>> box(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ i,j });
			}
			else if (box[i][j] == 0) {
				raw++; //익지 않은 토마토의 개수 count
			}
		}
	}

	//연산 & 출력
	cout << bfs(n, m, raw, q, box);

	return 0;
}