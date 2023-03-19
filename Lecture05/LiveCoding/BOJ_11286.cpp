#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	//x1: 부모 노드, x2: 자식 노드
	//true일 때 swap
	bool operator()(const int& x1, const int& x2) {
		//절댓값이 다른 경우
		if (abs(x1) != abs(x2)) {
			//절댓값이 가장 작은 값이 top이 되어야 함
			return abs(x1) > abs(x2);
		}
		//절댓값이 같은 경우
		else {
			//가장 작은 값이 top이 되어야 함
			return x1 > x2;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;

	int x;
	while (n--) {
		cin >> x;
		if (x == 0) {
			//배열이 비어있는 경우 0 출력
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			//배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거함
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			//배열에 x값 추가
			pq.push(x);
		}
	}

	return 0;
}