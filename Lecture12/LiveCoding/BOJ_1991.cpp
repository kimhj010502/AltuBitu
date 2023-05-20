#include <iostream>
#include <map>

using namespace std;

map<char, pair<char, char>> tree;

//전위 순회: root -> left -> right
void preOrder(char root) {
	if (root == '.') {
		return;
	}

	cout << root;
	preOrder(tree[root].first);
	preOrder(tree[root].second);
}

//중위 순회: left -> root -> right
void inOrder(char root) {
	if (root == '.') {
		return;
	}

	inOrder(tree[root].first);
	cout << root;
	inOrder(tree[root].second);
}

//후위 순회: left -> right -> root
void postOrder(char root) {
	if (root == '.') {
		return;
	}

	postOrder(tree[root].first);
	postOrder(tree[root].second);
	cout << root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	char root, left, right;
	for (int i = 0; i < n; i++) {
		cin >> root >> left >> right;
		tree[root] = { left, right };
	}

	//연산 & 출력
	//전위 순회
	preOrder('A');
	cout << "\n";

	//중위 순회
	inOrder('A');
	cout << "\n";

	//후위 순회
	postOrder('A');

	return 0;
}