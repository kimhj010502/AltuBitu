#include <iostream>
#include <vector>

using namespace std;

const int NUM_CHARS = 26;

//각 알파벳의 개수 세기
void countFreq(string word, vector<int>& freq) {
	for (int i = 0; i < word.length(); i++) {
		freq[word[i] - 'A']++;
	}
}

//다른 문자의 개수 세기
int countDiff(string word, vector<int> original_freq) {
	vector<int> freq(NUM_CHARS, 0);
	int diff = 0; //원본 단어와의 차이

	countFreq(word, freq); //각 알파벳의 개수 세기

	//원본 단어와 다른 알파벳 개수 구하기
	for (int i = 0; i < NUM_CHARS; i++) {
		diff += abs(original_freq[i] - freq[i]);
	}
	return diff;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	
	string original; //첫 번째 단어
	cin >> original;
	//각 알파벳의 개수를 저장할 정수형 벡터
	vector<int> original_freq(NUM_CHARS, 0);

	//연산
	countFreq(original, original_freq);

	int ans = 0;
	for (int i = 1; i < n; i++) {
		string word;
		cin >> word;

		int diff = countDiff(word, original_freq);
		//비슷한 단어 세기
		if (diff <= 1 || diff == 2 && original.length() == word.length()) {
			ans++;
		}
	}

	//출력
	cout << ans;

	return 0;
}