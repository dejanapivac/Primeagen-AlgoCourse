#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int> &arr, int lo, int hi) {    //gdje je pivot
    int pivot = arr[hi];
    int idx = lo - 1;   // ne mora biti -1, ali vecinom je??

    // sada moramo hodat od lo do hi, ali ne ukljuciti hi jer je on pivot
    for(int i = lo; i < hi; ++i) {
        if(arr[i] <= pivot) {
            idx++;  // sada nije -1 vec 0
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
    // base case
    if(lo >= hi) {
        return;
    }

    int pivotIdx = partition(arr, lo, hi);
    qs(arr, lo, pivotIdx - 1); //jedna strana polja
    qs(arr, pivotIdx + 1, hi); // druga strana polja
}


void quick_sort(vector<int> &arr) {
    qs(arr, 0, arr.size() - 1);
}

int main() {

    vector<int> arr = {5,7,2,1,8,9};

    for(int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<", ";
    }

    cout<<endl;

    quick_sort(arr);

    for(int i = 0; i < arr.size(); ++i) {
        cout<<arr[i]<<", ";
    }


    return 0;
}