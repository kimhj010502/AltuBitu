#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    string name, state;
    set<string, greater<>> s; //내림차순 집합

    //입력 & 연산
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> state;
        if (state == "enter") {
            s.insert(name);
        }
        else {
            s.erase(name);
        }
    }

    //출력
    /*
    for (auto iter = s.begin(); iter != s.end(); iter++) { //r 붙여서 역순 출력 가능
        cout << *iter << '\n';
    }
    */

    for (auto iter : s) {
        cout << iter << '\n';
    }

    return 0;
}