#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>

class Monomial {
public:
	int Degree;
	double Coefficient;
	double Pry;
	bool is_monom;
	bool is_cos, is_sin, is_tan, is_lan, is_E;

	Monomial();
	Monomial(int const &Coeff,int const &Deg);
	Monomial(int const &Coeff);
	Monomial(std:: string const &form);
	friend std::ostream &operator<<(std::ostream &out, Monomial const &source);
	 void operator+(Monomial const&b);
	 void operator-(Monomial const&b);
	 void operator*( Monomial const&b);
	 void operator^( int const&b);
	 void operator/(Monomial const &b);
	 void Derive();
	 void Derive(int const &mag);
	 double operator[](double const &x_value);
	 
};


void get_Cof_Deg(std::string const &to_parse,double &cof, int &deg) {
	std::stringstream ss, ss2;
	std::string via, via2;
	std::size_t pos;
	pos = to_parse.find("*");
	if (pos == std::string::npos) {
		pos = to_parse.find("x");
		if (pos == std::string::npos) {
			return;
		}
		else {
			if (to_parse[pos + 1] == '^') {
				pos += 2;
				for (std::size_t i = pos; i < to_parse.size(); i++) {
					ss << to_parse[i];
				}
				via = ss.str();
				ss.str(std::string());
				deg = atoi(via.c_str());
				cof = 1;
				return;
			}
			else {
				cof = 1;
				deg = 1;
			}
		}
	}
	else {
		for (std::size_t i = 0; i < pos; i++) {
			ss << to_parse[i];
		}
		via = ss.str();
		ss.str(std::string());
		cof = atoi(via.c_str());
		pos = to_parse.find("x");
		if (to_parse[pos + 1] == '^') {
			pos += 2;
			for (std::size_t i = pos; i < to_parse.size(); i++) {
				ss << to_parse[i];
			}
			via = ss.str();
			ss.str(std::string());
			deg = atoi(via.c_str());
			return;
		}
		else {
			deg = 1;
			return;
		}
	}
}
Monomial::Monomial() {
	this->Degree = 0;
	this->Coefficient = 0;
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = false;
}
Monomial::Monomial(int const &Coeff, int const &Deg) {
	this->Coefficient = Coeff;
	this->Degree = Deg;
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = true;
}
Monomial::Monomial(int const &Coeff) {
	this->Degree = 1;
	this->Coefficient = Coeff;
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = true;
}
Monomial::Monomial(std::string const &form) {
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = false;
	std::size_t pos, endp;
	std::stringstream ss, ss2;
	std::string via, via2,subs;
	int DEG,i=0;
	double COF;
	if (form.find("cos(") != std::string::npos) {
		this->is_cos = true;
		pos = form.find("cos(");
		pos += 3;
		endp = form.find(")",pos);
		subs = form.substr(pos+1, endp-1);
		get_Cof_Deg(subs, COF, DEG);
		this->Degree = DEG;
		this->Coefficient = COF;

	}
	else if (form.find("sin(") != std::string::npos) {
		this->is_sin = true;
		pos = form.find("sin(");
		pos += 3;
		endp = form.find(")", pos);
		subs = form.substr(pos + 1, endp - 1);
		get_Cof_Deg(subs, COF, DEG);
		this->Degree = DEG;
		this->Coefficient = COF;
	}
	else if (form.find("tan(") != std::string::npos) {
		this->is_tan = true;
		pos = form.find("tan(");
		pos += 3;
		endp = form.find(")", pos);
		subs = form.substr(pos + 1, endp - 1);
		get_Cof_Deg(subs, COF, DEG);
		this->Degree = DEG;
		this->Coefficient = COF;
	}
	else if (form.find("ln(") != std::string::npos) {
		this->is_lan = true;
		pos = form.find("ln(");
		pos += 2;
		endp = form.find(")", pos);
		subs = form.substr(pos + 1, endp - 1);
		get_Cof_Deg(subs, COF, DEG);
		this->Degree = DEG;
		this->Coefficient = COF;
	}
	else {
		this->is_monom = true;
		get_Cof_Deg(form, COF, DEG);
		this->Degree = DEG;
		this->Coefficient = COF;
	}


}

