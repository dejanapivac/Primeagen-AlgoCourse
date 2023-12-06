#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int lo, int hi) { // return pivot index
    int pivot = arr[hi];
    int idx = lo - 1;

    for (int i = lo; i < hi; ++i) {
        if (arr[i] <= pivot) {
            idx++;
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }

    idx++;
    arr[hi] = arr[idx];
    arr[idx] = pivot;

    return idx;
}

void qs(vector<int>& arr, int lo, int hi) {
    if(lo >= hi) {
        return;
    }

    int pivotIdx = partition(arr, lo, hi);
    qs(arr, lo, pivotIdx - 1);
    qs(arr, pivotIdx + 1, hi);
}

int main() {
    vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15};
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    qs(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}