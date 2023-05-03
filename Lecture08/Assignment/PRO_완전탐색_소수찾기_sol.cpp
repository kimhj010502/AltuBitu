#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 7;
const int MAX_VAL = 1e8;

int n;
int answer = 0;

vector<int> nums(MAX_N);
vector<int> is_counted(MAX_VAL); //이미 센 숫자인지 확인
vector<bool> is_used(MAX_N); //해당 종이 조각이 사용된적이 있는지 확인

//소수인지의 여부 리턴
bool isPrime(int x) {
	if (x < 2) {
		return false;
	}
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

//cnt: 현재까지 뽑은 종이 조각 개수
//val: 현재까지 뽑은 종이 조각으로 만든 수
void backtrack(int cnt, int val) {
	//현재까지 만든 수가 소수인지 체크
	if (cnt > 0 && isPrime(val) && !is_counted[val]) {
		answer++;
		is_counted[val] = true;
	}

	//재귀호출 종료 조건
	if (cnt == n) {
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_used[i]) {
			continue;
		}

		//사용
		is_used[i] = true;
		
		//다음 숫자
		backtrack(cnt + 1, val * 10 + nums[i]);

		//반납
		is_used[i] = false;
	}
}

int solution(string numbers) {
	//각 숫자 저장
	n = numbers.size();
	for (int i = 0; i < n; i++) {
		nums[i] = numbers[i] - '0';
	}

	//연산
	backtrack(0, 0);

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	string numbers;
	cin >> numbers;

	//연산 & 출력
	cout << solution(numbers);

	return 0;
}