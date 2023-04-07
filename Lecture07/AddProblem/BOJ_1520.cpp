#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int countRoute(int m, int n, vector<vector<int>>& map) {
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
	int n, m;
	cin >> m >> n;
	
	vector<vector<int>> map(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	//연산 & 출력
	cout << countRoute(m, n, map);

	return 0;
}
