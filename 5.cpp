#include <iostream>
using namespace std;

void find_divisors()
{
    int number;
    cout << "Input : ";
    cin >> number;
    do
    {
        for (int i = 1; i <= number; i++)
        {
            if (number % i == 0)
            {
                if(true){
                    cout << ",";
                }
                cout << i;
            }
           
        }
        if (number < 1 || number > 1000)
        {
            cout << "\nbetween 1 and 1000" << endl;
        }
    }while(number < 1 || number > 1000);
}

int main()
{
    find_divisors();
    return 0;
}