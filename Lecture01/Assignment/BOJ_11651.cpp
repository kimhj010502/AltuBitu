#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second != p2.second) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

int main() {
	int n, x, y;

	//입력
	cin >> n;
	vector<pair<int, int>> point(n);
	for (int i = 0; i < n; i++) {
		cin >> point[i].first >> point[i].second;
	}

	//연산
	sort(point.begin(), point.end(), cmp);

	//출력
	for (int i = 0; i < n; i++) {
		cout << point[i].first << " " << point[i].second << "\n";
	}
	
	return 0;
}