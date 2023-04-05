#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minWeight(int n, vector<int>& weight) {
	int sum_num = 0;

	sort(weight.begin(), weight.end()); //오름차순으로 정렬

	for (int i = 0; i < n; i++) {
		//새로 추가될 추의 무게가 이전의 모든 추의 무게 합보다 크다면 그 사이의 값들은 만들어지지 못함
		//ex) 1~a까지 다 만들어지고 새로운 추의 무게가 b인 경우 b+1~a+b까지도 만들 수 있는데
		//b > a인 경우에는 중간이 비어버리게 됨
		if (weight[i] > sum_num + 1) {
			break;
		}
		sum_num += weight[i];
	}
	return sum_num + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<int> weight(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	//연산 & 출력
	cout << minWeight(n, weight);

	return 0;
}