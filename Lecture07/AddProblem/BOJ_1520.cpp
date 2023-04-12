#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int n, m;
vector<vector<int>> map;
vector<vector<int>> cnt;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int dfs(int r, int c) {
	//제일 오른쪽 아래 지점에 도달한 경우
	if (r == m - 1 && c == n - 1) {
		return 1;
	}

	//이미 탐색을 한 경우
	if (cnt[r][c] != -1) {
		return cnt[r][c];
	}

	cnt[r][c] = 0;

	//이웃한 4개의 방향으로 탐색
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		//이웃한 지점 중에 더 낮은 지점으로 이동
		if (nr >= 0 && nr < m && nc >= 0 && nc < n && map[nr][nc] < map[r][c]) {
			cnt[r][c] += dfs(nr, nc);
		}
	}
	return cnt[r][c];
}

//bfs: 시간 초과
int bfs(int m, int n, vector<vector<int>>& map) {
	vector<vector<int>> cnt(m, vector<int>(n, 0));
	queue<ii> q;

	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	//시작 지점 초기화
	q.push({ 0,0 });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		//이웃한 4개의 방향으로 탐색
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			//이웃한 지점 중에 더 낮은 지점으로 이동
			if (nr >= 0 && nr < m && nc >= 0 && nc < n && map[nr][nc] < map[r][c]) {
				cnt[nr][nc]++;
				q.push({ nr,nc });
			}
		}
	}
	return cnt[m - 1][n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> m >> n;

	map.assign(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	//연산 & 출력
	cnt.assign(m, vector<int>(n, -1));
	cout << dfs(0, 0);

	return 0;
}