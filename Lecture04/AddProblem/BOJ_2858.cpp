#include <iostream>

using namespace std;

typedef pair<int, int> ii;
const int MAX = 5000;

ii solution(int r, int b) {
	for (int l = 3; l < MAX; l++) {
		for (int w = 3; w < MAX; w++) {
			int r_num = l * w - (l - 2) * (w - 2);
			int b_num = (l - 2) * (w - 2);
			//r_num과 b_num이 주어진 r, b와 같다면 l, w 리턴
			if (r_num == r && b_num == b) {
				return { l,w };
			}
			//구한 타일의 개수가 주어진 타일의 개수보다 커진다면 w 증가 멈추고 l 증가
			if (r_num > r || b_num > b) {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int r, b;
	cin >> r >> b;

	//연산
	ii lw = solution(r, b);
	//큰 수를 L로, 작은 수를 W로 만들기
	if (lw.second > lw.first) {
		swap(lw.first, lw.second);
	}

	//출력
	cout << lw.first << " " << lw.second;

	return 0;
}