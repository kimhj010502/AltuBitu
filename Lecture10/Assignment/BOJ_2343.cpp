#include <iostream>
#include <vector>

using namespace std;

int minSize(int n, int m, int sum_len, int max_len, vector<int>& lecture) {
	int left = max_len, right = sum_len;
	while (left <= right) {
		int mid = (left + right) / 2; //탐색할 블루레이의 크기 후보
		int cnt = 0; //블루레이의 개수
		int sum_size = 0; //각 블루레이의 크기

		for (int i = 0; i < n; i++) {
			if (sum_size + lecture[i] > mid) {
				cnt++;
				sum_size = 0;
			}
			sum_size += lecture[i];
		}
		cnt++;

		if (cnt > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, sum_len = 0, max_len = 0;
	cin >> n >> m;

	vector<int> lecture(n);
	for (int i = 0; i < n; i++) {
		cin >> lecture[i];
		sum_len += lecture[i];
		max_len = max(max_len, lecture[i]);
	}

	//연산 & 출력
	cout << minSize(n, m, sum_len, max_len, lecture);

	return 0;
}