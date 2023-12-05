#include <iostream>
#include <vector>

using namespace std;

void qs(vector<int> arr, int lo, int hi) {

}

int partition(vector<int> arr, int lo, int hi) { // return pivot index
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
}

int main() {

    return 0;
}