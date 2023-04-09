#include <iostream>
#include <vector>

using namespace std;

int n;
int min_diff = 2000;
vector<vector<int>> stats;
vector<bool> is_start;

int getDiff() {
	int start_sum = 0;
	int link_sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (is_start[i] && is_start[j]) {
				start_sum += stats[i][j];
				start_sum += stats[j][i];
			}
			else if (!is_start[i] && !is_start[j]) {
				link_sum += stats[i][j];
				link_sum += stats[j][i];
			}
		}
	}
	return abs(start_sum - link_sum);
}

void backtracking(int cnt) {
	//종료 조건: n/2의 인원이 모인 경우
	if (cnt == n / 2) {
		min_diff = min(min_diff, getDiff());
		return;
	}

	for (int i = 1; i <= n; i++) {
		//이미 스타트팀에 속해있다면 넘어가기
		if (is_start[i]) {
			continue;
		}

		//사용
		is_start[i] = true;

		//다음 사람 넣기
		backtracking(cnt + 1);
		
		//반납
		is_start[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;
	stats.assign(n + 1, vector<int>(n + 1));
	is_start.assign(n + 1, false);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	//연산
	backtracking(0);

	//출력
	cout << min_diff;

	return 0;
}
