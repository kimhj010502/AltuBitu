#include <iostream>
#include <vector>

using namespace std;

void printResult(int t, int cnt) {
	cout << "Case " << t << ": ";
	if (cnt == 0) {
		cout << "No trees.\n";
		return;
	}
	if (cnt == 1) {
		cout << "There is one tree.\n";
		return;
	}
	cout << "A forest of " << cnt << " trees.\n";
}

void dfs(bool& flag, int cur, int prev, vector<vector<int>>& graph, vector<bool>& visited) {
	//이미 방문했던 곳을 또 방문하는 경우에는 트리가 아님
	if (visited[cur]) {
		flag = false;
		return;
	}

	visited[cur] = true;

	for (int next : graph[cur]) {
		//양방향으로 겹치는거 제외
		if (next == prev) {
			continue;
		}
		dfs(flag, next, cur, graph, visited);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, node1, node2, cnt;

	for (int t = 1;; t++) {
		//입력
		cin >> n >> m;

		//n과 m이 둘 다 0인 경우 반복문 종료
		if (!n && !m) {
			break;
		}

		vector<vector<int>> graph(n + 1, vector<int>());
		while (m--) {
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		//연산
		cnt = 0;
		vector<bool> visited(n + 1, false);
		for (int i = 1; i <= n; i++) {
			bool flag = true; //트리인지의 여부 저장하는 함수
			dfs(flag, i, 0, graph, visited);
			if (flag) {
				cnt++;
			}
		}

		//출력
		printResult(t, cnt);
	}

	return 0;
}