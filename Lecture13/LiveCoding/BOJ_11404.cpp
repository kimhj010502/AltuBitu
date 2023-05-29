#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;

void floyWarshall(int n, vector<vector<int>>& graph) {
	//k: 중간, i: 출발, j: 도착
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//i -> k -> j로 갈때의 비용
				int cost = graph[i][k] + graph[k][j];

				//더 적은 비용이 드는 경로 선택
				graph[i][j] = min(graph[i][j], cost);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, a, b, c;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //graph[i][j]: i 도시에서 j 도시로 가는데 필요한 비용

	//자기 자신과의 거리 0으로 초기화
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	while (m--) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c); //중복되는 노선이 있을 수 있으므로 최솟값
	}

	//연산
	floyWarshall(n, graph);

	//출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << " ";
		}
		cout << "\n";
	}

	return 0;
}