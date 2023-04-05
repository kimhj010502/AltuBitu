#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

//합이 큰 알파벳 순으로 정렬
bool cmp1(const vector<int> d1, const vector<int> d2) {
	return d1[1] > d2[1];
}

//알파벳 순 (A~Z)로 정렬
bool cmp2(const vector<int> d1, const vector<int> d2) {
	return d1[0] < d2[0];
}

//A부터 Z까지 알파벳의 개수와 가장 높은 자리수를 담은 vector 반환 
vector<vector<int>> getDigit(int n, vector<string>& word) {
	vector<vector<int>> digit(26, vector<int>(3)); //{알파벳, 합, 바꿀 숫자}

	//알파벳 초기화
	for (int i = 0; i < 26; i++) {
		digit[i][0] = i;
	}
	
	for (int i = 0; i < n; i++) {
		string s = word[i];
		for (int j = 0; j < s.size(); j++) {
			int n = (int)s[j] - 65;
			digit[n][0] = n;
			digit[n][1] += pow(10, s.size() - j - 1);
		}
	}
	return digit;
}

int getSum(int n, vector<string>& word) {
	//가장 높은 자리수을 가진 알파벳, 개수가 많은 알파벳 순으로 정렬
	vector<vector<int>> digit = getDigit(n, word); //{알파벳, 합, 바꿀 숫자}
	sort(digit.begin(), digit.end(), cmp1);
	
	//알파벳을 숫자로 바꾸기
	//0번째 숫자는 9로, 1번째 숫자는 8로, ...
	for (int i = 0; i < 10; i++) {
		digit[i][2] = 9 - i;
	}

	//다시 알파벳 순으로 정렬
	sort(digit.begin(), digit.end(), cmp2);

	//단어를 숫자로 바꾸기
	vector<string> word_num(n, "");
	for (int i = 0; i < n; i++) {
		string s = word[i];
		for (int j = 0; j < s.size(); j++) {
			int alphabet = (int)s[j] - 65;
			string num = to_string(digit[alphabet][2]);
			word_num[i] += num;
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += stoi(word_num[i]);
	}
	return result;
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
	cout << getSum(n, word);

	return 0;
}