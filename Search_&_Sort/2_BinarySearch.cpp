#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int> arr, int number){
    int low = 0;
    int high = arr.size();
    // logn
    do{
        int mid = low + ((high - low)/2);
        int value = arr[mid];
        if(value == number) {
            return true;
        } else if(value < number) {
            low = mid + 1;
        } else {
            high = mid;
        }
    } while (low < high);

    return false;
}

int main() {
    cout << binary_search({1,2,3,4,5,6,7,8,9}, 20);
}