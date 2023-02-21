#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sorted; //정렬 과정에서 사용한 부분적으로 정렬된 배열

//합병 정렬 (합병)
void merge(vector<int>& arr, int left, int mid, int right) {
    int pl = left, pr = mid + 1, idx = left;
    while (pl <= mid && pr <= right) {
        if (arr[pl] < arr[pr]) {
            sorted[idx++] = arr[pl++];
        }
        else {
            sorted[idx++] = arr[pr++];
        }
    }
    while (pl <= mid) {
        sorted[idx++] = arr[pl++];
    }
    while (pr <= right) {
        sorted[idx++] = arr[pr++];
    }
    for (int i = left; i <= right; i++) {
        arr[i] = sorted[i];
    }
}

//합병 정렬 (분할): O(nlog2n)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    //입력
    int n;
    cin >> n;
    vector<int> arr(n);
    //sorted.assign(n, 0); //sorted 벡터에 0을 n번 넣음
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    //mergeSort(arr, 0, n - 1);
    sort(arr.begin(), arr.end());

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}