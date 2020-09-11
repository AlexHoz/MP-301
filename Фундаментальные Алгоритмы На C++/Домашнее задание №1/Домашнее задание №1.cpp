#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;

//Задание 1
double Length(double xA, double yA, double xB, double yB) { return sqrt(pow(xB - xA, 2) + pow(yB - yA, 2)); }

//Задание 2
double TriangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
//Задание 3
struct Point
{
    int x;
    int y;
};
double Length(Point a, Point b) { return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)); }

//Задание 5
double TriangleArea(Point a, Point b, Point c) { return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) /2; }

//Задание 6
long GCD(long a, long b) 
{
    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b -= a;
    }
    return a;
}

double AmountPoints(Point a, Point b) {
    return 1 + GCD(abs(b.x - a.x),abs(b.y - a.y));
}
double AmountPoints(double xA, double yA, double xB, double yB) {
    return 1 + GCD(abs(xB - xA), abs(yB - yA));
}

//Задание 7
double PoligonPerimeter()
{
    int n;
    long xA, yA, xB, yB, xS, yS;
    double  p = 0;
    cin >> n >> xA >> yA;
    xS = xA; 
    yS = yA;
    for (int i = 0; i < n - 1; i++) {
        cin >> xB >> yB;
        p += Length(xA, yA, xB, yB);
        xA = xB; 
        yA = yB;
    }
    p += Length(xS, yS, xA, yA);
    return p;
}
//Задание 8
int AmountPointsPerimeter() {
    int n;
    long xA, yA, xB, yB, xS, yS,  p = 0;
    cin >> n >> xA >> yA;
    xS = xA;
    yS = yA;
    for (int i = 0; i < n - 1; i++) {
        cin >> xB >> yB;
        p += AmountPoints(xA, yA, xB, yB) - 1;
        xA = xB;
        yA = yB;
    }
    p += AmountPoints(xS, yS, xA, yA) - 1;
    return p;
}
//Задание 9
string Intersected(Point a, Point b, Point c, Point d)
{
    double denominator = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.y - c.x);

    if (denominator == 0) return "Не пересекаются";

    double numeratorA = (a.y - c.y) * (d.x - c.x) - (a.x - c.x) * (d.y - c.y);
    double numeratorB = (a.y - c.y) * (b.x - a.x) - (a.x - c.x) * (b.y - a.y);

    double r = numeratorA / denominator;
    double s = numeratorB / denominator;

    if (r >= 0 && r <= 1 && s >= 0 && s <= 1)
        return "Пересекаются";
    else
        return "Не пересекаются";
}
//Задание 10
int Area(Point a, Point b, Point c, Point d)
{
    int xA = max(a.x, c.x), xB = min(b.x, d.x);
    int yA = max(a.y, c.y), yB = min(b.y, d.y);
    int width = xB - xA;
    int height = yB - yA;

    return (width < 0 || height < 0) ? 0 : width * height;
}
/* ИЛИ ТАК
int Area(Point a, Point b, Point c, Point d)
{
    int width = min(b.x, d.x) - max(a.x, c.x);;
    int height = min(b.y, d.y) - max(a.y, c.y);

    if (width < 0 || height < 0)  return 0;
    return width * height;
}
*/

//Задание 11
/*int Palindrom(){
    
}*/

//Задание 12
int AmountСells() {
    int n;
    double x, y, size;
    set<pair<int,int>> cells;
    cin >> n >> size;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x /= size;
        y /= size;
        if(x - int(x) != 0 && y - int(y) != 0)
            cells.insert({ int(x), int(y) });
    }
    return cells.size();
}

int main()
{
    //Задание 4
    cout << Length(0, 0, 2, 2) << endl
         << TriangleArea(3, 2, 3) << endl;

    Point a = { 0,0 };
    Point b = { 4,4 };
    Point c = { 0,4 };
    cout << Length(a, b) << endl
        << TriangleArea(a, b, c) << endl
        << AmountPoints(a, b) << endl;

    cout << AmountСells();
}


/*
1. Написать функцию, вычисляющую длину отрезка по 4-м координатам двух точек
2. Написать функцию, вычисляющую площадь треугольника по 3-м сторонам.
3. Определить структуру Point из двух полей. Переписать первое задание через структуру.
4. Привести в main примеры функций.
5. Написать функцию вычисляющую площать по 3м вершинам.
6. Написать функцию вычисляющую кол-во целых точек на отрезке с целочисленными концами.
--------------------------------------------------------------------------------------------
7. Написать функцию, вычисляющую периметр многоугольника по вершинам
8. Написать функцию, вычисляющую кол-во целых точек на периметре многоугольника
9. Написать функцию определяющую, пересекаются ли два отрезка
10. Написать функцию, определяющую площадь пересечения двух прямоугольников
11. Написать функцию, определяющую длину наибольшего палиндрома внутри заданной строки
12. Написать функцию, вычисляющую кол-во клеток которые проткнули иглой
*/