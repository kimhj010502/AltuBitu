#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	//학생들의 체육복 개수
	vector<int> student(n + 1, 1);
	for (int i = 0; i < lost.size(); i++) {
		student[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		student[reserve[i]]++;
	}

	for (int i = 1; i < n + 1; i++) {
		//체육복을 가지고 있으면 넘어감
		if (student[i] > 0) {
			continue;
		}
		
		//체육복이 없고 옆에서 빌릴 수 있는 경우
		if (student[i - 1] == 2) {
			student[i]++;
			student[i - 1]--;
			continue;
		}
		if (student[i + 1] == 2) {
			student[i]++;
			student[i + 1]--;
			continue;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		if (student[i] > 0) {
			answer++;
		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n = 5;
	vector<int> lost{ 2,4 };
	vector<int> reserve{ 1,3,5 };

	//연산 & 출력
	cout << solution(n, lost, reserve);

	return 0;
}