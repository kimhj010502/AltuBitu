#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, int> si;

string getName(int n, int input, vector<si>& power) {
	//가장 작은 범위인 경우
	if (input < power[0].second) {
		return power[0].first;
	}
	
	//가장 큰 범위인 경우
	if (input > power[n - 1].second) {
		return power[n - 1].first;
	}

	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (input > power[mid].second) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return power[left].first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, input;
	cin >> n >> m;

	vector<si> power(n);
	for (int i = 0; i < n; i++) {
		cin >> power[i].first >> power[i].second;
	}

	while (m--) {
		cin >> input;

		//연산 & 출력
		cout << getName(n, input, power) << "\n";
	}

	return 0;
}