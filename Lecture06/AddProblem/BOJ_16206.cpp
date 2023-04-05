#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//케이크의 길이가 10의 배수인 경우 자른 횟수에 비해 더 많은 케이크가 나옴
//둘 다 10의 배수인 경우 케이크의 길이가 짧은 것이 더 많이 나올 가능성이 있음 (예시: 30 vs 20)
//10의 배수 먼저, 길이가 짧은 케이크가 먼저 처리되도록 sort
bool cmp(int a, int b) {
	if (a % 10 == 0 && b % 10 == 0) {
		return a < b;
	}
	else if (a % 10 == 0 && b % 10 != 0) {
		return true;
	}
	else {
		return false;
	}
}

int countCake(vector<int>& a, int m) {
	int cut_cnt = 0;
	int total_cake = 0;
	int cake_cnt;
	bool multi_ten = false; //해당 케이크가 10의 배수인지 확인

	//10의 배수가 앞에 오도록 정렬
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < a.size(); i++) {
		//cout << a[i] << ": ";
		//해당 케이크를 잘랐을 때 생기는 길이가 10인 케이크의 개수
		cake_cnt = a[i] / 10;
		//전체 케이크 개수 업데이트
		total_cake += cake_cnt;

		//케이크의 길이를 10으로 나눈 나머지가 0이 아닌 경우
		if (a[i] % 10) {
			multi_ten = false;
			cut_cnt += cake_cnt;
		}
		//나머지가 0인 경우
		else {
			multi_ten = true;
			cut_cnt += cake_cnt - 1;
		}

		//cout << "케이크 개수: " << cake_cnt << ", 전체 케이크 개수: " << total_cake << ", 자른 횟수: " << cut_cnt << "\n";

		//자른 횟수가 m인 경우 바로 총 케이크의 개수 반환
		if (cut_cnt == m) {
			return total_cake;
		}
		else if (cut_cnt > m) {
			//방금 앞에 잘랐던 케이크가 10의 배수인 경우
			if (multi_ten) {
				return total_cake - (cut_cnt - m) - 1;
			}
			//10의 배수가 아닌 경우
			else {
				return total_cake - (cut_cnt - m);
			}
		}

	}

	//자를만큼 잘랐는데 m보다 작은 경우에도 total_cake 반환
	return total_cake;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//연산 & 출력
	cout << countCake(a, m);

	return 0;
}