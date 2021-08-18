#include <iostream>
#include <BigDecimalInt.h>
using namespace std;

bool validation(string decStr)
{
    if((decStr[0]>'0' && decStr[0]<'9') || decStr[0]=='-'){
            for(int i=1;i<decStr.length();i++)
            {
                if(decStr[i]<'0' && decStr[i]>'9'){
                    return false;
                }
            }
            return true;
    }

}

void menu ()
{
    cout << "Welcome to FCI Calculator\n";
    cout << "----------------------------------------\n";
    cout << "1- Perform Addition\n";
    cout << "2- Perform Subtraction\n";
    cout << "3- Exit\n";
}

void setData(BigDecimalInt &num1,BigDecimalInt &num2)
{
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

}

int main()
{
    int operation;
    BigDecimalInt num1,num2,num3;

    while (true)
    {
        menu();
        cin >> operation;
        switch (operation)
        {
        case 1:
            setData(num1,num2);
            num3 = num1 + num2;
            cout << "num1 + num2 = " << num3 << endl;
            break;
        case 2:
            setData(num1,num2);
            num3 = num1 - num2;
            cout << "num1 - num2 = " << num3 << endl;
            break;
        case 3:
            return 0;
        default:
            cout << "Wrong choice.\n";
        }
    }
    return 0;
}
