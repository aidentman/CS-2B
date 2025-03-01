#ifndef FRACTION_H
#define FRACTION_H

/*
Aiden Man
CS 2A - Harden
8/1/24
Project 15.1 - Fraction.h

The Fraction class can be used to create objects that store a fraction, consisting of
a numerator and denominator.

The following functions are available:

Fraction();
    pre: Nothing is passed through the initialization of the object
    post: The calling object has been created and initialized to 0/1

Fraction(int num1, int num2);
    pre: int num1 and int num2 are passed, where num2 is not 0
    post: The calling object has been created and initialized so
    the numerator is num1 and the denominator is num2.
    (As long as num2 is not 0)

Fraction addedTo(const Fraction& fraction) const;
    post: Returns a Fraction answer after adding
    the calling object and the passed Fraction

Fraction subtract(const Fraction& fraction) const;
    post: Returns a Fraction answer after subtracting
    the passed Fraction from the calling object

Fraction multipliedBy(const Fraction& fraction) const;
    post: Returns a Fraction answer after multiplying
    the calling object by the passed Fraction

Fraction dividedBy(const Fraction& fraction) const;
    post: Returns a Fraction answer after dividing
    the calling object by the passed Fraction

bool isEqualTo(const Fraction& fraction) const;
    post: Returns true if the calling object is equal to
    the passed fraction. Otherwise returns false.

void print() const;
    post: The calling object is printed to the console
    in the format numerator/denominator

void simplify();
    post: The function modifies the calling object
    by simplifying the fraction.
*/

class Fraction {
public:
    Fraction();
    Fraction(int num1, int num2);
    Fraction addedTo(const Fraction& fraction) const;
    Fraction subtract(const Fraction& fraction) const;
    Fraction multipliedBy(const Fraction& fraction) const;
    Fraction dividedBy(const Fraction& fraction) const;
    bool isEqualTo(const Fraction& fraction) const;
    void print() const;
private:
    int numerator;
    int denominator;
    void simplify();
};

#endif
