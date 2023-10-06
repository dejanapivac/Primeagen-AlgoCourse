#include <iostream>
#include <vector>

using namespace std;

bool linear_search(vector<int> numbers, int number) {
    for(int i = 0; i <= numbers.size(); ++i) {
        if(numbers[i] == number) {
            return true;
        }
    }
    return false;
}

int main() {
    cout <<linear_search({1,2,5,4,3}, 5);
}