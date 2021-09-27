#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Ulitka.h"


Ulitka::Ulitka(double radius) :a(1) { //Пустой конструктор
	if (radius < 0)
		throw std::exception("Invalid radius!");

	R = radius;
}

Ulitka::Ulitka(double radius, double A) :a(A) {
	if (radius < 0)
		throw std::exception("Invalid radius!");

	R = radius;
}

Ulitka& Ulitka::set_R(double radius) { //№2
	if (radius < 0)
		throw std::exception("Invalid radius!");

	R = radius;

	return *this;
}

double Ulitka::len_to_beg(double fi) const { //№3
	double ro_fi, x, y, i, l;

	i = fi * M_PI / 180; //deg to rad
	ro_fi = 2 * R * cos(i) + a;

	x = ro_fi * cos(i);
	y = ro_fi * sin(i);
	l = sqrt(x * x + y * y);

	return l;
}

double Ulitka::rkriv(double fi) const { //№4
	double r, r1, r2, chisl, znam, k, rKriv = 0, fi1;

	fi1 = M_PI * fi / 180;

	r = 2 * R * cos(fi1) + a;
	r1 = 0;
	r2 = -1 * R * cos(fi1);

	chisl = (r * r) + (2 * r1 * r1) - (r * r2);
	chisl = fabs(chisl);

	znam = r * r + r2 * r2;
	znam = pow(znam, 1.5);

	k = chisl / znam;

	if (k == 0) {
		std::cout << "No rKriv!" << std::endl;
		return 0;
	}
	else {
		rKriv = 1 / k;
	}

	return k;

}

const char* Ulitka::type() const { //№5
	const char* type = "Error";
	if (2 * R > a)
		type = "С петлёй";

	if (2 * R < a)
		type = "С перегибом";

	if (2 * R == a)
		type = "Кардиола";

	if ((R == 0 && a != 0) || (a == 0 && R != 0))
		type = "Окружность";

	if (R == 0 && a == 0)
		type = "Вырожденная";

	return type;
}

double Ulitka::area() const { //№6
	double S;
	S = (2 * M_PI * R * R) + (M_PI * a * a);

	return S;
}

char* Ulitka::uravnenie(int key) const { //№7
	//Не требовалось по заданию
	if (key == 1) {
		std::cout << "\nУравнение улитки Паскаля в декартовой системе координат:\n";
		system("chcp 65001>nul");
		const char* s = u8"(x\u00B2 + y\u00B2 - 2\u00B7R\u00B7x)\u00B2 - a\u00B2\u00B7(x\u00B2 + y\u00B2) = 0\n";
		std::cout << s << std::endl;
		system("chcp 1251>nul");
	}

	//Требовалось по заданию
	const char* c = "(x^2 + y^2 - *x)^2 - *(x^2 + y^2) = 0";
	int l = strlen(c) + 1;

	char num[20];
	sprintf(num, "%.2f", 2 * R);
	l += strlen(num);
	sprintf(num, "%.2f", a * a);
	l += strlen(num);

	char* C = new char[l];

	if (R == 0) {
		sprintf(C, "(x^2 + y^2)^2");
	}
	else {
		sprintf(C, "(x^2 + y^2 - %.2f*x)^2", 2 * R);
	}

	int k = strlen(C);

	if (a == 0) {
		sprintf(C + k, " = 0");
	}
	else {
		sprintf(C + k, " - %.2f*(x^2 + y^2) = 0", a * a);
	}

	if (key == 1) {
		std::cout << "Текущее уравнение улитки Паскаля:" << std::endl;
	}

	return C;
}

void Ulitka::print_R_a() const { //Напечатать R и a
	std::cout << "\nR = " << std::fixed << std::setprecision(3) << R << "\na = " << std::fixed << std::setprecision(3) << a << std::endl << std::endl;
}
