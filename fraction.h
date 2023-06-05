#include <iostream>
using namespace std;

class fraction
{
private:
    int HCF()
    {
        int n = abs(numerator);
        int d = abs(denominator);
        int hcf = 1;
        for (int i = 1; i <= min(n, d); i++)
        {
            if ((n % i == 0) and (d % i == 0))
            {
                hcf = i;
            }
        }
        return hcf;
    }

    int numerator, denominator;

public:
    fraction(){};
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    fraction(fraction &object)
    {
        denominator = object.denominator;
        numerator = object.numerator;
    };

    void reduce()
    {
        int hcf = HCF();
        numerator = numerator / hcf;
        denominator = denominator / hcf;
    }

    void print()
    {
        cout << numerator << " / " << denominator << endl;
    }

    void operator+(fraction &object)
    {
        int max;
        int min;
        fraction ans;
        if (denominator > object.denominator)
        {
            max = denominator;
            min = object.denominator;
        }
        else
        {
            max = object.denominator;
            min = denominator;
        }
        if (max % min == 0)
        {
            int multiple = max / min;
            if (object.denominator == min)
            {
                int n = object.numerator * multiple;
                ans.numerator = n + numerator;
                ans.denominator = max;
            }
            else
            {
                int n = numerator * multiple;
                ans.numerator = n + object.numerator;
                ans.denominator = max;
            }
        }
        else
        {
            ans.numerator = (numerator * object.denominator) + (object.numerator * denominator);
            ans.denominator = denominator * object.denominator;
        }
        ans.print();
    }

    void operator-(fraction &object)
    {
        int max;
        int min;
        fraction ans;
        if (denominator > object.denominator)
        {
            max = denominator;
            min = object.denominator;
        }
        else
        {
            max = object.denominator;
            min = denominator;
        }
        if (max % min == 0)
        {
            int multiple = max / min;
            if (object.denominator == min)
            {
                int n = object.numerator * multiple;
                ans.numerator = numerator - n;
                ans.denominator = max;
            }
            else
            {
                int n = numerator * multiple;
                ans.numerator = n - object.numerator;
                ans.denominator = max;
            }
        }
        else
        {
            ans.numerator = (numerator * object.denominator) - (object.numerator * denominator);
            ans.denominator = denominator * object.denominator;
        }
        ans.print();
    }

    void operator*(fraction &object)
    {
        fraction ans;
        ans.numerator = numerator * object.numerator;
        ans.denominator = denominator * object.denominator;
        ans.print();
    }

    void operator/(fraction &object)
    {
        fraction ans;
        ans.numerator = numerator * object.denominator;
        ans.denominator = denominator * object.numerator;
        ans.reduce();
        ans.print();
    }
    
    fraction operator++()
    {
        numerator += denominator;
        return *this;
    }

    fraction operator++(int)
    {
        fraction temp = *this;
        numerator += denominator;
        return temp;
    }    

    friend void add_int(fraction &obj, int n);
};

void add_int(fraction &obj, int n)
{
    obj.numerator += (obj.denominator * n);
    obj.print();
}
