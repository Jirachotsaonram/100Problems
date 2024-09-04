#include <iostream>
#include <iomanip>
using namespace std;


void calculate_sum_and_average(){
    float sum = 0, average, number;
    for(int i =1 ; i <= 5 ; i++){
        cout << "Enter number " << i << " : ";
        cin >> number;
        sum += number;
    }
    average = sum / 5;
    cout << fixed << setprecision(2) ;
    cout << "Sum = " << sum << "   Average = " << average;
}

int main()
{
    calculate_sum_and_average();
    return 0 ;
}