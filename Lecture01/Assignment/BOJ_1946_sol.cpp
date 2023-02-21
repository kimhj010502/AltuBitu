#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int maxEmploy(vector<ci>& candidates) {
	int cnt = 1, highest_rank = candidates[0].second; //first�� ���� ���� ����� ���� �ɻ� ����
	for (int i = 1; i < candidates.size(); i++) {
		if (highest_rank > candidates[i].second) {
			highest_rank = candidates[i].second;
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	int t, n, cnt;

	//�Է�
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ci> candidates(n, ci(0, 0));
		for (int i = 0; i < n; i++) {
			cin >> candidates[i].first >> candidates[i].second;
		}
		//����
		sort(candidates.begin(), candidates.end()); //first ���� ������ �� second�� ������
		//���
		cout << maxEmploy(candidates) << "\n";
	}

	return 0;
}