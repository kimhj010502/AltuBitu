#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int>& height) {
	vector<int> result;
	sort(height.begin(), height.end());

	int sum_height = 0;
	for (int i = 0; i < 9; i++) {
		sum_height += height[i];
	}

	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			if (sum_height - height[i] - height[j] == 100) {
				result.push_back(i); result.push_back(j);
				return result;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	vector<int> height(9);
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	
	//연산
	vector<int> result = solution(height);

	//출력
	for (int i = 0; i < 9; i++) {
		if (find(result.begin(), result.end(), i) == result.end()) {
			cout << height[i] << "\n";
		}
	}

	return 0;
}