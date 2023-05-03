#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;

const int DO = 0, SU = 1;

//수연이와 도도가 종을 치는 조건이 되는지 확인
int bellCheck(cards& deck, cards& ground) {
	//가장 위의 카드 중 5가 있는 경우 도도가 종을 침
	if ((!ground[DO].empty() && ground[DO].front() == 5) || (!ground[SU].empty() && ground[SU].front() == 5)) {
		return DO;
	}

	//두 그라운드가 비어있지 않고 두 카드의 합이 5가 되는 경우 수연이가 종을 침
	if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) {
		return SU;
	}

	//종을 칠 수 없는 경우
	return -1;
}

//그라운드에 있는 카드를 자신의 카드 더미로 옮기는 함수
void moveCard(deque<int>& deck, deque<int>& ground) {
	while (!ground.empty()) {
		deck.push_back(ground.back());
		ground.pop_back();
	}
}

//벨을 울린 경우 카드를 옮기는 함수
void ringBell(int player, cards& deck, cards& ground) {
	//상대방 그라운드에 있는 카드 가져오기
	moveCard(deck[player], ground[!player]);

	//자신의 그라운드에 있는 카드 가져오기
	moveCard(deck[player], ground[player]);
}

//승리 판단하는 함수
string judge(cards& deck) {
	if (deck[DO].size() > deck[SU].size()) {
		return "do";
	}
	else if (deck[DO].size() < deck[SU].size()) {
		return "su";
	}
	else {
		return "dosu";
	}
}

string game(int m, cards& deck, cards& ground) {
	bool turn = DO; //도도 먼저

	//m번동안 반복
	while (m--) {
		//1) 그라운드에 가장 위에 있는 카드 내려놓기
		ground[turn].push_front(deck[turn].front());
		deck[turn].pop_front();

		//2) 카드가 0개가 되었는지 검사하고 맞다면 바로 종료
		if (deck[turn].empty()) {
			break;
		}

		//3) 종치는 조건 검사하고 카드 이동
		int bell = bellCheck(deck, ground);
		if (bell != -1) {
			ringBell(bell, deck, ground);
		}

		turn = !turn; //차례 바꾸기
	}

	//더 많은 카드를 가진 사람이 이김
	return judge(deck);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, c1, c2;
	cin >> n >> m;

	//front(): 카드 더미 중 가장 위, back(): 카드 더미 중 가장 아래
	cards deck(2), ground(2); //0: 도도, 1: 수연

	while (n--) {
		cin >> c1 >> c2; //도도, 수연의 카드
		deck[DO].push_front(c1);
		deck[SU].push_front(c2);
	}

	//연산 & 출력
	cout << game(m, deck, ground);

	return 0;
}