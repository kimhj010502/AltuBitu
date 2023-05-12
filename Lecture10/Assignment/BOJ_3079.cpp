#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX = 1e5;

ll minTime(ll n, ll m, ll max_wait, vector<ll>& time) {
	//최소 시간: 0, 최대 시간: 최대 대기 시간 * 사람 수
	ll left = 0, right = max_wait * m;
	ll result = right; //최댓값으로 설정 후 값을 줄여감

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll people = 0; //mid 시간만큼 기다릴 때, 입국심사가 가능한 인원

		for (int i = 0; i < n; i++) {
			people += mid / time[i];
			if (people > m) {
				break;
			}
		}

		if (people >= m) {
			result = min(result, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	ll n, m, max_wait = -1;
	cin >> n >> m;

	vector<ll> time(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
		max_wait = max(max_wait, time[i]);
	}
	sort(time.begin(), time.end());

	//연산 & 출력
	cout << minTime(n, m, max_wait, time);

	return 0;
}