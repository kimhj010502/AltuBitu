#include <iostream>
#include <vector>

using namespace std;

const int MAX_ANS = 200 * 15;

int getScore(int r, int c, vector<vector<int>> gr) {
	return gr[r][c] + gr[r - 1][c] + gr[r + 1][c] + gr[r][c - 1] + gr[r][c + 1];
}

int solution(int n, vector<vector<int>> gr) {
	int answer = MAX_ANS;
	int r1, c1, r2, c2, r3, c3;
	n -= 2;

	for (int i = 0; i < n * n; i++) {
		r1 = i / n + 1; c1 = i % n + 1;
		for (int j = 0; j < n * n; j++) {
			r2 = j / n + 1; c2 = j % n + 1;
			if (abs(r1 - r2) + abs(c1 - c2) <= 2) { //꽃끼리 닿는 경우에는 넘어감
				continue;
			}
			for (int k = 0; k < n * n; k++) {
				r3 = k / n + 1; c3 = k % n + 1;
				if (abs(r1 - r3) + abs(c1 - c3) <= 2 || abs(r2 - r3) + abs(c2 - c3) <= 2) { //꽃끼리 닿는 경우에는 넘어감
					continue;
				}
				answer = min(answer, getScore(r1, c1, gr) + getScore(r2, c2, gr) + getScore(r3, c3, gr));
			}
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<int>> gr(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gr[i][j];
		}
	}

	//연산 & 출력
	cout << solution(n, gr);

	return 0;
}