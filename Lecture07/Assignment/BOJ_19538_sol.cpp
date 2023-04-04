#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>>& adj_list, vector<int>& spreader) {
	vector<int> result(n + 1, -1); //초기화
	vector<int> adj_believer_cnt(n + 1, 0); //루머를 믿는 주변인의 수 저장
	queue<int> q;

	//최초 유포자 초기화
	for (int i = 0; i < m; i++) {
		int p = spreader[i];
		result[p] = 0;
		q.push(p);
	}

	while (!q.empty()) {
		int node = q.front(); //루머를 유포하는 사람
		q.pop();

		//node가 루머를 믿고 있으므로 주변 사람들한테 전파
		for (int i = 0; i < adj_list[node].size(); i++) {
			int next_node = adj_list[node][i]; //node 주변인
			adj_believer_cnt[next_node]++;

			//주변인의 절반 이상이 루머를 믿을 때 본인도 루머를 믿음
			//1. next_node가 아직 루머를 믿지 않는 상태
			//2. next_node의 주변인의 절반 이상이 루머를 믿고 있어야 함
			if (result[next_node] == -1 && adj_believer_cnt[next_node] >= (adj_list[next_node].size() / 2.0)) {
				result[next_node] = result[node] + 1;
				q.push(next_node);
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, p, m;
	cin >> n;

	vector<vector<int>> adj_list(n + 1, vector<int>()); //인접 리스트
	for (int i = 1; i <= n; i++) {
		while (true) {
			cin >> p;
			if (p == 0) {
				break;
			}
			adj_list[i].push_back(p);
		}
	}
	
	cin >> m;
	vector<int> spreader(m); //최초 유포자 번호 저장
	for (int i = 0; i < m; i++) {
		cin >> spreader[i];
	}

	//연산
	vector<int> result = bfs(n, m, adj_list, spreader);

	//출력
	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}