#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

/*
Aiden Man
CS 2B - Harden
10/27/24
Project 19.1 - fraction.h

The Fraction class can be used to create objects that store a fraction, consisting of
a numerator and denominator.

The following functions are available:

Fraction(int num1, int num2);
    pre: int "num1" and int "num2" are passed, where num2 is not 0.
    "num1" defaults to 0, and num2 defaults to 1 if not defined
    otherwise.
    post: The calling object has been created and initialized so
    the numerator is "num1" and the denominator is "num2".
    (As long as "num2" is not 0)


friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns true if the fractions are equivalent
    and false if the fractions are not.

friend bool operator!=(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns true if the fractions are not equivalent
    and false if the fractions are equivalent.

friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns true if the fraction "fraction1" is less than "fraction2"
    and returns false otherwise.

friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns true if the fraction "fraction1" is greater than
    "fraction2" and returns false otherwise.

friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns true if the fraction fraction1 is less than
    or equal to fraction2, and returns false if otherwise.

friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns true if the fraction "fraction1" is greater
    than or equal to "fraction2", and returns false if otherwise.

friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns a fraction equal to the sum of
    "fraction1" and "fraction2".

friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns a fraction equal to the difference
    between "fraction1" and "fraction2".

friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns a fraction equal to the product
    between "fraction1" and "fraction2".

friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2);
    pre: Fraction "fraction1" and Fraction "fraction2" are passed
    post: The function returns a fraction equal to the quotient
    of "fraction1" and "fraction2".

Fraction operator+=(const Fraction& fraction1);
    pre: The calling fraction and the Fraction "fraction1" are passed.
    post: The function sets the calling fraction to the sum of that
    fraction and "fraction1".

Fraction operator-=(const Fraction& fraction1);
    pre: The calling fraction and the Fraction "fraction1" are passed.
    post: The function sets the calling fraction to the difference between that
    fraction and "fraction1".

Fraction operator*=(const Fraction& fraction1);
    pre: The calling fraction and the Fraction "fraction1" are passed.
    post: The function sets the calling fraction to the product of that
    fraction and "fraction1".

Fraction operator/=(const Fraction& fraction1);
    pre: The calling fraction and the Fraction "fraction1" are passed.
    post: The function sets the calling fraction to the quotient of that
    fraction and "fraction1".

Fraction operator++();
    pre: Nothing is passed through the call of this function.
    post: The function pre-increments the calling fraction, adding
    1 before returning the value.

Fraction operator++(int);
    pre: Nothing is passed through the call of this function.
    post: The function post-increments the calling fraction, adding
    1 after returning the value.

Fraction operator--();
    pre: Nothing is passed through the call of this function.
    post: The function pre-decrements the calling fraction, subtracting
    1 before returning the value.

Fraction operator--(int);
    pre: Nothing is passed through the call of this function.
    post: The function post-decrements the calling fraction, subtracting
    1 after returning the value.

friend ostream& operator<<(ostream& out, const Fraction& fraction);
    pre: An ostream "out" and a Fraction "fraction" are passed into
    the function.
    post: The function returns the "out" ostream with "fraction" formatted
    as a string, such that the whole number is placed first, followed by a
    '+' character to separate it from the fraction, where the numerator
    and denominator are separated by '/', e.g. 1+2/3. If there is
    no fraction, the whole number and '+' character are omitted, e.g. 2/3.
    If the number is only a whole integer, the fraction and '+' character
    are omitted, e.g. 1.

friend istream& operator>>(istream& in, Fraction& fraction);
    pre: An istream "in" and a Fraction "fraction" are passed into
    the function. The "in" istream must be formatted such that the
    whole number component is separated from the fraction component
    by a '+' character, and the numerator and denominator are
    separated by a '/' character, e.g. 1+2/3. If there is only a whole
    integer, the '+' and fraction are omitted, e.g. 1. If there
    is only a fraction, the whole number and '+' are omitted, e.g. 2/3.
    post: The function returns the fraction object with values matching the
    input from the "in" istream.

void Simplify();
    pre: Nothing is passed through the call of this function
    post: The calling fraction is simplified such that the result
    is an equivalent fraction in the smallest possible integer terms
*/


namespace cs_fraction{
    class Fraction {
    public:
        Fraction(int num1 = 0, int num2 = 1);

        friend bool operator==(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator!=(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator<(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator>(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator<=(const Fraction& fraction1, const Fraction& fraction2);
        friend bool operator>=(const Fraction& fraction1, const Fraction& fraction2);

        friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2);
        friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2);
        Fraction operator+=(const Fraction& fraction1);
        Fraction operator-=(const Fraction& fraction1);
        Fraction operator*=(const Fraction& fraction1);
        Fraction operator/=(const Fraction& fraction1);

        Fraction operator++();
        Fraction operator++(int);
        Fraction operator--();
        Fraction operator--(int);

        friend ostream& operator<<(ostream& out, const Fraction& fraction);
        friend istream& operator>>(istream& in, Fraction& fraction);

    private:
        int numerator;
        int denominator;
        void Simplify();
    };
}

#endif //FRACTION_H
