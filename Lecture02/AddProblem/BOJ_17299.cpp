#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 1000000;

//F를 계산하는 함수
stack<pair<int, int>> calF(vector<int>& a) {
	vector<int> m(MAX + 1); //F(A)
	for (int i = 0; i < a.size(); i++) {
		m[a[i]]++;
	}
	stack<pair<int, int>> f; //A, F값을 역순으로 담은 스택
	for (int i = 0; i < a.size(); i++) {
		f.push({ a[i], m[a[i]] });
	}
	return f;
}

//NGF 계산하는 함수
stack<int> calNGF(vector<int>& a) {
	stack<pair<int, int>> f = calF(a); //<A, F(A)>
	stack<pair<int, int>> s;
	stack<int> ngf;
	while (!f.empty()) { //모든 <A, F>에 대해서 연산을 끝낼 때까지 반복
		//s가 비어있으면 A의 오른쪽에 있으면서 F가 큰 수가 없는 경우
		if (s.empty()) { 
			//-1을 넣고 f에 있는 수를 s로 옮김
			ngf.push(-1); 
			s.push(f.top()); 
			f.pop();
			continue;
		}
		
		//s에 있는 A의 F가 f에 있는 A의 F보다 큰 경우
		//s.top()은 A의 오른쪽에 있으면서 F가 큰 수 중에서 가장 왼쪽에 있는 수
		if (s.top().second > f.top().second) {
			//그 수의 A를 넣고 f에 있는 수를 s로 옮김
			ngf.push(s.top().first); 
			s.push(f.top());
			f.pop();
		}
		//s에 있는 A의 F가 f에 있는 A의 F보다 작거나 같은 경우
		else {
			//F가 더 큰 수가 나올 때까지 s의 원소 제거
			s.pop();
		}
	}
	return ngf;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//연산
	stack<int> ngf = calNGF(a);

	//출력
	while (!ngf.empty()) {
		cout << ngf.top() << " ";
		ngf.pop();
	}

	return 0;
}