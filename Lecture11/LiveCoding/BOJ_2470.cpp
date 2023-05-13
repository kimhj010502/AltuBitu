#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

ii nearZero(int n, vector<int>& liquid) {
	int min_ans = 2 * 1e9; //0에 제일 가까운 용액의 특성값
	int left = 0, right = n - 1;
	ii result = { liquid[left], liquid[right] };
	while (left < right) {
		int ans = liquid[left] + liquid[right];

		//0에 더 가까운 경우 업데이트
		if (abs(ans) < min_ans) {
			min_ans = abs(ans);
			result = { liquid[left], liquid[right] };
		}

		if (ans > 0) {
			right--;
		}
		else if (ans < 0) {
			left++;
		}
		//ans가 0이라면 더 이상 찾을 필요가 없으므로 break
		else {
			break;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> liquid(n);
	for (int i = 0; i < n; i++) {
		cin >> liquid[i];
	}
	sort(liquid.begin(), liquid.end());

	//연산 & 출력
	ii result = nearZero(n, liquid);
	cout << result.first << " " << result.second;

	return 0;
}