#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int isPossible(int n, int m, priority_queue<int>& pq, vector<int>& w) {	
	//1번 부터 M번 아이까지 반복
	for (int i = 0; i < m; i++) {
		int max_box = pq.top(); //선물이 가장 많이 담겨있는 상자
		pq.pop();

		//자신이 원하는 것보다 적은 개수의 선물이 들어있는 경우 실망함
		if (max_box < w[i]) {
			return 0;
		}
		else {
			pq.push(max_box - w[i]);
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, c;
	cin >> n >> m;

	priority_queue<int> pq; //선물의 개수가 큰 순서대로 정렬하는 우선순위큐
	for (int i = 0; i < n; i++) {
		cin >> c;
		pq.push(c);
	}

	vector<int> w(m);
	for (int i = 0; i < m; i++) {
		cin >> w[i];
	}

	//연산 & 출력
	cout << isPossible(n, m, pq, w);

	return 0;
}