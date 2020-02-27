#pragma once
#include <iostream>


class Monomial {
public:
	int Degree;
	int Coefficient;

	Monomial();
	Monomial(int const &Coeff,int const &Deg);
	Monomial(int const &Coeff);
	friend std::ostream &operator<<(std::ostream &out, Monomial const &source);
	 void operator+(Monomial const&b);
	 void operator-(Monomial const&b);
	 void operator*( Monomial const&b);
	 void operator^( int const&b);

};

Monomial::Monomial() {
	this->Degree = 0;
	this->Coefficient = 0;
}
Monomial::Monomial(int const &Coeff, int const &Deg) {
	this->Coefficient = Coeff;
	this->Degree = Deg;
}
Monomial::Monomial(int const &Coeff) {
	this->Degree = 1;
	this->Coefficient = Coeff;
}
std::ostream &operator<<(std::ostream &out, Monomial const &source) {
	if (source.Degree == 0) {
		out << source.Coefficient;
		return out;

	}
	else if (source.Degree == 1) {
		out << source.Coefficient << "*X";
		return out;


	}
	else{
    	out << source.Coefficient << "*X^" << source.Degree;
		return out;
	}
	
	
}
void Monomial::operator+(Monomial const&b) {
	if (this->Degree == b.Degree) {
		this->Coefficient += b.Coefficient;
	}
	else {
		return;
	}
}
void Monomial::operator-( Monomial const&b) {
	if (this->Degree == b.Degree) {
		this->Coefficient -= b.Coefficient;
	}
	else {
		return;
	}
}
void Monomial::operator*(Monomial const&b) {
	if (b.Degree == 0) {
		this->Coefficient *= b.Coefficient;
	}
	else {
		this->Coefficient *= b.Coefficient;
		this->Degree += b.Degree;
	}
}
void  Monomial::operator^(int const&b) {
	if (b == 0) {
		this->Coefficient = 0;
		this->Degree = 1;
	}
	else {
		int p = this->Coefficient;
		for (int i = 1; i < b; i++) {
			this->Coefficient *= p;
		}
	}
}

