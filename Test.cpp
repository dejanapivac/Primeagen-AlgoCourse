#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int lo, int hi) {
    int pivot = arr[hi];
    int idx = lo - 1;

    for (int i = 0; i < hi; ++i) {
        if (arr[i] <= pivot) {
            idx++;
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
    }

    idx++;
    arr[hi] = arr[idx];
    arr[idx] = pivot;

    return idx;
}

void qs(vector<int> &arr, int lo, int hi) {
    if(lo >= hi) {
        return;
    }

    int pivotIdx = partition(arr, lo, hi);
    qs(arr, lo, pivotIdx -1);
    qs(arr, pivotIdx)
}

void quick_sort(vector<int> &arr) {
    qs(arr, 0, arr.size() - 1);
}

int main() {


    return 0;
}