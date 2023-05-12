#include <iostream>
#include <vector>

using namespace std;

int getNumber(int n, int m, vector<int>& time) {
	//아이들 인원이 놀이기구의 개수보다 작거나 같은 경우 차례대로 바로 탈 수 있음
	if (n <= m) {
		return n;
	}

	int cnt = m; //놀이기구를 탄 아이들 수
	int cur_time = 0; //현재 시각
	while (true) {
		//cout << "시각: " << cur_time << ", 탑승: " << cnt << "\n";
		cur_time++;
		for (int i = 1; i <= m; i++) {
			if (cur_time % time[i]) {
				continue;
			}
			cnt++;
			if (cnt == n) {
				return i;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<int> time(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> time[i];
	}

	//연산 & 출력
	cout << getNumber(n, m, time);

	return 0;
}