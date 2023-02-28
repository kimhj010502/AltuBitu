#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

queue<int> calculateTime(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); i++) {
        int time = ceil((100 - progresses[i]) / floor(speeds[i]));
        q.push(time);
    }

    return q;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q = calculateTime(progresses, speeds);

    while (!q.empty()) {
        int day = q.front();
        int count = 1;
        q.pop();

        while (!q.empty() && day >= q.front()) {
            count++;
            q.pop();
        }

        answer.push_back(count);
    }

    return answer;
}

int main() {

    //입력
    int t;
    cin >> t;

    vector<int> progresses(t);
    vector<int> speeds(t);

    for (int i = 0; i < t; i++) {
        cin >> progresses[i];
    }

    for (int i = 0; i < t; i++) {
        cin >> speeds[i];
    }

    //연산
    vector<int> result = solution(progresses, speeds);

    //출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}