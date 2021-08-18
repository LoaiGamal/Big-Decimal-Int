#include "BigDecimalInt.h"
#include <iostream>
#include <string>
using namespace std;
BigDecimalInt::BigDecimalInt(string decStr){
    if(decStr[0]=='-')
        isPositive = false;
    else
        isPositive = true;
    number = decStr;
}
BigDecimalInt::BigDecimalInt(){}

BigDecimalInt::BigDecimalInt(int decInt){
    string str = changeInt(decInt);
    number = str;
}

BigDecimalInt::~BigDecimalInt()
{

}

string BigDecimalInt::changeInt(int integer){
    int mod = 0;
    int s = intSize(integer);
    string ch = "";
    string str="";
    if(integer<0){
        str+='-';
    }
    for(int i=0; i<s; i++){
        mod = abs(integer%10);
        ch += char(mod+48);
        integer/=10;
    }

    return reverseString(ch);

    /*for (int j=s-1;j>=0;j--)
    {
        str +=ch[j];
    }
    return str;*/
}

int BigDecimalInt::intSize(int integer){
    integer = abs(integer);
    int s=0;
    while(integer>0){
        s++;
        integer/=10;
    }
    return s;
}

BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec)
{
    bool carry = false;
    string finalResult = "";
    string str = "";
    string zeros = addZeros(number,anotherDec.number);
    BigDecimalInt result("");



    if(isPositive&&anotherDec.isPositive){
        if(number.size()>anotherDec.number.size()){
            anotherDec.number = zeros+anotherDec.number;
        }else{
                number = zeros+number;
        }
        for(int i=number.size()-1; i>=0; i--)
        {
            int value = ((int)number[i]+(int)anotherDec.number[i])-(48*2);
            if(carry){value++;}
            if(value>9){
                carry=true;
            }
            else{
                carry=false;
            }
            int mod = value%10;
            str += (char)mod+48;
        }
        str = reverseString(str);
        return BigDecimalInt(str);
    }else if(isPositive && !anotherDec.isPositive){
        anotherDec.number.erase(anotherDec.number.begin()+0);

        BigDecimalInt obj1 (number);
        BigDecimalInt obj2 (anotherDec.number);

        result = obj1-obj2;
        return result;
    }else if(!isPositive && anotherDec.isPositive){
        number.erase(number.begin()+0);

        BigDecimalInt obj1 (number);
        BigDecimalInt obj2 (anotherDec.number);

        result = obj1-obj2;
        return result;
    }else if(!isPositive&&!anotherDec.isPositive){
        number.erase(number.begin()+0);
        anotherDec.number.erase(anotherDec.number.begin()+0);



        BigDecimalInt obj1 (number);
        BigDecimalInt obj2 (anotherDec.number);

        result = obj1+obj2;
        str+='-';
        str+=result.number;
        return BigDecimalInt(str);
    }
}


BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec)
{
    string finalResult = "";
    string str = "";
    string zeros = addZeros(number,anotherDec.number);
    BigDecimalInt result("");
    int digit=0;
    int anotherDigit=0;



    if(isPositive&&anotherDec.isPositive){
        if(number.size()>anotherDec.number.size()){
            anotherDec.number = zeros+anotherDec.number;
        }else{
                number = zeros+number;
        }
        for(int i=number.size()-1; i>=0; i--)
        {
            int value = 0;
            digit = (int)number[i]-48;
            anotherDigit = (int)anotherDec.number[i]-48;

            /*if (number[i]<anotherDec.number[i])
            {
                if (i>0 && number[i-1] > '0')
                {
                    number[i-1]--;
                    digit += 10;
                }
                else
                {

                }

            }*/
            value = abs(digit-anotherDigit);
            /*if(carry){value++;}
            if(value>9){
                carry=true;
            }
            else{
                carry=false;
            }*/
            int mod = value%10;
            str += (char)mod+48;
            if (number < anotherDec.number)
                str+='-';
        }
        str = reverseString(str);
        return BigDecimalInt(str);
    }else if(isPositive && !anotherDec.isPositive){
        anotherDec.number.erase(anotherDec.number.begin()+0);

        BigDecimalInt obj1 (number);
        BigDecimalInt obj2 (anotherDec.number);

        result = obj1+obj2;
        return result;

    }else if(!isPositive && anotherDec.isPositive){
        number.erase(number.begin()+0);

        BigDecimalInt obj1 (number);
        BigDecimalInt obj2 (anotherDec.number);

        result = obj1+obj2;
        str+='-';
        str+=result.number;
        return BigDecimalInt(str);
    }else if(!isPositive&&!anotherDec.isPositive){
        number.erase(number.begin()+0);
        anotherDec.number.erase(anotherDec.number.begin()+0);



        BigDecimalInt obj1 (number);
        BigDecimalInt obj2 (anotherDec.number);

        result = obj1-obj2;
        str+=result.number;
        return BigDecimalInt(str);
    }
}

string BigDecimalInt::reverseString(string txt){
    string temp = "";
    for(int i=txt.size()-1; i>=0; i--){
        temp += txt[i];
    }
    return temp;
}

string BigDecimalInt::addZeros(string str1, string str2){
    int minimum = min(str1.size(), str2.size());
    int maximum = max(str1.size(), str2.size());
    int difference = maximum - minimum;
    string zeros = "";

    for(int i=0; i<difference; i++){
        zeros+='0';
    }

    return zeros;
}
BigDecimalInt BigDecimalInt:: operator= (BigDecimalInt anotherDec)
{
    number = anotherDec.number;
    return *this;
}


ostream& operator << (ostream& out, BigDecimalInt& b)
{
    out << b.number;
    return out;
}
istream& operator >> (istream& in, BigDecimalInt& b)
{
    in >> b.number;
    return in;
}


