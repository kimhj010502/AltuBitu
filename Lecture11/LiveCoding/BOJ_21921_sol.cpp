#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

//슬라이딩 윈도우로 최대 방문자 수와 그 기간의 개수 반환
ii slidingWindow(int n, int x, vector<int>& visit) {
	//윈도우 초기화
	int left = 1, right = x;
	int visitor = 0; //방문자 수
	int cnt = 1; //최대 방문자 수 기간 개수

	for (int i = left; i <= right; i++) {
		visitor += visit[i];
	}
	int max_visitor = visitor; //최대 방문자 수

	while (right < n) {
		visitor -= visit[left++]; //이번 윈도우에서 제외
		visitor += visit[++right]; //이번 윈도우에 추가

		//새로운 최대 방문자수라면 기간의 개수를 1로 초기화
		if (visitor > max_visitor) {
			cnt = 1;
			max_visitor = visitor;
		}
		//최대 방문자수라면 기간의 개수 증가
		else if (visitor == max_visitor) {
			cnt++;
		}
	}
	return { max_visitor, cnt };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, x;
	cin >> n >> x;

	bool sad = true; //최대 방문자 수가 0인지의 여부
	vector<int> visit(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> visit[i];
		if (visit[i]) {
			sad = false;
		}
	}

	//연산 & 출력
	//최대 방문자 수가 0인 경우
	if (sad) {
		cout << "SAD";
	}
	//최대 방문자 수가 0이 아닌 경우
	else {
		ii result = slidingWindow(n, x, visit);
		cout << result.first << "\n" << result.second;
	}

	return 0;
}