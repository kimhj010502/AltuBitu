#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200 * 15;

int getPrice(int r, int c, vector<vector<int>>& field) {
	return field[r][c] + field[r - 1][c] + field[r + 1][c] + field[r][c - 1] + field[r][c + 1];
}

int solution(int n, vector<vector<int>>& field) {
	int result = MAX;
	int r1, c1, r2, c2, r3, c3;
	int t = n - 2;

	for (int i = 0; i < t * t; i++) {
		r1 = i / t + 1; c1 = i % t + 1;
		for (int j = 0; j < t * t; j++) {
			r2 = j / t + 1; c2 = j % t + 1;
			//두 꽃이 만나면 안됨
			if (abs(r1 - r2) + abs(c1 - c2) <= 2) {
				continue;
			}
			for (int k = 0; k < t * t; k++) {
				r3 = k / t + 1; c3 = k % t + 1;
				//두 꽃이 만나면 안됨
				if (abs(r1 - r3) + abs(c1 - c3) <= 2 || abs(r2 - r3) + abs(c2 - c3) <= 2) {
					continue;
				}
				result = min(result, getPrice(r1, c1, field) + getPrice(r2, c2, field) + getPrice(r3, c3, field));
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<int>> field(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> field[i][j];
		}
	}

	//연산 & 출력
	cout << solution(n, field);

	return 0;
}