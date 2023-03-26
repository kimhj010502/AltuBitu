#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

int countMeeting(vector<ii>& meeting) { 
	int cnt = 0;
	int time = 0;

	//끝나는 시간, 시작 시간으로 회의 sort
	sort(meeting.begin(), meeting.end());

	for (int i = 0; i < meeting.size(); i++) {
		//현재 시간이 회의 시작 시간 이전인 경우
		if (time <= meeting[i].second) {
			cnt++;
			time = meeting[i].first;
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

	vector<ii> meeting(n); //회의 종료 시간, 시작 시간
	for (int i = 0; i < n; i++) {
		cin >> meeting[i].second >> meeting[i].first;
	}

	//연산 & 출력
	cout << countMeeting(meeting);

	return 0;
}