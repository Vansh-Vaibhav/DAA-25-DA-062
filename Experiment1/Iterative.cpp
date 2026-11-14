
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left,
           int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int n) {

    // Start with subarrays of size 1
    for (int curr_size = 1; curr_size < n;
         curr_size = 2 * curr_size) {

        // Pick starting point of left subarray
        for (int left = 0; left < n - 1;
             left += 2 * curr_size) {

            int mid = min(left + curr_size - 1, n - 1);

            int right = min(left + 2 * curr_size - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int main() {

    vector<int> arr = {38, 27, 43, 10};

    int n = arr.size();

    cout << "Before:" << endl;

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    mergeSort(arr, n);

    cout << "\nAfter:" << endl;

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;

    cout << "Vansh Vaibhav CSDA 25/DA/062";

    return 0;
}
