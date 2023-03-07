#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ci; //몇칸 돌렸는지, 어떤 알파벳인지
const int ALPHA = 26;

string arrowStartWheel(int index, int n, vector<char>& wheel) {
	string ans = "";

	for (int i = 0; i < n; i++) {
		ans += wheel[(i + index) % n];
	}
	return ans;
}

string makeWheel(int n, vector<ci>& record) {
	vector<char> wheel(n, '?');
	vector<bool> is_available(ALPHA, false);

	int index = 0;
	
	for (int i = 0; i < record.size(); i++) {
		int rot = record[i].first;
		int ch = record[i].second;

		index = (index - rot + 100 * n) % n; //화살표 인덱스

		if (wheel[index] == ch) { //비어있지 않지만, 글자가 같은 경우
			continue;
		}

		//비어있지 않으면서 이미 사용한 경우
		if (wheel[index] != '?' || is_available[ch - 'A']) {
			return "!";
		}

		wheel[index] = ch; //원판에 기록
		is_available[ch - 'A'] = true; //알파벳 중복 체크 기록
	}

	return arrowStartWheel(index, n, wheel);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;

	//입력
	cin >> n >> k;
	vector<ci> record(k, { 0,0 });
	for (int i = 0; i < k; i++) {
		cin >> record[i].first >> record[i].second;
	}

	//연산 & 출력
	cout << makeWheel(n, record);

	return 0;
}