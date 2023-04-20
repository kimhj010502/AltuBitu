#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> alphabet;
vector<char> password;
vector<char> vowel = { 'a','e','i','o','u' }; //모음
vector<char> consonant = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' }; //자음

//최소 한 개의 모음, 최소 두 개의 자음으로 구성되어 있는지 확인
bool check() {
	int vowel_cnt = 0;
	for (int i = 0; i < vowel.size(); i++) {
		if (find(password.begin(), password.end(), vowel[i]) != password.end()) {
			vowel_cnt++;
		}
	}
	if (vowel_cnt < 1) {
		return false;
	}
	
	int consonant_cnt = 0;
	for (int i = 0; i < consonant.size(); i++) {
		if (find(password.begin(), password.end(), consonant[i]) != password.end()) {
			consonant_cnt++;
		}
	}
	if (consonant_cnt < 2) {
		return false;
	}

	return true;
}

//암호를 출력하는 함수
void printPassword() {
	for (auto iter : password) {
		cout << iter;
	}
	cout << "\n";
}

//cnt: 현재 암호를 이루는 알파벳의 개수, idx: 다음 알파벳의 인덱스
void backtracking(int cnt, int idx) {
	//종료 조건: 암호가 다 만들어진 경우
	if (cnt == l) {
		//조건에 맞다면 암호 출력
		if (check()) {
			printPassword();
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		//사용
		password[cnt] = alphabet[i];

		//다음 알파벳 구하기
		backtracking(cnt + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> l >> c;

	alphabet.assign(c, '0');
	for (int i = 0; i < c; i++) {
		cin >> alphabet[i];
	}

	//알파벳을 순서대로 정렬
	sort(alphabet.begin(), alphabet.end()); 

	//연산 & 출력
	password.assign(l, '0');
	backtracking(0, 0);

	return 0;
}