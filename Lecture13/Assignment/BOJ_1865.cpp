#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;

bool bellmanFord(int n, vector<tp>& edges) {
	vector<int> dist(n + 1, 0);

	//노드 하나씩 
	for (int i = 1; i <= n; i++) {
		bool flag = false; //음의 사이클 발생 여부

		for (int j = 0; j < edges.size(); j++) {
			int s = get<0>(edges[j]);
			int d = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			int next_weight = dist[s] + w;
			if (next_weight < dist[d]) {
				flag = true;
				dist[d] = next_weight;

				//n번째에 갱신이 되면 음의 사이클이 발생한 것이므로 true 반환
				if (i == n) {
					return true;
				}
			}
		}
		//줄어드는 시간이 없어서 한번도 갱신이 되지 못한 경우 false 반환
		if (!flag) {
			break;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tc, n, m, w, s, e, t;
	cin >> tc;

	while (tc--) {
		//입력
		cin >> n >> m >> w;

		vector<tp> edges;

		//양방향
		while (m--) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}

		//단방향
		while (w--) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		//연산 & 출력
		if (bellmanFord(n, edges)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}