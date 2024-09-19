#include <iostream>
using namespace std;
int fine_divisors(){
    int number;
    cout << "Input:";
    cin >> number;
    if(number > 1){
        for(int i=2 ; i < number ; i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;
    }else return false;
}
int main(){
    if(fine_divisors()){
        cout << "is prime";
    }else cout << "is not prime";
    return 0;
}