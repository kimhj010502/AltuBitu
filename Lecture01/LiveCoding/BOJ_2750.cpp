#include <iostream>
#include <vector>

using namespace std;

//선택 정렬 O(n^2)
void selectionSort(vector<int>& arr) {
    int least;
    for (int i = 0; i < arr.size() - 1; i++) {
        least = i;
        for (int j = i + 1; j < arr.size(); i++) {
            if (arr[j] < arr[least]) {
                least = j;
            }
        }
        swap(arr[i], arr[least]);
    }
}

//삽입 정렬: O(n^2)
void insertionSort(vector<int>& arr) {
    int curr, j;
    for (int i = 1; i < arr.size(); i++) {
        curr = arr[i]; //위치를 찾으려는 원소
        for (j = i - 1; j >= 0 && arr[j] > curr; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = curr;
    }
}

//버블 정렬: O(n^2)
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//향상된 버블 정렬: O(n^2)
void advBubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool is_swap = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    is_swap = true;
                }
            }
        }
        if (!is_swap) { //swap이 한 번도 일어나지 않았다면
            return; //이미 모든 원소가 정렬되어 있으므로 바로 리턴
        }
    }
}

int main()
{
    //입력
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    advBubbleSort(arr);

    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
