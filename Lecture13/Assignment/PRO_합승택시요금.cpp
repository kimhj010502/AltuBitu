#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 2e7;

vector<vector<int>> fillGraph(int n, vector<vector<int>>& fares) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < fares.size(); i++) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    return graph;
}

void floyWarshall(int n, vector<vector<int>>& graph) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
                int dist = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], dist);
			}
		}
	}
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    vector<vector<int>> graph = fillGraph(n, fares);
    floyWarshall(n, graph);

    for (int i = 1; i <= n; i++) { //i번째 지점까지 합승
        //지금까지의 최단거리와 합승을 했을 때의 최단거리 비교
        //이동이 불가능한 경우는 INF이므로 min 조건에 의해 자동으로 고려되지 않음
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    return answer;
}

int main() {
    //입력
    int n = 6, s = 4, a = 6, b = 2;
    vector<vector<int>> fares = { {4,1,10}, {3,5,24}, {5,6,2}, {3,1,41}, {5,1,24}, {4,6,50}, {2,4,66}, {2,3,22}, {1,6,25} };

    //연산 & 출력
    cout << solution(n, s, a, b, fares);
}