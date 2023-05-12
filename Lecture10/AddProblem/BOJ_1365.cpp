#include <iostream>
#include <vector>

using namespace std;

//오름차순 result 벡터에서 number가 들어갈 수 있는 위치 반환
int searchPos(int number, int right, vector<int>& result) {
	int left = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (number > result[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

int minWire(int n, vector<int>& num) {
	vector<int> result(n); //오름차순 수열을 저장한 벡터
	result[0] = num[0];
	int position = 0; //숫자를 넣을 위치
	
	for (int i = 1; i < n; i++) {
		//result의 마지막 숫자보다 number가 큰 경우
		if (num[i] > result[position]) {
			result[++position] = num[i];
			continue;
		}
		result[searchPos(num[i], position, result)] = num[i];
	}
	return n - position - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	//연산 & 출력
	cout << minWire(n, num);

	return 0;
}