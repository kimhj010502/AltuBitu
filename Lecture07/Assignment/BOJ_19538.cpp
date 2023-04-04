#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getTime(int n, int m, vector<vector<int>>& people, vector<int>& start) {
	vector<int> time(n + 1, -1);
	vector<int> cnt(n + 1, 0); //루머를 믿는 주변 사람 수
	queue<int> q;

	//최초 유포자 q에 넣기
	for (int i = 0; i < m; i++) {
		q.push(start[i]);
		time[start[i]] = 0;
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();
		
		for (int i = 0; i < people[p].size(); i++) {
			int next_p = people[p][i];
			cnt[next_p]++;

			//주변인의 절반 이상이 루머를 믿는 아직 루머를 믿지 않은 사람인 경우 루머를 믿게 됨
			if (time[next_p] == -1 && cnt[next_p] >= (people[next_p].size() / 2.0)) {
				time[people[p][i]] = time[p] + 1;
				q.push(next_p);
			}
		}
	}
	return time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, p, m;
	cin >> n;

	vector<vector<int>> people(n + 1, vector<int>());
	for (int i = 1; i <= n; i++) {
		while (true) {
			cin >> p;
			if (p == 0) {
				break;
			}
			people[i].push_back(p);
		}
	}

	cin >> m;
	vector<int> start(m);
	for (int i = 0; i < m; i++) {
		cin >> start[i];
	}

	//연산
	vector<int> result = getTime(n, m, people, start);

	//출력
	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}