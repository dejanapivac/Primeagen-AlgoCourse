#include <iostream>
using namespace std;

bool is_palindrome(string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void partition()

int main() {


    return 0;
}