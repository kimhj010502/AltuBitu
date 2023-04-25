#include <iostream>
#include <vector>

using namespace std;

void getPsum(int n, vector<vector<int>>& num, vector<vector<int>>& psum) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + num[i][j];
		}
	}
}

int calcSum(vector<vector<int>>& psum, int x1, int y1, int x2, int y2) {
	return psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, x1, x2, y1, y2;
	cin >> n >> m;

	vector<vector<int>> num(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num[i][j];
		}
	}

	vector<vector<int>> psum(n + 1, vector<int>(n + 1));
	getPsum(n, num, psum);

	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << calcSum(psum, x1, y1, x2, y2) << "\n";
	}

	return 0;
}