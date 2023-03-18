#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int n) {
	//한자리수라면 바로 반환
	if (n < 10) {
		return to_string(n);
	}

	vector<vector<vector<string>>> v(12, vector<vector<string>>(10, vector<string>()));
	
	//한자리수 채우기
	for (int i = 0; i < 10; i++) {
		v[1][i].push_back(to_string(i));
	}

	int cnt = 9;
	//두자리수부터 열한자리수까지 채우기
	for (int i = 2; i < 12; i++) {
		//j로 시작하는 숫자
		for (int j = i - 1; j < 10; j++) {
			for (int k = 0; k < j; k++) {
				for (int t = 0; t < v[i - 1][k].size(); t++) {
					v[i][j].push_back(to_string(j) + v[i - 1][k][t]);
					cnt++;
					//cnt가 n이라면 정답이므로 해당 숫자 반환
					if (cnt == n) {
						return to_string(j) + v[i - 1][k][t];
					}
				}
			}
		}
	}
	//아무것도 반환하지 못했다면 이미 범위를 넘어선 것이므로 -1 반환
	return "-1";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << solution(n);

	return 0;
}