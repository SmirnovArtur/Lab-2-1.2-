#include <iostream>
#include <iomanip>
#include "Ulitka.h"


int get_int(int& a) {
    std::cin >> a;
    if (!std::cin.good())
        return -1;
    return 1;
}

int get_double(double& a) {
    std::cin >> a;
    if (!std::cin.good())
        return -1;
    return 1;
}

Ulitka init() {
    int type;
    double R, a;
    do {
        system("cls");
        std::cout << "r(fi) = 2*R*cos(fi) + a\n\n1 - Ulitka() ; R = 1, a = 1\n2 - Ulitka(R); a = 1\n3 - Ulitka(R, a)\n" << std::endl;
        std::cin >> type;
        if (type == 1) {
            Ulitka u;
            return u;
        }
        else if (type == 2) {
            std::cout << "R = ";
            get_double(R);
            Ulitka u(R);
            std::cout << std::endl;
            return u;
        }
        else if (type == 3) {
            std::cout << "\nR = ";
            get_double(R);
            std::cout << "a = ";
            get_double(a);
            Ulitka u(R, a);
            std::cout << std::endl;
            return u;
        }
        else {
            std::cout << "Enter: 1, 2 or 3!" << std::endl;
            system("pause");
            system("cls");
        }
    } while (type > 3 || type < 0);
}

int main() {
    system("chcp 1251>nul");
    
    int menu, type;
    double R, a, fi;
    
    Ulitka u = init();

    do {
        std::cout << "\n-------------------------------------------------------------------" << std::endl;
        std::cout << "\nMenu:\n\n-1 - Начать заново\n0 - Print R and a\n1 - set_R\n2 - set_a\n3 - Расстояние до начала координат\n4 - Радиус кривизны\n5 - Тип кривой\n6 - Площадь описываемую полярным радиусом\n7 - Уравнение в ДПСК\n8 - Clean CMD\n9 - Exit\n\nMenu: ";
        get_int(menu);
        std::cout << "\n-------------------------------------------------------------------" << std::endl;
        
        switch (menu) {
        case -1:
            u = init();
            break;
        case 0:
            u.print_R_a();
            break;
        case 1:
            std::cout << "\nR = ";
            get_double(R);
            u.set_R(R);
            break;
        case 2:
            std::cout << "\na = ";
            get_double(a);
            u.set_a(a);
            break;
        case 3:
            std::cout << "\nfi = ";
            get_double(fi);
            std::cout << std::fixed << std::setprecision(3) << "\nl = " << u.len_to_beg(fi) << std::endl;
            break;
        case 4:
            std::cout << "\nfi = ";
            get_double(fi);
            std::cout << std::fixed << std::setprecision(3) << "\nr = " << u.rkriv(fi) << std::endl;
            break;
        case 5:
            std::cout << "\nТип - " << u.type() << std::endl;
            break;
        case 6:
            std::cout << std::fixed << std::setprecision(3) << "\nS = " << u.area() << std::endl;
            break;
        case 7:
            std::cout << u.uravnenie() << std::endl;
            break;
        case 8:
            system("cls");
            break;
        case 9:
            system("pause");
            exit(0);
            break;
        default:
            std::cout << "Error!\nWrong comand!\nPress any key to try again!\n" << std::endl;
            system("pause");
            system("cls");
        }

        if (menu != 8 && (menu <= 9 && menu >= -1)) {
            std::cout << "\n-------------------------------------------------------------------" << std::endl;
            system("pause");
        }

    } while (menu != 9);


    system("pause");
    return 0;
}
