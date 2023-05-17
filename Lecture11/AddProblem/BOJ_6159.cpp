#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getCount(int n, int s, vector<int>& cow) {
	int cnt = 0;

	int left = 0, right = n - 1;
	while (left < right) {
		int sum_length = cow[left] + cow[right]; //두 소의 길이의 합

		//s보다 작거나 같으면 가능한 개수만큼 cnt 증가하고 left 증가
		if (sum_length <= s) {
			cnt += right - left;
			left++;
		}
		//s보다 크다면 길이의 합을 더 줄여야하므로 right 증가
		else {
			right--;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, s;
	cin >> n >> s;

	vector<int> cow(n);
	for (int i = 0; i < n; i++) {
		cin >> cow[i];
	}
	sort(cow.begin(), cow.end());

	//연산 & 출력
	cout << getCount(n, s, cow);

	return 0;
}