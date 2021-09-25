#ifndef _ULITKA_H_
#define _ULITKA_H_
#include <iostream>

class Ulitka {
private:
	double a; //№1
	double R; //№1

public:
	Ulitka(double radius = 1);
	Ulitka(double radius, double A);

	Ulitka& set_R(double radius = 1);                      //№2
	Ulitka& set_a(double A = 1) { a = A; return *this; };  //№2

	double get_R() const { return R; }                     //№2
	double get_a() const { return a; }                     //№2

	double len_to_beg(double fi);                          //№3          Вернуть расстояние до центра в полярной системе координат в зависимости от угла для точки принадлежащей улитке Паскаля.
	double rkriv(double fi);                               //№4          Вернуть радиус кривизны в характерных точках улитки Паскаля.
	const char* type();                                    //№5          Вернуть тип формы улитки Паскаля (с петлей, кардиоида, с перегибом, овальная)
	double area();                                         //№6          Вернуть площадь описываемую полярным радиусом улитки Паскаля.
	char* uravnenie(int key = 1);                          //№7          Вернуть текстовое представление уравнения улитки Паскаля в декартовой системе координат в виде строки (char[] или wchar_t[]).

	void print_R_a();
};

#endif
