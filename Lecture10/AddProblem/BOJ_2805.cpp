#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxHeight(int n, int m, vector<int>& height) {
	int result = 0;

	int left = 0, right = height[n - 1];
	while (left <= right) {
		int mid = (left + right) / 2;

		long long sum = 0; //자른 나무의 길이
		for (int i = 0; i < n; i++) {
			if (height[i] > mid) {
				sum += height[i] - mid;
			}
		}

		if (sum >= m) {
			left = mid + 1;
			result = max(result, mid);
		}
		else {
			right = mid - 1;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<int> height(n);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	sort(height.begin(), height.end());

	//연산 & 출력
	cout << maxHeight(n, m, height);

	return 0;
}