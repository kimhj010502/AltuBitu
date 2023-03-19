#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//heap이 비어있는지 확인하는 함수
bool heapEmpty(vector<int>& heap) {
	return heap.size() == 1;
}

//heap에 x 삽입하는 함수
void heapPush(vector<int>& heap, int x) {
	//현재 heap의 크기 = 새로 push할 x의 초기 인덱스
	int idx = heap.size();

	//heap의 마지막 자리에 x 삽입
	heap.push_back(x);

	//부모 노드와 비교하면서 swap
	while (idx > 1 && heap[idx] > heap[idx / 2]) {
		swap(heap[idx], heap[idx / 2]);
		idx /= 2;
	}
}

//heap의 가장 큰 값을 출력하고 그 값을 제거하는 함수
int heapPop(vector<int>& heap) {
	//루트 노드 값을 복사함
	int top = heap[1];

	//가장 마지막의 값을 루트 노드에 옮김
	heap[1] = heap[heap.size() - 1];
	heap.pop_back();

	int size = heap.size();
	int parent = 1, child = 2;

	//자식 노드가 존재하는동안 비교 진행
	while (child < size) {
		//오른쪽 자식 노드가 존재한다면, 둘 중에 큰 값을 선택
		if (child + 1 < size && heap[child + 1] > heap[child]) {
			child += 1;
		}

		//부모 노드가 자식 노드보다 작은 경우 swap
		if (heap[parent] < heap[child]) {
			swap(heap[parent], heap[child]);
			parent = child;
			child = parent * 2;
		}
		//부모 노드가 자식 노드보다 큰 경우에는 더 이상 swap할 필요가 없음
		else {
			break;
		}
	}
	return top;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> pq;

	int x;
	while (n--) {
		cin >> x;
		if (x == 0) {
			//배열이 비어있는 경우 0 출력
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			//배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거함
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			//배열에 x값 추가
			pq.push(x);
		}
	}

	/*
	vector<int> heap;
	heap.push_back(0); //첫번째 쓰레기값 삽입

	int x;
	while (n--) {
		cin >> x;
		if (x == 0) {
			//배열이 비어있는 경우 0 출력
			if (heapEmpty(heap)) {
				cout << 0 << "\n";
			}
			//배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거함
			else {
				cout << heapPop(heap) << "\n";
			}
		}
		else {
			//배열에 x값 추가
			heapPush(heap, x);
		}
	}
	*/

	return 0;
}