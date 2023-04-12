#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> dfs_hacked;

//dfs: 시간 초과
int dfs(int n, int c, vector<vector<int>>& trust) {
	int cnt = 1; //해당 컴퓨터가 해킹할 수 있는 컴퓨터 수
	dfs_hacked.assign(n + 1, false);
	dfs_hacked[c] = true;

	for (int i = 0; i < trust[c].size(); i++) {
		int next_c = trust[c][i];
		if (!dfs_hacked[next_c]) {
			cnt += dfs(n, next_c, trust);
		}
	}
	return cnt;
}

//start 컴퓨터를 시작으로 해킹한 컴퓨터의 개수 출력
int bfs(int n, int start, vector<vector<int>>& trust) {
	int result = 1; //해킹한 컴퓨터 개수
	vector<bool> bfs_hacked(n + 1, false);

	//처음 시작 컴퓨터 초기화
	queue<int> q;
	q.push(start);
	bfs_hacked[start] = true;

	while (!q.empty()) {
		int c = q.front();
		q.pop();

		//연결된 컴퓨터 다 해킹
		for (int i = 0; i < trust[c].size(); i++) {
			//아직 해킹되지 않은 컴퓨터라면 해킹
			if (!bfs_hacked[trust[c][i]]) {
				q.push(trust[c][i]);
				bfs_hacked[trust[c][i]] = true;
				result++;
			}
		}
	}
	return result;
}

vector<int> maxHacking(int n, vector<vector<int>>& trust) {
	vector<int> result;

	int max_cnt = 0;
	for (int i = 1; i < n + 1; i++) {
		//해킹 가능한 컴퓨터 개수 저장
		int hacking_cnt = bfs(n, i, trust);

		//가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호 저장
		if (hacking_cnt > max_cnt) {
			max_cnt = hacking_cnt;
			result = { i };
		}
		else if (hacking_cnt == max_cnt) {
			result.push_back(i);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	int a, b;
	vector<vector<int>> trust(n + 1, vector<int>());
	while (m--) {
		cin >> a >> b;
		trust[b].push_back(a);
	}

	//연산
	vector<int> result = maxHacking(n, trust);

	//출력
	for (auto iter : result) {
		cout << iter << " ";
	}

	return 0;
}