#include <iostream>
#include <vector>

using namespace std;

vector<bool> visit;
vector<vector<int>> tree;
vector<vector<int>> dp;

void dfs(int cur) {
	visit[cur] = true;
	dp[cur][1] = 1; //cur 노드를 얼리어답터로 지정할 경우 얼리어답터 최소 개수 1로 증가

	//cur 노드와 연결된 노드들 탐색
	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (!visit[next]) {
			dfs(next);
			dp[cur][0] += dp[next][1]; //cur 노드가 얼리어답터가 아닌 경우 주변의 모든 노드가 얼리어답터여야 함
			dp[cur][1] += min(dp[next][0], dp[next][1]);//cur 노드가 얼리어답터인 경우 주변 노드의 얼리어답터 여부 상관 없음
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, u, v;
	cin >> n;

	visit.assign(n + 1, false); //visit[i]: i 노드의 방문 여부 저장
	dp.assign(n + 1, vector<int>(2, 0)); //dp[i]: i 노드가 얼리어답터인 경우와 아닌 경우의 최솟값 저장

	tree.assign(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	//연산
	dfs(1);
	
	//출력
	cout << min(dp[1][0], dp[1][1]);

	return 0;
}