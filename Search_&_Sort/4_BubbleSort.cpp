#include <iostream>
#include <vector>
using namespace std;

// MOJ NACIN - losiji
//void bubble_sort(vector<int>& arr) {
//    for(int i = 0; i < arr.size() - 1; ++i) {
//        for(int j = i + 1; j <= arr.size() - 1 - i; j++) {
//            int a = arr[i];
//            int b = arr[j];
//            if (arr[j] < arr[i]) {
//                int temp;
//                temp = arr[j];
//                arr[j] = arr[i];
//                arr[i] = temp;
//            }
//        }
//    }
//}

void bubble_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size() - 1 - i; ++j) {
            int temp;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}


int main() {
    vector<int> array = {5,1,4,2, 8, 9};
    for (int i: array) {
        cout << i;
    }
    cout << "\n";
    bubble_sort(array);
    for (int i: array) {
        cout << i;
    }
    cout << "\n";
}
