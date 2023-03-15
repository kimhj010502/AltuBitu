#include <iostream>
#include <vector>

using namespace std;

//두 단어가 같은지의 여부 반환 함수
bool check(string s1, string s2) {
	//두 단어의 길이가 다르면 다른 단어임
	if (s1.size() != s2.size()) {
		return false;
	}

	int n = s1.size();
	vector<int> start; //글자가 같은 인덱스 저장할 벡터
	for (int i = 0; i < n; i++) {
		//글자가 다르면 넘어가기
		if (s1[i] != s2[0]) {
			continue;
		}
		//글자가 같은 경우
		start.push_back(i);
	}

	//저장된 인덱스가 없는 경우 같은 글자가 없으므로 false 반환
	if (start.size() == 0) {
		return false;
	}

	//저장된 인덱스가 있는 경우 글자 하나하나씩 비교
	for (int i = 0; i < start.size(); i++) {
		bool result = true;
		//f: s1의 시작 인덱스, s: s2의 시작 인덱스
		int f = start[i], s = -1;
		while (s++ < n - 1) { //총 n번 비교
			//글자가 같지 않으면 false 반환
			if (s1[f] != s2[s]) {
				result = false;
			}
			f = (f + 1) % n;
		}
		if (result) {
			return true;
		}
	}
	return false;
}

bool advCheck(string s1, string s2) {
	//두 단어의 길이가 다르면 다른 단어임
	if (s1.size() != s2.size()) {
		return false;
	}

	int n = s1.size();
	for (int i = 0; i < n; i++) {
		//글자가 같은 경우
		if (s1[i] == s2[0]) {
			bool result = true;
			//f: s1의 시작 인덱스, s: s2의 시작 인덱스
			int f = i, s = -1;
			while (s++ < n - 1) { //총 n번 비교
				//글자가 같지 않으면 false 반환
				if (s1[f] != s2[s]) {
					result = false;
				}
				f = (f + 1) % n;
			}
			if (result) {
				return true;
			}
		}
	}
	return false;
}

//서로 다른 단어의 개수 반환 함수
int countWord(vector<string>& word) {
	int cnt = word.size(); //단어의 개수로 초기화
	for (int i = 0; i < word.size(); i++) {
		for (int j = i + 1; j < word.size(); j++) {
			//두 단어가 같으면 같은 단어가 있다는 뜻이므로 cnt 감소
			//반복문 break해서 중복되어서 감소되지 않도록 함
			if (advCheck(word[i], word[j])) {
				cnt--;
				break;
			}
		}
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<string> word(n);
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	//연산 & 출력
	cout << countWord(word);

	return 0;
}