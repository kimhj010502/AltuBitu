#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> josephus(const int& n, const int& k) {
	queue<int> num;
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		num.push(i);
	}

	while (!num.empty()) {
		int cnt = k - 1;
		while (cnt--) { //k-1보다 번호가 작은 사람은 큐에서 빼서 다시 뒤로 넣기
			int t = num.front();
			num.pop();
			num.push(t);
		}
		result.push_back(num.front()); //k번째 사람은 결과 벡터에 넣기
		num.pop();
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//연산
	vector<int> result = josephus(n, k);

	//출력
	cout << "<";
	for (int i = 0; i < n - 1; i++) { //결과 벡터에 저장된 숫자 순서대로 하나씩 출력
		cout << result[i] << ", ";
	}
	cout << result[n - 1] << ">";

	return 0;
}