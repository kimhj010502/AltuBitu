#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void balance(priority_queue<int>& max_pq, priority_queue<int, vector<int>, greater<>>& min_pq) {
	int M, m;

	//왼쪽 힙의 최댓값이 오른쪽 힙의 최솟값보다 크다면 다시 저장
	if (max_pq.top() > min_pq.top()) {
		M = max_pq.top();
		m = min_pq.top();

		max_pq.pop();
		min_pq.pop();

		max_pq.push(m);
		min_pq.push(M);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, input;
	cin >> n;

	priority_queue<int> max_pq; //MAX 왼쪽 힙
	priority_queue<int, vector<int>, greater<>> min_pq; //MIN 오른쪽 힙

	for (int i = 0; i < n; i++) {
		cin >> input;

		//연산
		//max_pq의 사이즈가 min_pq의 사이즈와 같거나 하나 더 많도록 저장
		if (max_pq.size() > min_pq.size()) {
			min_pq.push(input);
		}
		else {
			max_pq.push(input);
		}

		//두개의 pq 모두 원소가 존재할 때 균형을 맞춤
		if (!max_pq.empty() && !min_pq.empty()) {
			balance(max_pq, min_pq);
		}

		//출력
		cout << max_pq.top() << "\n";
	}

	return 0;
}