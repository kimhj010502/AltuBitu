#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getParent(int n, vector<vector<int>>& adj_list) {
	vector<int> parent(n + 1);
	vector<bool> visited(n + 1, false);
	queue<int> q;

	//시작 노드 초기화
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		//부모 노드
		int node = q.front();
		q.pop();

		for (int i = 0; i < adj_list[node].size(); i++) {
			//인접한 노드를 자식 노드로 설정
			int child_node = adj_list[node][i];

			//아직 방문하지 않은 경우
			if (!visited[child_node]) {
				visited[child_node] = true;
				parent[child_node] = node;
				q.push(child_node);
			}
		}
	}

	return parent;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, n1, n2;
	cin >> n;

	vector<vector<int>> adj_list(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		cin >> n1 >> n2;
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}

	//연산
	vector<int> parent = getParent(n, adj_list);

	//출력
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}