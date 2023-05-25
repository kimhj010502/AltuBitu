#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

//cur 노드에서 가장 먼 노드의 번호와 weight 반환
ii dfs(int cur, int prev, int weight, vector<vector<ii>>& graph) {
	int max_node = cur;
	int max_weight = weight;

	//다음 노드 탐색
	for (int i = 0; i < graph[cur].size(); i++) {
		int next_node = graph[cur][i].first;
		int next_weight = graph[cur][i].second;

		//탐색할 노드가 이미 거쳐온 노드인 경우 넘어감
		if (next_node == prev) {
			continue;
		}

		ii search = dfs(next_node, cur, weight + next_weight, graph);

		//가중치가 최댓값이 되도록 업데이트
		if (search.second > max_weight) {
			max_node = search.first;
			max_weight = search.second;
		}
	}
	return { max_node, max_weight };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, v1, v2, e;
	cin >> n;

	vector<vector<ii>> graph(n + 1, vector<ii>());
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2 >> e;
		graph[v1].push_back({ v2,e });
		graph[v2].push_back({ v1,e });
	}

	//연산
	ii result1 = dfs(1, -1, 0, graph); //루트 노드에서 가장 먼 노드
	ii result2 = dfs(result1.first, -1, 0, graph); //result1에서 가장 먼 노드

	//출력
	cout << result2.second;

	return 0;
}