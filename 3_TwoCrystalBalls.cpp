#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int two_crystal_balls(vector<bool> breaks) {
    const int jumpAmount = floor(sqrt(breaks.size()));
    int i = jumpAmount;
    for (; i < breaks.size(); i += jumpAmount) {
        if (breaks[i]) {
            break;
        }
    }

//  i -= jumpAmount;

//    for (int j = 0; j <= jumpAmount && i < breaks.size(); ++j, ++i) {
//        if(breaks[i]) {
//            return i;
//        }
//    }

    for(int j = i - jumpAmount; j < i; ++j) {
        if(breaks[j]) {
            return j;
        }
    }

    return -1;
}

int main() {
    cout << two_crystal_balls({0,0,0,0,1,1,1,1,1,1});
}