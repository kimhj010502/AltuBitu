#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
const int INF = 1e5;

//start 도시부터 end까지 가는 데 걸리는 소요 시간 반환
int dijkstra(int start, int end, int n, vector<vector<ii>>& graph) {
	vector<int> v(n + 1, INF);
	priority_queue<ii, vector<ii>, greater<>> pq; //{ 시작점으로부터의 시간, 정점 } 내림차순 정렬

	//시작 정점 초기화
	v[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int t = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		//이미 저장된 시간이 새로 구한 시간보다 작을 경우 넘어감
		if (t > v[node]) {
			continue;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_time = t + graph[node][i].second;

			if (next_time < v[next_node]) {
				v[next_node] = next_time;
				pq.push({ next_time, next_node });
			}
		}
	}
	return v[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, x, a, b, t;
	cin >> n >> m >> x;

	vector<vector<ii>> graph(n + 1, vector<ii>()); //graph[시작점]: { 끝점, 소요시간 }
	while (m--) {
		cin >> a >> b >> t;
		graph[a].push_back({ b,t });
	}

	//연산
	int max_time = 0;
	for (int i = 1; i <= n; i++) {
		max_time = max(max_time, dijkstra(i, x, n, graph) + dijkstra(x, i, n, graph));
	}

	//출력
	cout << max_time;

	return 0;
}