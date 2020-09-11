#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

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
    double x;
    double y;

    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
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
double getDirection(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool onSegment(Point a, Point b, Point c)
{
    if ((min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) && (min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)))
        return true;
    else
        return false;

}
bool getIsIntersect(Point a1, Point b1, Point a2, Point b2)
{
    double d1 = getDirection(a2, b2, a1);
    double d2 = getDirection(a2, b2, b1);
    double d3 = getDirection(a1, b1, a2);
    double d4 = getDirection(a1, b1, b2);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d3 > 0)))
        return true;
    else if (d1 == 0 && onSegment(a2, b2, a1))
        return true;
    else if (d2 == 0 && onSegment(a2, b2, b1))
        return true;
    else if (d3 == 0 && onSegment(a1, b1, a2))
        return true;
    else if (d4 == 0 && onSegment(a1, b1, b2))
        return true;
    else
        return false;
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
int Palindrom(string s){
    int n = s.size(), max = 0;
    vector<int> d1(n);
    int l = 0, r = -1;
    if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            int k = i > r ? 1 : min(d1[l + r - i], r - i + 1);
            while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) k++;
            d1[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1; 
                r = i + k - 1;
            } 
            if (r - l > max) 
                max = r - l;
        }
    }
    else
    {
        for (int i = 0; i < n; ++i) {
            int k = i > r ? 0 : min(d1[l + r - i + 1], r - i + 1);
            while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])  k++;
            d1[i] = k;
            if (i + k - 1 > r){
                l = i - k;
                r = i + k - 1;
            }  
            if (r - l > max) 
                max = r - l;
        }
    }
    return max + 1;
}

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

    cout << Palindrom("323abccba221");
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