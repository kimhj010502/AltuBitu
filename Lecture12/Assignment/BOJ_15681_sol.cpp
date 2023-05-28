#include <iostream>
#include <vector>

using namespace std;

/*1. 루트에서 DFS를 사용하여 탐색
2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 벡터에 저장
- 서브트리에 속한 정점의 개수를 저장하는 dp 배열을 1로 초기화
- 탐색 시 현재 정점의 자식 노드만 탐색해서 현재 정점의 dp 값에 더해줌
3. 쿼리로 주어지는 정점의 서브트리의 정점의 개수를 dp에서 찾아서 출력*/

void dfs(int cur, int prev, vector<vector<int>>& graph, vector<int>& dp) {
	//현재 정점의 자식 노드 탐색
	for (int i = 0; i < graph[cur].size(); i++) {
		//거쳐온 경로인 경우 넘어감
		if (graph[cur][i] == prev) {
			continue;
		}
		dfs(graph[cur][i], cur, graph, dp);
		dp[cur] += dp[graph[cur][i]]; //자식 노드의 dp값 더해줌
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r, q, u, v, node1, node2;

	//입력
	cin >> n >> r >> q;

	vector<vector<int>> graph(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	//연산
	vector<int> dp(n + 1, 1); //자기 자신도 자신을 루트로 하는 서브트리에 포함되므로 1로 초기화
	dfs(r, -1, graph, dp);

	//출력
	while (q--) {
		cin >> u;

		cout << dp[u] << "\n";
	}

	return 0;
}