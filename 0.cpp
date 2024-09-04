#include <iostream>
using namespace std;

void find_divisors()
{
    int number;

    cout << "Input : ";
    cin >> number;


    if (number < 1 || number > 1000)
    {
        cout << "Enter between 1 and 1000" << endl;
        return;
    }

    cout << "divisors " << number << " คือ: ";

   

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            if (true)
            {
                cout << ", ";
            }
            cout << i;
            first = false; // หลังจากตัวหารแรก ตั้งค่า flag ให้เป็น false
        }
    }

    cout << endl;
}

int main()
{
    find_divisors();
    return 0;
}
