#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<bool> visited_recur;

void dfsRecur(int n, int node, vector<vector<bool>>& adj_matrix) {
	visited_recur[node] = true;
	cout << node << " ";

	for (int i = 1; i <= n; i++) {
		if (adj_matrix[node][i] && !visited_recur[i]) {
			dfsRecur(n, i, adj_matrix);
		}
	}
}

vector<int> dfs(int n, int v, vector<vector<bool>>& adj_matrix) {
	vector<int> result;
	vector<bool> visited(n + 1, false);
	stack<int> s;

	//시작 노드 초기화
	s.push(v);
	visited[v] = true;
	result.push_back(v);

	while (!s.empty()) {
		int node = s.top();
		bool child = false; //인접한 노드가 있는지의 여부

		//현재 노드와 연결된 노드 탐색
		for (int i = 1; i <= n; i++) {
			//연결된 노드 하나만 추가
			if (adj_matrix[node][i] && !visited[i]) {
				child = true;
				s.push(i);
				visited[i] = true;
				result.push_back(i);
				break;
			}
		}

		//더 연결된 노드가 없는 경우에 stack에서 제거
		if (!child) {
			s.pop();
		}
	}
	return result;
}

vector<int> bfs(int n, int v, vector<vector<bool>>& adj_matrix) {
	vector<int> result;
	vector<bool> visited(n + 1, false);
	queue<int> q;

	//시작 노드 초기화
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);

		//현재 노드와 연결된 노드 탐색
		for (int i = 1; i <= n; i++) {
			//연결된 노드 다 추가
			if (adj_matrix[node][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, v;
	cin >> n >> m >> v;
	
	int n1, n2;
	vector<vector<bool>> adj_matrix(n + 1, vector<bool>(n + 1, false));
	while (m--) {
		cin >> n1 >> n2;
		adj_matrix[n1][n2] = true;
		adj_matrix[n2][n1] = true;
	}

	//연산
	vector<int> dfs_result = dfs(n, v, adj_matrix);
	vector<int> bfs_result = bfs(n, v, adj_matrix);

	//출력
	/*
	for (auto iter : dfs_result) {
		cout << iter << " ";
	}
	*/

	//연산 & 출력
	visited_recur.assign(n + 1, false);
	dfsRecur(n, v, adj_matrix);

	cout << "\n";
	for (auto iter : bfs_result) {
		cout << iter << " ";
	}

	return 0;
}