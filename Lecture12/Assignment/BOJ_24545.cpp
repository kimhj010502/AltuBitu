#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dfs(int cur, int prev, vector<vector<int>>& tree, vector<map<int, int>>& cnt_node) {
	//저장된 값이 있는 경우 바로 리턴
	if (cnt_node[prev][cur]) {
		return cnt_node[prev][cur];
	}

	int cnt = 0;
	//cur 노드와 연결된 노드 탐색
	for (int next : tree[cur]) {
		//탐색할 노드가 이미 거쳐온 노드인 경우 넘어감
		if (next == prev) {
			continue;
		}
		cnt = max(cnt, dfs(next, cur, tree, cnt_node)); //최댓값 갱신
	}
	return cnt_node[prev][cur] = cnt + 1; //자기 자신 포함
}

int getMaxYTree(int n, vector<vector<int>>& tree, vector<map<int, int>>& cnt_node) {
	int ans = 0;

	//Y-트리의 중심이 될 노드를 순차적으로 탐색
	for (int cur = 1; cur <= n; cur++) {
		//간선의 수가 3보다 작은 경우 중심이 될 수 없음
		if (tree[cur].size() < 3) {
			continue;
		}

		vector<int> cnt; //cur 노드에서 나오는 간선에서 얻을 수 있는 노드의 수 저장
		//cur 노드와 연결된 노드 탐색
		for (int next : tree[cur]) {
			cnt.push_back(dfs(next, cur, tree, cnt_node));
		}
		sort(cnt.rbegin(), cnt.rend()); //내림차순으로 정렬
		ans = max(ans, cnt[0] + cnt[1] + cnt[2] + 1); //가장 많은 노드를 선택할 수 있는 경우 세가지 + 중심점
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, u, v;
	cin >> n;

	vector<vector<int>> tree(n + 1, vector<int>());
	vector<map<int, int>> cnt_node(n + 1, map<int, int>()); // 간선에 노드 수 저장
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	//연산 & 출력
	cout << getMaxYTree(n, tree, cnt_node);

	return 0;
}