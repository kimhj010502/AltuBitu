#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, h_centi, t, h, max_h;
	cin >> n >> h_centi >> t;

	priority_queue<int> pq;
	while (n--) {
		cin >> h;
		pq.push(h);
	}

	//연산
	int cnt = 0; //마법의 뿅망치를 사용한 횟수
	while (cnt < t) {
		max_h = pq.top();
		//모두 센티보다 작아졌거나 가장 키가 큰 사람의 키가 1인 경우 연산을 더 하지 못함
		if (h_centi > max_h || max_h == 1) {
			break;
		}
		pq.pop();
		pq.push(max_h / 2);
		cnt++;
	}

	//출력
	if (h_centi > pq.top()) {
		cout << "YES\n" << cnt;
	}
	else {
		cout << "NO\n" << pq.top();
	}

	return 0;
}