std::ostream &operator<<(std::ostream &out, Monomial const &source) {
	if (source.is_cos == true) {
		std::cout << "cos(";
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			out << source.Coefficient << "*X";
			std::cout << ")";

			return out;


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else if (source.is_sin == true) {
		std::cout << "sin(";
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			out << source.Coefficient << "*X";
			std::cout << ")";

			return out;


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else if (source.is_tan == true) {
		std::cout << "tan(";
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			out << source.Coefficient << "*X";
			std::cout << ")";

			return out;


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else if (source.is_monom == true) {
		if (source.Degree == 0) {
			out << source.Coefficient;

			return out;

		}
		else if (source.Degree == 1) {
			out << source.Coefficient << "*X";
\
			return out;


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
\
			return out;
		}
	}
	else if (source.is_lan == true) {
		std::cout << "ln(";
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			out << source.Coefficient << "*X";
			std::cout << ")";

			return out;


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else {
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
		this->Degree *= b;
		int p = this->Coefficient;
		for (int i = 1; i < b; i++) {
			this->Coefficient *= p;
		}
	}
}
void Monomial::operator/(Monomial const &b) {
	this->Coefficient /= b.Coefficient;
	this->Degree -= b.Degree;
}
void Monomial::Derive() {
	if (is_cos == true) {
		
	}
	else if (is_sin == true) {

	}
	else if (is_tan==true) {

	}
	else if (is_lan == true) {

	}
	else if (is_monom == true) {
		if (Degree == 1) {
			Degree = 0;
			return;
		}
		else if (Degree == 0) {
			Coefficient = 0;
		}
		else {
			this->Coefficient *= Degree;
			this->Degree--;
		}
	}
	else {
		return;
	}
}
void Monomial::Derive(int const &mag) {
	for (int i = 0; i < mag; i++) {
		Derive();
	}
}
double Monomial::operator[](double const &x_value) {
	if (this->is_cos == true) {
		if (Degree == 0) {
			return cos(Coefficient);
		}
		else if (Degree == 1) {
			return cos(Coefficient * x_value);
		}
		else {
			double t_valv = x_value;

			for (unsigned i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			return cos(t_valv);
		}
	}
	else if (this->is_monom == true) {

		if (Degree == 0) {
			return Coefficient;
		}
		else if (Degree == 1) {
			return Coefficient * x_value;
		}
		else {
			double t_valv = x_value;

			for (unsigned i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			return t_valv;
		}
	}
	else if (this->is_tan == true) {
		if (Degree == 0) {
			return std::tan(Coefficient);

		}
		else if (Degree == 1) {
			return std::tan(Coefficient * x_value);
		}
		else {
			double t_valv = x_value;

			for (unsigned i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			return std::tan(t_valv);
		}
	}
	else if (this->is_lan == true) {
		if (Degree == 0) {
			return std::log(Coefficient);

		}
		else if (Degree == 1) {
			return std::log(Coefficient * x_value);
		}
		else {
			double t_valv = x_value;

			for (unsigned i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			return std::log(t_valv);
		}
	}
	else if (this->is_sin == true) {
		if (Degree == 0) {
			return std::sin(Coefficient);
			
		}
		else if (Degree == 1) {
			return std::sin(Coefficient * x_value);
		}
		else {
			double t_valv = x_value;

			for (unsigned i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			return std::sin(t_valv);
		}
	}
	else {
		return 0;
	}

}







class Function {
protected:

public:
	std::string input;
	std::vector<Monomial> Body;
	std::vector<char> signs;

	std::stack<char> operations;
	std::stack<Monomial> operands;
	Function();
	Function(const char *function);
	double operator[](double const &x_value);
	friend std::ostream &operator<<(std::ostream &out, Function const &func);
	void Derive();
	void Derive(int const &mag);

};

double commit_operation(char const &op, double const &a, double const &b) {
	double sum = 0;
	switch (op)
	{
	case '+':
		sum = a + b;
		return sum;
		break;
	case '-':
		sum = a - b;
		return sum;
		break;

	case '*':
		sum = a * b;
		return sum;
		break;

	case '/':

		sum = a / b;
		return sum;
		break;

	case '^':
		sum = pow(a, b);
		return sum;
		break;



	default:
		return 0;
		break;
	}
}
int sign_pt(char const &op) {
	switch (op)
	{
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;

	case '*':
		return 2;
		break;

	case '/':

		return 2;
		break;

	case '^':
		return 3;
		break;



	default:
		return 0;
		break;
	}
}
Function::Function() {

}
Function::Function(const char *function) {
	this->input = std::string(function);
	std::stringstream ss;
	std::string via;
	std::size_t pos, endp;
	if (input.find(' ') == std::string::npos) {

		operands.push(Monomial(input));
		Body.push_back(Monomial(input));

	}
	else {
		endp = input.find(' ');
		pos = 0;
		while (true) {
			for (std::size_t i = pos; i < endp; i++) {
				ss << input[i];
			}
			via = ss.str();
			ss.str(std::string());
			operands.push(Monomial(via));
			Body.push_back(Monomial(via));
			operations.push(input[endp + 1]);
			signs.push_back(input[endp + 1]);
			pos = endp +2;
		
			if (input.find(' ', pos+1) == std::string::npos) {
				for (std::size_t i = pos + 1; i < input.size(); i++) {
					ss << input[i];
				}
				via = ss.str();
				ss.str(std::string());
				operands.push(Monomial(via));
				Body.push_back(Monomial(via));
				break;
			}
			endp = input.find(' ', pos+1);
			
		}
	}

}
double Function::operator[](double const &x_value) {
	std::vector<double> infix;
	std::stack<char> opts;
	std::stack<double> oprnds;
	char temp;
	double a, b, sum;
	int k = 0;
	for (int i = 0; i < Body.size(); i++) {
		oprnds.push(Body[i][x_value]);
		if (k < signs.size()) {
			if (opts.empty()) {
				opts.push(signs[k]);
			}
			else {
				if (sign_pt(opts.top()) < sign_pt(signs[k])) {
					opts.push(signs[k]);
				}
				else {
					temp = opts.top();
					opts.pop();
					a = oprnds.top();
					oprnds.pop();
					b = oprnds.top();
					oprnds.pop();
					sum = commit_operation(temp, a, b);
					oprnds.push(sum);
					opts.push(signs[k]);
				}
			}
			k++;
		}

	}

	while (!opts.empty()) {
		a = oprnds.top();
		oprnds.pop();
		b = oprnds.top();
		oprnds.pop();
		temp = opts.top();
		opts.pop();
		sum = commit_operation(temp, b, a);
		oprnds.push(sum);
	}
	return oprnds.top();

}
std::ostream &operator<<(std::ostream &out, Function const &func) {
	int k = 0;
	for (unsigned i = 0; i < func.Body.size(); i++) {

		out << func.Body[i] << " ";
		if (k < func.signs.size()) {
			out << func.signs[k] << " ";
			k++;
		}


	}
	for (unsigned i = 0; i < func.Body.size(); i++) {
	}
	return out;
}
void  Function::Derive() {
	for (int i = 0; i < Body.size(); i++) {
		Body[i].Derive();
	}
}
void Function::Derive(int const &mag) {
	for (int i = 0; i < mag; i++) {
		this->Derive();
	}
}
