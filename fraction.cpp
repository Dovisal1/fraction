/*
 * Implementation of the fraction class
 */

#ifndef FRACTION_H
#define FRACTION_H
#include "fraction.h"
#endif

using namespace std;

Fraction::Fraction(void) { }

Fraction::Fraction(int u, int v){
    num = u;
    den = v;
    this -> reduce();
}

void Fraction::setValues(int u, int v) {
    num = u;
    den = v;
    this -> reduce();
}

void Fraction::reduce(void) {
    int u = num, v=den, temp;
    
    while (v != 0) {
        temp = u % v;
        u = v;
        v = temp;
    }
    
    num /= u;
    den /= u;
}

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
            cout << num * -1 << "/" << den * -1;
    }
    
    else if (den != 1 && den != -1) {
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
    
    else if (den == 1)
        cout << num;
    
    else if (den == -1)
        cout << num * -1;
}

Fraction Fraction::operator+ (const Fraction& param) {
    int v = den * param.den;
    int u = (v / den + num) + (v / param.den + param.num);
    Fraction temp (u,v);
    return temp;
}

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

int Fraction::getNum (void) { return this -> num; }

int Fraction::getDen (void) { return this -> den; }
