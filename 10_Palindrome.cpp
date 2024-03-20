#include <iostream>
using namespace std;

bool check_palindrome(string s, int i, int j) {
    if(i >= j) {
        return true; //rijec je palindrom
    } else if (s[i] == s[j]) {
        cout<<s[i]<<" "<<s[j]<<endl;
        return check_palindrome(s, i + 1, j - 1);
    } else {
        return false;
    }
}

bool is_palindrome(string s) {
    return check_palindrome(s, 0, s.length() - 1);
}

int main(){
    string s = "tsabbcacbbast";

    cout<<is_palindrome(s);

    return 0;
}