#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <string>

using namespace std;

class BigDecimalInt
{
    public:
        BigDecimalInt();
        BigDecimalInt(string decStr);
        BigDecimalInt(int decInt);
        virtual ~BigDecimalInt();
        string changeInt(int integer);
        int intSize(int integer);
        BigDecimalInt operator+ (BigDecimalInt anotherDec);
        BigDecimalInt operator- (BigDecimalInt anotherDec);
        int Size();
        string getNumber();
        string reverseString(string txt);
        string addZeros(string str1, string str2);
        BigDecimalInt operator= (BigDecimalInt anotherDec);
        friend ostream& operator << (ostream& out, BigDecimalInt& b);
        friend istream& operator >> (istream& in, BigDecimalInt& b);

    private:
        string number;
        bool isPositive;
};

#endif // BIGDECIMALINT_H
