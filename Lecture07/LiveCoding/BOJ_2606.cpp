#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> dfs_hacked;

int dfs(int node, vector<vector<int>>& adj_list) {
	dfs_hacked[node] = true;
	int cnt = 1;

	for (int i = 0; i < adj_list[node].size(); i++) {
		int next_node = adj_list[node][i];
		if (!dfs_hacked[next_node]) {
			cnt += dfs(next_node, adj_list);
		}
	}
	return cnt;
}

int bfs(int n, vector<vector<int>>& adj_list) {
	int cnt = 0;
	vector<bool> hacked(n + 1, false);
	queue<int> q;

	//시작 노드 초기화
	q.push(1);
	hacked[1] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		//현재 노드와 연결된 노드 탐색
		for (int i = 0; i < adj_list[node].size(); i++) {
			int next_node = adj_list[node][i];
			//연결된 노드 다 추가
			if (!hacked[next_node]) {
				q.push(next_node);
				hacked[next_node] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	int n1, n2;
	vector<vector<int>> adj_list(n + 1, vector<int>(0));
	while (m--) {
		cin >> n1 >> n2;
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}

	//연산 & 출력
	cout << bfs(n, adj_list);

	/*
	dfs_hacked.assign(n + 1, false);
	cout << dfs(1, adj_list) - 1;
	*/

	return 0;
}