#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
const int INF = 2e5; //최대 V-1개의 간선을 지나게 됨 -> V * (가중치 최대값)

vector<int> dijkstra(int start, int n, vector<vector<ii>>& graph) {
	vector<int> dist(n + 1, INF); //각 정점까지의 최단 경로 저장

	priority_queue<ii, vector<ii>, greater<>> pq; //{ 시작점으로부터의 거리, 정점 } 내림차순 정렬

	//시작 정점 초기화
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int weight = pq.top().first; //현재 정점까지의 경로값
		int node = pq.top().second; //현재 정점
		pq.pop();

		//이미 저장된 경로값이 더 작은 경우 넘어감
		if (weight > dist[node]) {
			continue;
		}

		//현재 정점과 연결된 노드 탐색
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_weight = weight + graph[node][i].second;

			//다음 노드까지의 경로가 더 짧은 경우 갱신
			if (next_weight < dist[next_node]) {
				dist[next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, e, k, u, v, w;
	cin >> n >> e >> k;

	vector<vector<ii>> graph(n + 1, vector<ii>()); //graph[i]: i 노드와 연결된 노드 벡터
	while (e--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w }); //u에서 v로 가는 가중치 w인 간선
	}

	//연산
	vector<int> dist = dijkstra(k, n, graph);

	//출력
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}