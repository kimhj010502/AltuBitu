#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//가장 인접한 두 공유기 사이의 거리가 dist가 되도록 공유기를 설치할 때
//설치되는 공유기의 개수 반환
int cntRouter(int dist, vector<int>& house) {
	//첫번째 집에 무조건 공유기 설치
	int cnt = 1;
	int cur = house[0]; //1번 집의 위치

	//최소 거리 기준을 만족하는 공유기 개수 세기
	for (int i = 0; i < house.size(); i++) {
		if (house[i] - cur >= dist) {
			cnt++;
			cur = house[i];
		}
	}
	return cnt;
}

//공유기 target개를 설치할 때, 인접한 두 공유기 사이의 최대 거리 반환
int binarySearch(int n, int target, vector<int>& house) {
	int left = 1, right = house[n - 1] - house[0];
	while (left <= right) {
		int mid = (left + right) / 2;
		int installed = cntRouter(mid, house);
		if (installed >= target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, c;
	cin >> n >> c;

	vector<int> house(n);
	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}

	//house 정렬
	sort(house.begin(), house.end());

	//연산 & 출력
	cout << binarySearch(n, c, house);

	return 0;
}