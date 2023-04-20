#include <iostream>
#include <vector>

using namespace std;

vector<string> word(3);
vector<int> alphabet_num(26, -1); //알파벳에 대응되는 숫자 저장
vector<bool> num(10, false); //0~9의 숫자가 사용되었는지의 여부 저장
vector<bool> is_exist(26, false); 
vector<int> alphabet;
int alphabet_cnt; //사용된 알파벳의 개수
bool is_possible = false; //계산식에 해답이 존재하는지의 여부

//사용된 알파벳의 개수 반환
int countAlphabet() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < word[i].size(); j++) {
			is_exist[word[i][j] - 65] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (is_exist[i]) {
			cnt++;
			alphabet.push_back(i);
		}
	}
	return cnt;
}

//계산식이 성립하는지의 여부 반환
bool check() {
	vector<int> word_num(3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < word[i].size(); j++) {
			word_num[i] = word_num[i] * 10 + alphabet_num[word[i][j] - 65];
		}
	}

	if (word_num[0] + word_num[1] == word_num[2]) {
		return true;
	}
	return false;
}

void backtracking(int cnt) {
	//이미 발견했으면 종료
	if (is_possible) {
		return;
	}

	//종료 조건: 모든 알파벳이 대응된 경우
	if (cnt == alphabet_cnt) {
		//식이 성립한다면
		if (check()) {
			is_possible = true;
		}
		return;
	}

	//10개의 숫자 대응
	for (int j = 0; j < 10; j++) {
		//이미 대응된 숫자의 경우 넘어감
		if (num[j]) {
			continue;
		}

		//사용
		alphabet_num[alphabet[cnt]] = j;
		num[j] = true;

		//다음 문자 대응
		backtracking(cnt + 1);

		//반납
		alphabet_num[alphabet[cnt]] = -1;
		num[j] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	for (int i = 0; i < 3; i++) {
		cin >> word[i];
	}

	//연산
	alphabet_cnt = countAlphabet();

	//알파벳의 종류가 10개가 넘는다면 바꿀 수 없으므로 NO 출력
	if (alphabet_cnt > 10) {
		cout << "NO";
		return 0;
	}

	backtracking(0);

	//출력
	if (is_possible) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}