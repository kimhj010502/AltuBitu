#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//현재 시각에서 요청된 task 중 소요시간이 가장 적은 task를 우선으로 실행해야 함

//소요시간으로 sort
struct sortMinTime {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) { //요청시간, 소요시간
	int answer = 0;
	int curt_time = 0; //현재 시간
	int total_time = 0; //대기 시간
	int next_request_job = 0; //다음으로 요청되는 task 인덱스 번호
	int job_cnt = jobs.size(); //해야할 task 개수

	//소요시간이 작은 순으로 정렬해주는 우선순위 큐
	priority_queue<vector<int>, vector<vector<int>>, sortMinTime> pq;

	//task를 요청 시간이 작은 순으로 정렬
	sort(jobs.begin(), jobs.end());

	while (next_request_job < job_cnt || !pq.empty()) {

		//현재 요청된 task는 없지만 task가 남아 있는 경우
		//다음으로 요청되는 job 실행
		if (pq.empty()) {
			curt_time = jobs[next_request_job][0];
			pq.push(jobs[next_request_job++]);
		}

		//현재 요청된 task 중 소요시간이 가장 적은 task 수행
		vector<int> curt_job = pq.top();
		pq.pop();

		total_time += ((curt_time - curt_job[0]) + curt_job[1]); //(요청부터 실행까지 delay된 시간) + 소요 시간
		curt_time += curt_job[1];

		//현재 시간까지 요청된 task를 큐에 push
		while (next_request_job < job_cnt && jobs[next_request_job][0] <= curt_time) {
			pq.push(jobs[next_request_job++]);
		}
	}

	answer = int(total_time / job_cnt);
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 3;

	vector<vector<int>> jobs(3, vector<int>(2));
	for (int i = 0; i < 3; i++) {
		cin >> jobs[i][0] >> jobs[i][1];
	}

	cout << solution(jobs);

	return 0;
}