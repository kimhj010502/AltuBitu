#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;

int minTime(int n, int k) {
	vector<int> time(2 * MAX + 1, MAX);
	vector<int> visited(2 * MAX + 1, false);
	queue<int> q;

	//처음 시작 위치
	q.push(n);
	time[n] = 0;
	visited[n] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		//갈 수 있는 3가지의 위치
		int d[3] = { node - 1, node + 1, 2 * node };

		for (int i = 0; i < 3; i++) {
			//다음 위치
			int next_node = d[i];

			//아직 가지 않은 칸이라면 시간 계산해주고 q에 삽입
			if (next_node >= 0 && next_node < 2 * MAX + 1 && !visited[next_node]) {
				visited[next_node] = true;
				time[next_node] = time[node] + 1;
				q.push(next_node);
			}

			if (next_node == k) {
				return time[k];
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//연산 & 출력
	cout << minTime(n, k);
	
	return 0;
}