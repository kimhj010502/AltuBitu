#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 100000;

vector<int> getPrime() {
    vector<int> prime_num(MAX + 1, 0);

    for (int i = 2; i * i <= MAX; i++) {
        if (prime_num[i] != 0) { //소수가 아니면
            continue;
        }
        for (int j = i * 2; j <= MAX; j += i) {
            if (prime_num[j] == 0) { //값이 이미 채워져있지 않은 경우
                prime_num[j] = i;
            }
        }
    }
    return prime_num;
}

vector<int> factorization(int num, vector<int>& prime_num) {
    vector<int> v;
    while (prime_num[num] != 0) {
        v.push_back(prime_num[num]);
        num /= prime_num[num];
    }
    v.push_back(num);

    return v;
}

string advCalculate(vector<string>& input) {
    vector<int> result(MAX + 1, 0);
    vector<int> prime_num = getPrime();

    int check = 1;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == "*") {
            check = 1;
        }
        else if (input[i] == "/") {
            check = -1;
        }
        else {
            int num = stoi(input[i]);
            if (num == 0) {
                return "mint chocolate";
            }

            vector<int> v = factorization(num, prime_num);

            for (int i = 0; i < v.size(); i++) {
                result[v[i]] += check;
            }
        }
    }

    for (int i = 2; i < result.size(); i++) {
        if (result[i] < 0) {
            return "toothpaste";
        }
    }
    return "mint chocolate";
}

int gcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecur(b, a % b);
}

//수를 곱하는 과정에서 int의 범위를 넘어설 수 있음
string calculate(vector<string>& input) {
    vector<int> result(2); //곱과 나누는 수 저장
    result[0] = stoi(input[0]);
    result[1] = 1;
    int check = -1;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == "*") {
            check = 0;
        }
        else if (input[i] == "/") {
            check = 1;
        }
        else {
            result[check] *= stoi(input[i]);
            int gcd = gcdRecur(max(result[0], result[1]), min(result[0], result[1]));
            result[0] /= gcd; result[1] /= gcd;
        }
    }

    if (result[1] == 1) {
        return "mint chocolate";
    }
    return "toothpaste";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int n;
    cin >> n;
    vector<string> input(2 * n - 1);
    string num;
    for (int i = 0; i < 2 * n - 1; i++) {
        cin >> num;
        if (num[0] == '-') {
            input[i] = num.substr(1);
            continue;
        }
        input[i] = num;
    }

    //연산 & 출력
    cout << advCalculate(input);

    return 0;
}