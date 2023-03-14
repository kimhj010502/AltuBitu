#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<char, char> cc;

cc move(string input, char x, char y) {
	for (int i = 0; i < input.size(); i++) {
		char how = input[i];
		if (how == 'R') {
			x++;
		}
		else if (how == 'L') {
			x--;
		}
		else if (how == 'T') {
			y++;
		}
		else if (how == 'B') {
			y--;
		}
	}

	return { x,y };
}

bool checkRange(cc p) {
	if (p.first < 'A' || p.first > 'H' || p.second < '1' || p.second > '8') {
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cc k, s;
	int n;
	string input;

	//입력
	cin >> k.first >> k.second >> s.first >> s.second >> n;

	while (n--) {
		cin >> input;

		cc next_k, next_s; //킹과 돌의 다음 위치

		//연산
		//1. 킹 이동
		next_k = move(input, k.first, k.second);

		//2. 돌 이동 (킹과 돌의 위치가 같은 경우에만 돌을 이동시킴)
		if (next_k.first == s.first && next_k.second == s.second) {
			next_s = move(input, s.first, s.second);
		}
		else {
			next_s = s;
		}

		//3. 이동 위치 범위 체크
		if (checkRange(next_k) && checkRange(next_s)) {
			k = next_k;
			s = next_s;
		}
	}

	//출력
	cout << k.first << k.second << "\n" << s.first << s.second;

	return 0;
}