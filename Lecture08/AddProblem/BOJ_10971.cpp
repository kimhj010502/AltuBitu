#include <iostream>
#include <vector>

using namespace std;

int n;
int min_ans = 10000000;
vector<vector<int>> w;
vector<bool> visited;

//cnt: 지금까지 방문한 도시의 개수, start: 출발 도시, prev: 이전 도시, ans: 현재 비용
void backtracking(int cnt, int start, int prev, int ans) {
	//종료 조건: 모든 도시를 방문했고 출발 도시로 돌아갈 수 있는 경우
	if (cnt == n - 1 && w[prev][start] != 0) {
		ans += w[prev][start]; //마지막으로 출발 도시로 돌아옴
		min_ans = min(min_ans, ans);
		return;
	}

	for (int i = 0; i < n; i++) {
		//아직 n개 도시를 다 방문하지 않았는데 출발 도시를 방문하지 않도록 함
		if (i == start) {
			continue;
		}

		//아직 방문하지 않은 도시이면서 갈 수 있는 도시인 경우
		if (!visited[i] && w[prev][i] != 0) {
			//사용
			visited[i] = true;
			ans += w[prev][i];

			//다음 도시 선택
			backtracking(cnt + 1, start, i, ans);

			//반납
			visited[i] = false;
			ans -= w[prev][i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;
	w.assign(n, vector<int>(n, 0));
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	//연산
	for (int i = 0; i < n; i++) {
		visited.assign(n, false);
		backtracking(0, i, i, 0);
	}

	//출력
	cout << min_ans;

	return 0;
}