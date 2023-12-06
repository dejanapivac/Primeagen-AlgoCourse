#include <iostream>
using namespace std;

int recursive_sum(int a, int b) {
    // base case
    if(a == b){
        return a;
    }

    return a + recursive_sum(a + 1, b);
}

int main(){
    int a = 10, b = 20, sum = 0;

//    for(int i = a; i <= b; ++i) {
//        sum += i;
//    }
//    cout<< sum;

    cout<<"Sum = "<<recursive_sum(a,b);

    return 0;
}