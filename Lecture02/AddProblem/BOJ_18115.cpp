#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> initCard(vector<int>& a) {
	deque<int> result;

	int card = 1, f;
	for (int i = 0; i < a.size(); i++) {
		switch (a[i]) {
		case 1:
			result.push_front(card);
			break;
		case 2:
			f = result.front();
			result.pop_front();
			result.push_front(card);
			result.push_front(f);
			break;
		case 3:
			result.push_back(card);
			break;
		}
		card++;
	}

	return result;
}

int main() {
	//입력
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[n - i];
	}

	//연산
	deque<int> result = initCard(a);

	//출력
	while (!result.empty()) {
		cout << result.front() << " ";
		result.pop_front();
	}

	return 0;
}