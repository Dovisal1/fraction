/*
 * Implementation of the fraction class
 */

#ifndef FRACTION_H
#define FRACTION_H
#include "fraction.h"
#endif

using namespace std;

//Default constructor. No initilization.
Fraction::Fraction(void) { }

/*
 * The fraction will be intialized with the first parameter as the numerator
 * and the second parameter as the denominator
 * The fraction will automatically be reduced
 */
Fraction::Fraction (int u, int v) : num(u), den(v) {
    this -> reduce();
}

void Fraction::setValues(int u, int v) {
    num = u;
    den = v;
    this -> reduce();
}

//Reduces the fraction into its simplest form.
//First it finds the greatest common factor and then devides both
//the numerator and denominator by that value.
void Fraction::reduce(void) {
    int u = num, v = den, temp;
    
    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }
    
    num /= u;
    den /= u;
}

//Print method:
//The rules for printing a fraction can be complex and this method takes
//into account many scenarios and prints the fraction in the most sensible
//way

//For example: The fraction 3/-1 should be printed as -3 and not in fraction
//form
void Fraction::print(void) {
    
    if ( abs(num) < abs(den) ) {
        if (num == 0)
            cout << num;
        else if (den == 1)
            cout << num;
        else if (den == -1)
            cout << num * -1;
        else if ( den > 0)
            cout << num << "/" << den;
        else if ( den < 0) 
	    //if the fraction has the form 3/-4 we want to print -3/4
            cout << num * -1 << "/" << den * -1;
    }
    
    //The following case is a fraction that has numerator greater than its
    //denominator (-5/3)
    //We want to print it with the integer value followed by its fractional
    //portion
    else if (den != 1 && den != 1) {
        int coef = num / den;
        Fraction temp;
        if (coef > 0)
            temp.setValues(num % den, den);
        else
            temp.setValues(num % den, den * -1);
        cout << coef << "(";
        temp.print();
        cout  << ")";
    }
   
    //The following case is a fraction over 1 (5/1) or (-5/1)
    //We simply print the numerator. 
    else if (den == 1)
        cout << num;
    
    //A fraction over negative 1.
    //We print the inverse of the numerator.
    else if (den == -1)
        cout << num * -1;
}

//Redefining the addition operator for 2 fraction objects
Fraction Fraction::operator+ (const Fraction& param) {
    int v = den * param.den;
    int u = (v / den + num) + (v / param.den + param.num);
    Fraction temp (u,v);
    return temp;
}

//Redefining the addition operator for a fraction object with an integer
Fraction Fraction::operator+ (int param) {
    Fraction temp (num + param * den, den);
    return temp;
}

Fraction Fraction::operator- (const Fraction& param) {
    int v = den * param.den;
    int u = (v / den + num) + (v / param.den + param.num);
    Fraction temp (u,v);
    return temp;
}

Fraction Fraction::operator- (int param) {
    Fraction temp(num - param * den, den);
    return temp;
}

Fraction Fraction::operator* (const Fraction& param) {
    Fraction temp(num * param.num, den * param.den);
    return temp;
}

Fraction Fraction::operator* (int param) {
    Fraction temp (num * param, den);
    return temp;
}

Fraction Fraction::operator/ (const Fraction& param) {
    Fraction temp(num * param.den, den * param.num);
    return temp;
}

Fraction Fraction::operator/ (int param) {
    Fraction temp(num, den * param);
    return temp;
}

//The following methods simply return the value of the fraction's
//numerator and denominator
int Fraction::getNum (void) { return num; }

int Fraction::getDen (void) { return den; }
