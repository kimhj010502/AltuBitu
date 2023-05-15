#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//card 벡터에 num이 존재하는지의 여부 반환
int isExist(int n, int num, vector<int>& card) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (card[mid] == num) {
			return 1;
		}
		else if (card[mid] < num) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, num;
	cin >> n;

	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	//card 배열 정렬
	sort(card.begin(), card.end());

	cin >> m;
	while (m--) {
		cin >> num;

		//연산 & 출력
		cout << isExist(n, num, card) << " ";
	}

	return 0;
}