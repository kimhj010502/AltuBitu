#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

ii maxVisit(int n, int x, vector<int>& visit) {
	vector<int> sum(n);
	for (int i = 0; i < x; i++) {
		sum[x - 1] += visit[i];
	}

	int max_visit = sum[x - 1]; //최대 방문자 수
	int cnt = 1; //최대 방문자 수가 있는 기간의 개수

	for (int i = x; i < n; i++) {
		sum[i] = sum[i - 1] + visit[i] - visit[i - x];
		//최대 방문자수라면 기간의 개수 증가
		if (max_visit == sum[i]) {
			cnt++;
		}
		//새로운 최대 방문자수라면 기간의 개수를 1로 초기화
		else if (max_visit < sum[i]) {
			cnt = 1;
			max_visit = sum[i];
		}
	}
	return { max_visit, cnt };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, x;
	cin >> n >> x;

	bool sad = true; //최대 방문자 수가 0인지의 여부
	vector<int> visit(n);
	for (int i = 0; i < n; i++) {
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
		ii result = maxVisit(n, x, visit);
		cout << result.first << "\n" << result.second;
	}

	return 0;
}