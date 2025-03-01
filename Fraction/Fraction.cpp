#include <iostream>
#include <cassert>
#include "Fraction.h"

using namespace std;

/*
Aiden Man
CS 2A - Harden
8/1/24
Project 15.1 - Fraction.cpp

Class Invariant: a Fraction object has 2 int data members: numerator,
which stores the numerator of the fraction, and denominator, which
stores the denominator of the fraction. Internal operations always
result in valid fractions (denominator != 0) However, no effort is
made to prevent the client from providing an invalid fraction.
Fraction objects will always be stored in its lowest terms (simplified).
*/

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
    simplify();
}






Fraction::Fraction(int num1, int num2) {
    assert(num2!= 0);
    numerator = num1;
    denominator = num2;
    simplify();
}






Fraction Fraction::addedTo(const Fraction& fraction) const{
    Fraction result;
    result.numerator = numerator * fraction.denominator;
    result.numerator += fraction.numerator * denominator;
    result.denominator = denominator * fraction.denominator;
    result.simplify();
    return result;
}






Fraction Fraction::subtract(const Fraction& fraction) const{
    Fraction result;
    result.numerator = numerator * fraction.denominator;
    result.numerator -= fraction.numerator * denominator;
    result.denominator = denominator * fraction.denominator;
    result.simplify();
    return result;
}






Fraction Fraction::multipliedBy(const Fraction& fraction) const{
    Fraction result;
    result.numerator = numerator * fraction.numerator;
    result.denominator = denominator * fraction.denominator;
    result.simplify();
    return result;
}






Fraction Fraction::dividedBy(const Fraction& fraction) const{
    Fraction result;
    result.numerator = numerator * fraction.denominator;
    result.denominator = denominator * fraction.numerator;
    result.simplify();
    return result;
}






bool Fraction::isEqualTo(const Fraction& fraction) const{
    int product1 = numerator * fraction.denominator;
    int product2 = denominator * fraction.numerator;
    return (product1 == product2);
}






void Fraction::print() const{
    cout << numerator << "/" << denominator;
}






/*
This private member function simplifies the fraction. It does so by finding
the greatest common factor, the maximum of which is determined by the
smallest value between the numerator and the denominator. The for loop
checks every integer less than that maximum to see if that integer is a
factor for both the numerator and denominator. If the integer is a shared
factor, both values are modified by dividing by that factor. If there is
no shared factor, the values stay the same.
*/
void Fraction::simplify(){
    int maxSharedFactor;
    if (numerator > denominator) {
        maxSharedFactor = denominator;
    } else {
        maxSharedFactor = numerator;
    }

    for (int i=maxSharedFactor; i > 1; i--) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
        }
    }
}