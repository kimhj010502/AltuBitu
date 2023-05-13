#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int getNumber(int n, int m, vector<int>& time) {
	//아이들 인원이 놀이기구의 개수보다 작거나 같은 경우 차례대로 바로 탈 수 있음
	if (n <= m) {
		return n;
	}

	ll t;
	ll left = 0, right = 6 * 1e10;
	while (left <= right) {
		ll mid = (left + right) / 2;

		ll cnt = m; //놀이기구를 탄 아이들 수
		for (int i = 1; i <= m; i++) {
			cnt += mid / time[i];
		}

		if (cnt >= n) {
			t = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	//t분동안 m명의 아이들이 다 놀이기구를 탈 수 있음
	//t-1분동안 몇 명의 아이들이 놀이기구를 탔는지 확인
	int t_cnt = m;
	for (int i = 1; i <= m; i++) {
		t_cnt += (t - 1) / time[i];
	}

	//t분에 탑승한 아이들의 숫자 계산
	for (int i = 1; i <= m; i++) {
		if (t % time[i] == 0) {
			t_cnt++;
		}
		if (t_cnt == n) {
			return i;
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