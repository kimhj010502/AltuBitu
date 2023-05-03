#include <iostream>
#include <deque>

using namespace std;

struct info {
	int power; //내구도
	bool is_on; //로봇 존재 여부
};

//1단계: 벨트 한 칸 회전
void rotateBelt(int n, deque<info>& belt) {
	belt.push_front(belt.back()); //가장 마지막 원소를 앞에 추가
	belt.pop_back();
	belt[n - 1].is_on = false; //로봇 내리는 위치에서 로봇 내림
}

//2단계: 로봇을 움직일 수 있으면 한 칸 이동
void moveRobot(int n, deque<info>& belt) {
	for (int i = n - 2; i >= 0; i--) {
		//현재 위치에 로봇이 없고 이전 위치에 로봇이 있으며 내구도가 0보다 큰 경우 로봇 옮김
		if (belt[i].is_on && !belt[i + 1].is_on && belt[i + 1].power > 0) {
			belt[i].is_on = false;
			belt[i + 1].is_on = true;
			belt[i + 1].power--;
		}
	}
	belt[n - 1].is_on = false; //로봇 내리는 위치에서 로봇 내림
}

//3단계: 올리는 칸에 로봇을 올릴 수 있으면 올림
void putRobot(deque<info>& belt) {
	if (belt[0].power > 0) {
		belt[0].is_on = true;
		belt[0].power--;
	}
}

//4단계: 종료 조건 확인
bool checkFinish(int n, int k, deque<info>& belt) {
	int count = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (belt[i].power == 0) {
			count++;
		}
	}

	if (count >= k) {
		return true;
	}
	return false;
}

int solution(int n, int k, deque<info>& belt) {
	int step = 1;
	while (true) {
		//1단계
		rotateBelt(n, belt);

		//2단계
		moveRobot(n, belt);

		//3단계
		putRobot(belt);

		//내구도 체크
		if (checkFinish(n, k, belt)) {
			return step;
		}
		step++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	deque<info> belt(2 * n); //컨베이어 벨트의 내구도와 로봇 존재 여부 저장
	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i].power;
		belt[i].is_on = false;
	}
	
	//연산 & 출력
	cout << solution(n, k, belt);

	return 0;
}