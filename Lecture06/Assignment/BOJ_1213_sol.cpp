#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//팰린드롬의 앞쪽 글자 구하는 함수
string getFirst(vector<int>& alphabet) {
	string first;
	for (int i = 0; i < 26; i++) {
		//문자의 개수 반만큼 출력
		for (int j = 0; j < alphabet[i] / 2; j++) {
			first += (char)(i + 65);
		}
	}
	return first;
}

//영어 이름을 팰린드롬으로 바꾸는 함수
string palindrome(string s) {
	vector<int> alphabet(26); //알파벳의 개수 저장
	for (int i = 0; i < s.size(); i++) {
		alphabet[int(s[i]) - 65]++;
	}

	int odd_cnt = 0; //홀수개인 알파벳의 개수
	char odd_alphabet; //홀수개인 알파벳
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] % 2 != 0) {
			odd_cnt++;
			odd_alphabet = (char)(i + 65);
		}
	}

	//홀수개인 알파벳이 2종류 이상이면 불가능
	//글자가 짝수길이인데, 홀수개인 알파벳이 존재하는 경우 불가능
	//글자가 홀수길이인데, 홀수개인 알파벳이 한개가 아니면 불가능
	if (odd_cnt >= 2 || (odd_cnt > 0 && s.size() % 2 == 0) || (odd_cnt != 1 && s.size() % 2 != 0)) {
		return "I'm Sorry Hansoo";
	}

	string first = getFirst(alphabet); //앞쪽 글자
	string second = first; //뒤쪽 글자
	reverse(second.begin(), second.end());

	//글자가 짝수길이
	if (s.size() % 2 == 0) {
		return first + second;
	}
	//글자가 홀수길이 
	else {
		return first + odd_alphabet + second;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string s;
	cin >> s;

	//연산 & 출력
	cout << palindrome(s);

	return 0;
}