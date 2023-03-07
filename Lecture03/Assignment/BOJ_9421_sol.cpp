#include <iostream>
#include <vector>
#include <set>

using namespace std;

//1. 소수 구하기
vector<bool> getPrime(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (!is_prime[i]) {
			continue;
		}
		//i의 배수 지우기
		for (int j = i * i; j <= n; j += i) {
			is_prime[j] = false;
		}
	}
	return is_prime;
}

//2. 상근수 구하기
int getSum(int n) {
	int total = 0; //각 자리수의 제곱의 합 저장
	int tmp; //일의 자리수 저장

	while (n != 0) {
		tmp = n % 10;
		total += tmp * tmp;
		n /= 10;
	}
	return total;
}

bool isValid(int n) {
	set<int> visited;
	//visited.insert(n);

	while (1) {
		n = getSum(n); //n의 각 자리수의 제곱의 합

		//n == 1 -> 상근수
		if (n == 1) {
			return true;
		}

		//이미 방문한 수이면 -> 상근수 X
		if (visited.find(n) != visited.end()) {
			return false;
		}

		visited.insert(n);
	}
}

vector<int> solution(int n) {
	vector<int> result; //n보다 작거나 같은 모든 소수상근수
	vector<bool> is_prime = getPrime(n);
	
	for (int i = 2; i <= n; i++) {
		//i가 소수이면서 상근수이면 i는 소수상근수
		if (is_prime[i] && isValid(i)) {
			result.push_back(i);
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산
	vector<int> result = solution(n);

	//출력
	for (auto iter : result) {
		cout << iter << "\n";
	}

	return 0;
}