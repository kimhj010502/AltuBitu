#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//nums 배열 중 target이 처음으로 나오는 위치 반환
int lowerBound(int n, int target, vector<int>& nums) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] >= target) {
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	return left;
}

//nums 배열 중 target이 마지막으로 나오는 위치 반환
int upperBound(int n, int target, vector<int>& nums) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] <= target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
	}
	return left;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, target;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	//nums 정렬
	sort(nums.begin(), nums.end());

	cin >> m;
	while (m--) {
		cin >> target;

		//연산 & 출력
		cout << upperBound(n, target, nums) - lowerBound(n, target, nums) << " ";
	}

	return 0;
}