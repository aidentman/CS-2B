#include "fraction.h"
#include <iostream>
#include <cassert>
using namespace std;

/*
Aiden Man
CS 2B - Harden
10/27/24
Project 19.1 - fraction.cpp

Class Invariant: a Fraction object has 2 int data members: numerator,
which stores the numerator of the fraction, and denominator, which
stores the denominator of the fraction. Internal operations always
result in valid fractions (denominator != 0) or booleans. However,
no effort is made to prevent the client from providing an invalid fraction.
Fraction objects will always be stored in its lowest terms (simplified).
*/

namespace cs_fraction{
    Fraction::Fraction(const int num1, const int num2) {
        assert(num2!= 0);
        numerator = num1;
        denominator = num2;
        Simplify();
    }






    bool operator==(const Fraction& fraction1, const Fraction& fraction2){
        int product1 = fraction1.numerator * fraction2.denominator;
        int product2 = fraction1.denominator * fraction2.numerator;
        return (product1 == product2);
    }






    bool operator!=(const Fraction& fraction1, const Fraction& fraction2){
        return !(fraction1 == fraction2);
    }






    bool operator<(const Fraction& fraction1, const Fraction& fraction2){
        int product1 = fraction1.numerator * fraction2.denominator;
        int product2 = fraction1.denominator * fraction2.numerator;
        return (product1 < product2);
    }






    bool operator>(const Fraction& fraction1, const Fraction& fraction2){
        int product1 = fraction1.numerator * fraction2.denominator;
        int product2 = fraction1.denominator * fraction2.numerator;
        return (product1 > product2);
    }






    bool operator>=(const Fraction& fraction1, const Fraction& fraction2){
        return (!(fraction1 < fraction2));
    }






    bool operator<=(const Fraction& fraction1, const Fraction& fraction2){
        return (!(fraction1 > fraction2));
    }






    Fraction operator+(const Fraction& fraction1, const Fraction& fraction2){
        Fraction result;
        result.numerator = fraction1.numerator * fraction2.denominator;
        result.numerator += fraction2.numerator * fraction1.denominator;
        result.denominator = fraction1.denominator * fraction2.denominator;
        result.Simplify();
        return result;
    }






    Fraction operator-(const Fraction& fraction1, const Fraction& fraction2){
        Fraction result;
        result.numerator = fraction1.numerator * fraction2.denominator;
        result.numerator -= fraction2.numerator * fraction1.denominator;
        result.denominator = fraction1.denominator * fraction2.denominator;
        result.Simplify();
        return result;
    }






    Fraction operator*(const Fraction& fraction1, const Fraction& fraction2){
        Fraction result;
        result.numerator = fraction1.numerator * fraction2.numerator;
        result.denominator = fraction1.denominator * fraction2.denominator;
        result.Simplify();
        return result;
    }






    Fraction operator/(const Fraction& fraction1, const Fraction& fraction2){
        Fraction result;
        result.numerator = fraction1.numerator * fraction2.denominator;
        result.denominator = fraction1.denominator * fraction2.numerator;
        result.Simplify();
        return result;
    }






    Fraction Fraction::operator+=(const Fraction& fraction1){
        *this = *this + fraction1;
        return (*this);
    }






    Fraction Fraction::operator-=(const Fraction& fraction1){
        *this = *this - fraction1;
        return (*this);
    }






    Fraction Fraction::operator*=(const Fraction& fraction1){
        *this = *this * fraction1;
        return (*this);
    }






    Fraction Fraction::operator/=(const Fraction& fraction1){
        *this = *this / fraction1;
        return (*this);
    }






    Fraction Fraction::operator++(){
        *this = *this + 1;
        return (*this);
    }






    Fraction Fraction::operator++(int){
        Fraction temp(numerator, denominator);
        numerator += denominator;
        return (temp);
    }






    Fraction Fraction::operator--(){
        *this = *this - 1;
        return (*this);
    }






    Fraction Fraction::operator--(int){
        Fraction temp(numerator, denominator);
        numerator -= denominator;
        return (temp);
    }






    /*
    This function overloads the extraction operator. It takes in "fraction",
    a fraction object, and reformats the numbers to output to the stream
    using the ostream "out". The output is formatted such that the whole
    number is placed before the fraction, e.g. 1+2/3, and separated by a '+'
    character. In this case, 1 is the whole number, and 2/3 is the fraction.
    When there is only a fraction, the whole number and '+' characters are
    omitted, e.g. 2/3, and when there is only a whole number, the fraction
    is omitted, e.g. 1. Negative signs will always format to be in front of
    the first number, e.g. -10+1/2 or -1/2.
    */
    ostream& operator<<(ostream& out, const Fraction& fraction){
        Fraction temp(fraction.numerator, fraction.denominator);
        int whole = temp.numerator / temp.denominator;
        if (temp.numerator < 0 && whole < 0){
            temp.numerator *= -1;
        }
        temp.numerator = temp.numerator % temp.denominator;
        if (temp.denominator == 1){
            out << whole;
        } else if (whole == 0){
            out << temp.numerator << "/" << temp.denominator;
        } else{
            out << whole << "+" << temp.numerator << "/" << temp.denominator;
        }
        return out;
    }






    /*
    This function overloads the insertion operator, taking an input
    stream, "in", and formating the fraction object, "fraction", based
    on this input. The input must be formatted such that the whole part
    is followed by the fraction and separated by a '+' character, e.g.
    1+2/3. With just a fraction, the fraction would be formatted as 2/3
    where the numerator and denominator are separated by a '/' character.
    With just an integer, the integer would be formatted by itself e.g.
    1. Negative signs must always be formatted to be in front of the first
    number, e.g. -10+1/2 or -1/2.
    */
    istream& operator>>(istream &in, Fraction &fraction){
        int temp;
        int whole;
        in >> temp;
        if (in.peek() == '+'){
            in.ignore();
            whole = temp;
            in >> temp;
            fraction.numerator = temp;
            in.ignore();
            in >> temp;
            if (whole < 0) {
                fraction.numerator *= -1;
            }
            fraction.numerator += whole * temp;
            fraction.denominator = temp;
        } else if (in.peek() == '/'){
            fraction.numerator = temp;
            in.ignore();
            in >> temp;
            fraction.denominator = temp;
        } else {
            fraction.numerator = temp;
            fraction.denominator = 1;
        }
        return in;
    }






    /*
    This private member function simplifies the fraction. It does so
    by finding the greatest common factor starting from the value of
    the denominator and incrementing downward. For simplicity, the
    value the program checks decreases from the denominator, which is
    positive in every instance. If the integer is a shared factor,
    both values are modified by dividing by that factor. If there is
    no shared factor, the values stay the same, and the for loop continues
    to search for a shared factor (does not include 1).
    */
    void Fraction::Simplify(){
        if (denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }
        for (int i=denominator; i > 1; i--) {
            if (numerator % i == 0 && denominator % i == 0 && denominator > 1){
                numerator /= i;
                denominator /= i;
            }
        }
    }
}