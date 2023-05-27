#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e6 + 1;

vector<int> getParent(int n, vector<int>& number, queue<int>& q) {
	vector<int> parent(MAX);
	parent[number[1]] = number[0];

	int prev = number[0], cur = number[1], p = -1;
	for (int i = 2; i < n; i++) {
		cur = number[i];

		//연속이 아닌 경우
		if (cur > prev + 1) {
			p = q.front();
			q.pop();
		}
		parent[cur] = p;
		prev = cur;
	}
	return parent;
}

int getCousin(int n, int k, vector<int>& number, queue<int>& q) {
	//k가 루트 노드인 경우 사촌 없음
	if (k == number[0]) {
		return 0;
	}

	vector<int> parent = getParent(n, number, q);

	//부모가 루트 노드인 경우 사촌이 존재하지 않음
	if (parent[k] == number[0]) {
		return 0;
	}

	int cnt = 0; //사촌의 수
	for (int i = 0; i < n; i++) {
		//조부모가 같고 부모가 다른 경우
		if ((parent[parent[number[i]]] == parent[parent[k]]) && (parent[number[i]] != parent[k])) {
			cnt++;
		}
		
		//조부모가 달라지기 시작하면 break
		if (parent[parent[number[i]]] > parent[parent[k]]) {
			break;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;

	while (true) {
		//입력
		cin >> n >> k;
		if (n == 0 && k == 0) {
			break;
		}

		vector<int> number(n);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			cin >> number[i];
			q.push(number[i]);
		}

		//연산 & 출력
		cout << getCousin(n, k, number, q) << "\n";
	}

	return 0;
}