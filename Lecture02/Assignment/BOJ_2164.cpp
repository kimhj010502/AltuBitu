#include <iostream>
#include <queue>

using namespace std;

int main() {
	//입력
	int n;
	cin >> n;

	//연산
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop(); //제일 위의 카드 버리기
		int card = q.front(); //그 다음 제일 위에 있는 카드 밑으로 옮기기
		q.push(card);
		q.pop();
	}

	//출력
	cout << q.front();

	return 0;
}