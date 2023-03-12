#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getPrice(vector<vector<int>>& v) {
	int n = v[0].size() - 2;
	vector<vector<int>> price(n, vector<int>(n, 0));

	for (int i = 1; i < v[0].size() - 1 ; i++) {
		for (int j = 1; j < v[0].size() - 1; j++) {
			price[i - 1][j - 1] = v[i][j] + v[i - 1][j] + v[i + 1][j] + v[i][j - 1] + v[i][j + 1];
		}
	}
	return price;
}

int solution(vector<vector<int>>& v) {
	vector<vector<int>> price = getPrice(v);

	int n = price[0].size();
	int min_price = 3000; //최대 가격으로 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			min_price += 
			cout << price[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	solution(v);

	return 0;
}