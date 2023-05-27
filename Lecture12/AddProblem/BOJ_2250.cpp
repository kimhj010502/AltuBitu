#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> ii;

int n, c = 0;
int max_row = 0;
map<int, ii> tree;
vector<bool> visit;
vector<ii> position;

void dfs(int cur, int r) {
	//모든 열을 다 채운 경우 종료
	if (c == n) {
		return;
	}

	int left = tree[cur].first, right = tree[cur].second;

	//왼쪽 자식 노드 위치 정하기
	if (left != -1) {
		dfs(left, r + 1);
	}

	//본인 위치 정하기
	c++;
	position[cur] = { r,c };
	//cout << cur << "위치: " << r << ", " << c << "\n";
	visit[cur] = true;
	max_row = max(max_row, r);

	//오른쪽 자식 노드 위치 정하기
	if (right != -1) {
		dfs(right, r + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int x, l, r;
	cin >> n;
	
	position.assign(n + 1, { 0,0 }); //position[i]: i 노드의 행, 열 위치
	visit.assign(n + 1, false);
	vector<int> cnt(n + 1, 0); //cnt[i]: i 노드의 개수
	for (int i = 0; i < n; i++) {
		cin >> x >> l >> r;
		tree[x] = { l,r };
		cnt[x]++;

		if (l != -1) cnt[l]++;
		if (r != -1) cnt[r]++;
	}

	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 1) {
			root = i;
		}
	}

	//연산
	dfs(root, 1);

	vector<int> max_col(max_row + 1, 0); //max_col[i]: i행에 있는 노드들 중 가장 오른쪽에 있는 노드의 열 위치
	vector<int> min_col(max_row + 1, n + 1); //min_col[i]: i행에 있는 노드들 중 가장 왼쪽에 있는 노드의 열 위치
	
	for (int i = 1; i <= n; i++) {
		max_row = max(max_row, position[i].first);

		//해당 숫자의 열 위치가 해당 행에서의 최대 위치보다 큰 경우 갱신
		if (position[i].second > max_col[position[i].first]) {
			max_col[position[i].first] = position[i].second;
		}
		//해당 숫자의 열 위치가 해당 행에서의 최대 위치보다 작은 경우 갱신
		if (position[i].second < min_col[position[i].first]) {
			min_col[position[i].first] = position[i].second;
		}
	}

	ii result = { 1,0 }; //{ 너비가 가장 넓은 레벨, 그 레벨의 넓이 }
	for (int i = 1; i <= max_row; i++) {
		if (max_col[i] - min_col[i] > result.second) {
			result = { i, max_col[i] - min_col[i] };
		}
	}

	//출력
	cout << result.first << " " << result.second + 1;

	return 0;
}