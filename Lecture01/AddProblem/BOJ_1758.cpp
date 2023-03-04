#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int tip(vector<int>& people) {
	long long int result = 0, money;
	for (int i = 0; i < people.size(); i++) {
		money = people[i] - i;
		if (money > 0) {
			result += money;
		}
	}
	return result;
}

int main() {
	int n;

	//입력
	cin >> n;
	vector<int> people(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}

	//연산
	sort(people.rbegin(), people.rend());

	//출력
	cout << tip(people);

	return 0;
}