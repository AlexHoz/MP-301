#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double Function(double x) 
{
    return max(abs(x) + 1, x * x + 4 * x + 4);
   //Вы должны вернуть то что посчитала ВАША функция
}

double DivisionMethod(double accuracy, double a, double b, double (*function)(double))
{
    double c = (a + b) / 2;
    double x, y, Fx, Fy, Fc = Function(c);
    while (b - a > accuracy)
    {
        x = a + (b - a) / 4;
        y = b - (b - a) / 4;
        Fx = function(x);
        Fy = function(y);
        if (Fx < Fc) {
            b = c;
            c = x;
            Fc = Fx;
        }
        else if (Fy < Fc) {
            a = c;
            c = y;
            Fc = Fy;
        }
        else {
            a = x;
            b = y;
        }
    }
    return c;
}

double DichotomyMethod(double accuracy, double distinguishability, double a, double b, double (*function)(double))
{
    double c = (a + b) / 2;
    double x, y, Fx, Fy;

    while (b - a > accuracy) {
        x = (a + b) / 2 - distinguishability;
        y = (a + b) / 2 + distinguishability;
        Fx = function(x);
        Fy = function(y);
        Fx > Fy ? a = x : b = y;;
    }
    return (a + b) / 2;
}

int main()
{
    cout << DivisionMethod(0.01, -5, 3, Function) << endl
        << DichotomyMethod(0.01, 0.001, -5, 3, Function);
    //a = -5 и  b = 3 - это мои параметры, измените на свои
    //0.01 - заданная точность
    //0.001 - погрешность, как я понял её придумываем сами, но по условию (погрешность * 2 < точности)
}

