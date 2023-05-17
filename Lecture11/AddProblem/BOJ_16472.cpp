#include <iostream>
#include <vector>

using namespace std;

int maxLength(int n, string s) {
	vector<int> cnt(26, 0); //cnt[i]: 알파벳 i의 개수

	int max_len = 0; //최대 문자열의 길이
	int num = 0; //현재 알파벳 종류의 개수
	int left = 0, right = 0;
	while (left <= right && right < s.size()) {
		int next = s[right] - 'a'; //추가할 알파벳

		//해당 알파벳이 원래 없던 알파벳인 경우 num 증가
		if (cnt[next] == 0) {
			num++;
		}
		cnt[next]++;

		//num이 n보다 작거나 같은 경우 right 증가하여 계속해서 탐색
		if (num <= n) {
			max_len = max(max_len, right + 1 - left); //최대 길이 갱신
		}

		//num이 n보다 작거나 같아질 때까지 left 증가
		while (num > n) {
			int prev = s[left] - 'a'; //제거할 알파벳
			cnt[prev]--;
			if (cnt[prev] == 0) {
				num--;
			}
			left++;
		}
		
		//다음 탐색
		right++;
	}
	return max_len;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	string s;
	cin >> n >> s;

	//연산 & 출력
	cout << maxLength(n, s);

	return 0;
}