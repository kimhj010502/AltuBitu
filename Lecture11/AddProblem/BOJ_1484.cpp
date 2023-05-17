#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getWeight(int g) {
	vector<int> weight; 
	
	int right = sqrt(g);//현재 몸무게
	int left = 1; //기억하고 있던 몸무게

	while (true) {
		int diff = pow(right, 2) - pow(left, 2);

		//두 몸무게 제곱의 차가 g인 경우 현재 몸무게를 wieght 벡터에 추가
		if (g == diff) {
			weight.push_back(right);
			right++; left++;
		}
		//g가 diff보다 큰 경우 right을 증가시켜 diff를 크게 만듦
		else if (g > diff) {
			right++;
		}
		//g가 diff보다 작은 경우 left을 증가시켜 diff를 작게 만듦
		else if (g < diff) {
			//right과 left가 1 차이나는데 diff가 더 커진경우 차가 g를 만족하는 수가 더이상 없으므로 종료
			if (right - left == 1) {
				break;
			}
			left++;
		}
	}
	return weight;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int g;
	cin >> g;

	//연산
	vector<int> weight = getWeight(g);

	//출력
	if (weight.size() == 0) {
		cout << -1;
	}
	else {
		for (int i = 0; i < weight.size(); i++) {
			cout << weight[i] << "\n";
		}
	}

	return 0;
}