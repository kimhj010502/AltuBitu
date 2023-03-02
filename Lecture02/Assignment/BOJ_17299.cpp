#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

map<int, int> calF(vector<int>& a) { //F를 구하는 함수
	map<int, int> m;
	for (int i = 0; i < a.size(); i++) {
		m[a[i]]++;
	}
	return m;
}

vector<int> calNGF(vector<int>& a, const int& n) {
	map<int, int> m = calF(a); //<A, F(A)>
	vector<int> ngf(n);

	vector<int> f(n); //F(A1), ... , F(An)로 이루어진 배열
	for (int i = 0; i < n; i++) {
		f[i] = m[a[i]];
	}

	stack<int> s; //F가 더 큰 A를 담은 스택
	ngf[n - 1] = -1; //가장 마지막 값은 항상 -1
	s.push(a[n - 1]); //처음에는 F값이 가장 큰 A가 마지막 A임

	int index = n - 2; //index를 마지막에서 두번째로 지정해주고 하나씩 줄여나가면서 NGF 구함
	
	while (!s.empty() && f[index] > m[s.top()]) {
		s.pop();
	}

	
	
	while (!s.empty()) { //스택에 값이 있을 동안 반복
		while (f[index] > m[s.top()]) {
			s.pop();
		}



		if (f[index] < m[s.top()]) { //현재 F값보다 스택에 있는 A의 F값이 큰 경우
			ngf[index] = s.top(); //현재 인덱스에 해당하는 NGF값은 s.top()임
			s.push(a[index--]); //앞의 F보다 클 수 있으므로 스택에 저장
		}
		else { //현재 F값보다 스택에 있는 A의 F값이 작거나 같은 경우
			s.pop(); //이전에 스택에 저장해둔 값은 이제 쓰일 일이 없으므로 삭제
			if (!s.empty()) { //스택이 비어있지 않다면
				ngf[index--] = s.top(); //이전의 값 복사
			}
			s.push(a[index--]); //같을때?
		}
	}

	while (index >= 0) { //스택에 값이 없어지면 나머지는 모두 -1로 채워짐
		ngf[index--] = -1;
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
	vector<int> ngf = calNGF(a, n);

	//출력
	for (int i = 0; i < n; i++) {
		cout << ngf[i] << " ";
	}

	return 0;
}