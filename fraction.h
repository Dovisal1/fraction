/*
 * Author: Dovi Salomon
 *
 * Name: Fraction.h
 *
 * This class was designed to allow programmers to easily
 * implement fractions into their programs.
 * 
 */

class Fraction {
	int num, den;
    
    	void reduce(void);
    
    public:
	Fraction(void);
	Fraction(int, int);
    
	void setValues(int, int);
    
	int getNum(void);
	int getDen(void);
    
	void print(void);
    
	double evaluate(void);
    
	Fraction operator+ (const Fraction&);
	Fraction operator+ (int);
    
	Fraction operator- (const Fraction&);
	Fraction operator- (int);
    
	Fraction operator* (const Fraction&);
	Fraction operator* (int);
    
	Fraction operator/ (const Fraction&);
	Fraction operator/ (int);
};
