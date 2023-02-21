#include <iostream>
#include <vector>

using namespace std;

//���� ���� O(n^2)
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

//���� ����: O(n^2)
void insertionSort(vector<int>& arr) {
    int curr, j;
    for (int i = 1; i < arr.size(); i++) {
        curr = arr[i]; //��ġ�� ã������ ����
        for (j = i - 1; j >= 0 && arr[j] > curr; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = curr;
    }
}

//���� ����: O(n^2)
void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//���� ���� ����: O(n^2)
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
        if (!is_swap) { //swap�� �� ���� �Ͼ�� �ʾҴٸ�
            return; //�̹� ��� ���Ұ� ���ĵǾ� �����Ƿ� �ٷ� ����
        }
    }
}

int main()
{
    //�Է�
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //����
    advBubbleSort(arr);

    //���
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}
