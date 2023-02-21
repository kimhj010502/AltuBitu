#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    string name, state;
    set<string, greater<>> s; //�������� ����

    //�Է� & ����
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

    //���
    /*
    for (auto iter = s.begin(); iter != s.end(); iter++) { //r �ٿ��� ���� ��� ����
        cout << *iter << '\n';
    }
    */

    for (auto iter : s) {
        cout << iter << '\n';
    }

    return 0;
}