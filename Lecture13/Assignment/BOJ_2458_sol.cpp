#include <iostream>
#include <vector>

using namespace std;

void floyWarshall(int n, vector<vector<bool>>& graph) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				//i < k < j인 경우 i < j
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = true;
				}
			}
		}
	}
}

//s 학생의 키가 몇 번째인지 알 수 있는지의 여부
bool solution(int s, int n, vector<vector<bool>>& graph) {
	for (int i = 1; i <= n; i++) {
		//자기 자신이 아닌 다른 사람들이랑 비교할 수 없는 경우가 있는 경우 false 반환
		//graph[s][i] (s가 i보다 큼) 혹은 graph[i][s] (i가 s보다 큼)이 만족되어야 함
		if (i != s && (!graph[s][i] && !graph[i][s])) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, a, b;
	cin >> n >> m;

	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false)); //graph[i][j]: i와 j의 키를 비교할 수 있는지의 여부

	while (m--) {
		cin >> a >> b;
		graph[a][b] = true;
	}

	//연산
	floyWarshall(n, graph);

	int result = 0; //자신의 키가 몇 번째인지 알 수 있는 학생의 수
	for (int i = 1; i <= n; i++) {
		//자신의 키가 몇 번째인지 알 수 있는 경우 result 증가
		if (solution(i, n, graph)) {
			result++;
		}
	}

	//출력
	cout << result;

	return 0;
}