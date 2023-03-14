#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> arr;
int dr[2] = { 1,0 };
int dc[2] = { 0,1 };

//인접한 사탕의 최대 개수를 구하는 함수
int countCandy(int row, int col, int dir) {
	int result = 0, cnt = 0;
	char prev = ' '; //직전의 사탕

	for (int i = 0; i < n; i++) {
		//직전의 사탕과 종류가 같다면 cnt 증가하고 result에 최대 cnt값 저장
		if (prev == arr[row][col]) {
			cnt++;
			result = max(result, cnt);
		}
		else {
			cnt = 1; //1로 갱신
			prev = arr[row][col];
		}
		//다음에 탐색할 사탕의 좌표 행과 열 구하기
		row += dr[dir];
		col += dc[dir];
	}
	return result;
}

//행, 열 방향으로 인접한 사탕의 최대 개수를 탐색하는 함수
int findCandy() {
	int result = 0;

	for (int i = 0; i < n; i++) {
		result = max(result, countCandy(0, i, 0)); //같은 열
		result = max(result, countCandy(i, 0, 1)); //같은 행
	}
	return result;
}

//사탕의 위치를 바꾸면서 최댓값을 계산하는 함수
int switchCandy(int row, int col, char candy) {
	int result = 0;

	for (int i = 0; i < 2; i++) {
		int nr = row + dr[i], nc = col + dc[i]; //인접한 사탕의 좌표 (앞으로 가야할 좌표)
		
		//사탕의 색이 다른 인접한 두 칸을 골라서 교환함
		//여러 경우 중에서 최댓값을 result에 저장
		if (nr < n && nc < n && candy != arr[nr][nc]) {
			swap(arr[row][col], arr[nr][nc]);
			result = max(result, findCandy());
			swap(arr[row][col], arr[nr][nc]); //원상복구
		}

	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n;
	arr.assign(n, "");
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//연산
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, switchCandy(i, j, arr[i][j]));
		}
	}

	//출력
	cout << answer;

	return 0;
}