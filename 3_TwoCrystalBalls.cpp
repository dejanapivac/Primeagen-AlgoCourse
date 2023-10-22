#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int two_crystal_balls(vector<bool> arr) {
    int jumpAmount = floor(sqrt(arr.size()));
    int i = jumpAmount;
    for(; i <= arr.size(); i += jumpAmount) {
        if(arr[i]) {
            break;
        }
    }

    for(int j = i - jumpAmount; j <= i; ++j) {
        if (arr[j]) {
            return j;
        }
    }

    return -1;
}

int main() {
    cout << two_crystal_balls({0,0,0,1,1,1,1,1});
}