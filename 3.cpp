#include <iostream>
using namespace std;

void fine_not_multiples(int numStart,int numEnd)
{
    for (int i = numStart; i <= numEnd; i++){
            if (i % 3 != 0 && i % 4 != 0 && i % 5 != 0)
            {
                cout << i << " ";
            }
        }
}

int main()
{
int starts, ends;
    do
    {
        cout << "Enter Start : ";
        cin >> starts;
        cout << "Enter End : ";
        cin >> ends;
        fine_not_multiples(starts, ends);
        if (starts < 1 || ends > 1000 || starts > ends)
        {
            cout << "Enter 1 - 1000 agian and start value is less end value" << endl;
        }
    } while (starts < 1 || ends > 1000 || starts > ends);
}