#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//nums에 key값이 존재하면 1, 존재하지 않으면 0을 출력하는 함수
int binarySearch(int n, int key, vector<int>& nums) {
	int left = 0, right = n - 1; //최솟값, 최댓값의 인덱스
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] == key) {
			return 1;
		}
		else if (nums[mid] > key) {
			right = mid - 1;
		}
		else if (nums[mid] < key) {
			left = mid + 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, key;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	//nums 정렬
	sort(nums.begin(), nums.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> key;

		//연산 & 출력
		cout << binarySearch(n, key, nums) << "\n";
	}

	return 0;
}