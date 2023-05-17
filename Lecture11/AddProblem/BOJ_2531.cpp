#include <iostream>
#include <vector>

using namespace std;

int getMax(int n, int d, int k, int c, vector<int>& sushi) {
	vector<int> cnt(d + 1, 0); //cnt[i]: 초밥 i의 개수
	cnt[c]++;
	for (int i = 1; i <= k; i++) {
		cnt[sushi[(n - k + i) % n]]++;
	}

	//sushi[n-k+1] ~ sushi[0] + 쿠폰까지의 초밥 종류의 개수 초기화
	int num = 0; //손님이 먹을 수 있는 초밥 가짓수
	for (int i = 1; i <= d; i++) {
		if (cnt[i] > 0) {
			num++;
		}
	}

	//연속해서 먹는 접시의 수와 총 접시의 수가 같다면 다 먹으면 됨
	if (n == k) {
		return num;
	}

	int max_num = num; //손님이 먹을 수 있는 초밥 가짓수의 최댓값
	int left = (n - k + 1) % n, right = 1;
	while (right < n) {
		//제거될 초밥이 한 개 밖에 없었다면 초밥 종류의 개수 감소
		if (cnt[sushi[left]] == 1) {
			num--;
		}
		cnt[sushi[left]]--;

		//새로 추가될 초밥이 아직 없었다면 초밥 종류의 개수 증가
		if (cnt[sushi[right]] == 0) {
			num++;
		}
		cnt[sushi[right]]++;

		max_num = max(max_num, num); //최댓값 갱신
		left = (left + 1) % n;
		right++;
	}
	return max_num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> sushi(n);
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}

	//연산 & 출력
	cout << getMax(n, d, k, c, sushi);

	return 0;
}