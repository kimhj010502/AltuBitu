#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int getOrder(int n, int m, vector<ii>& document, vector<int>& priority) {
	queue<ii> q;
	//문서 다 q에 넣고 시작
	for (int i = 0; i < n; i++) {
		q.push(document[i]);
	}

	int order = 1; //출력 순서
	int p = 9;
	int cnt = n;  //탐색할 문서 개수
	while (!q.empty()) {
		int cnt = q.size();
		while (priority[p] > 0) {
			//맨 앞에 있는 문서 제거
			ii node = q.front();
			q.pop();

			//현재 문서의 우선순위가 낮다면 q의 맨 뒤로 보내기
			if (node.second < p) {
				q.push(node);
			}
			else if (node.second == p) {
				priority[p]--;
				if (node.first == m) {
					return order;
				}
				order++;
			}
		}
		p--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		vector<ii> document(n); //{인덱스, 우선순위}
		vector<int> priority(10);
		for (int i = 0; i < n; i++) {
			document[i].first = i;
			cin >> document[i].second;
			priority[document[i].second]++;
		}

		//연산 & 출력
		cout << getOrder(n, m, document, priority) << "\n";
	}

	return 0;
}