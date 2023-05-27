#include <iostream>
#include <vector>

using namespace std;

//node에서 root까지 거슬러 올라가는 경로 벡터 반환
vector<int> getParent(int node, vector<int>& tree) {
	vector<int> parent;

	int next = node;
	//루트노드까지 탐색
	while (next != -1) {
		parent.push_back(next);
		next = tree[next];
	}
	return parent;
}

int getNCA(int node1, int node2, vector<int>& tree) {
	vector<int> parent1 = getParent(node1, tree);
	vector<int> parent2 = getParent(node2, tree);

	for (int i = 0; i < parent1.size(); i++) {
		for (int j = 0; j < parent2.size(); j++) {
			if (parent1[i] == parent2[j]) {
				return parent1[i];
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n, a, b, node1, node2;
	cin >> t;

	while (t--) {
		//입력
		cin >> n;

		vector<int> tree(n + 1, -1); //tree[i]: i의 부모 노드
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			tree[b] = a;
		}

		cin >> node1 >> node2;

		//연산 & 출력
		cout << getNCA(node1, node2, tree) << "\n";
	}

	return 0;
}