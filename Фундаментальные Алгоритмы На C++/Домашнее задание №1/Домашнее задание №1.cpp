#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>


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

    bool operator<(const Point& p) const
    {
        return sqrt(pow(x, 2) + pow(y, 2)) < sqrt(pow(p.x, 2) + pow(p.y, 2));
    }
};
double Length(Point a, Point b) { return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)); }

//Задание 5
double TriangleArea(Point a, Point b, Point c) {
    return ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y)) / 2;
}

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
    return 1 + GCD(abs(b.x - a.x), abs(b.y - a.y));
}
double AmountPoints(double xA, double yA, double xB, double yB) {
    return 1 + GCD(abs(xB - xA), abs(yB - yA));
}

//Задание 7
double PoligonPerimeter(const vector <Point>& points)
{
    int size = points.size();
    double  perimeter = 0;
    for (int i = 0; i < size - 1; i++) {
        perimeter += Length(points[i], points[i + 1]);
    }
    perimeter += Length(points[0], points[size - 1]);
    return perimeter;
}
//Задание 8
int AmountPointsPerimeter(const vector <Point>& points) {
    int amount = 0;
    int size = points.size();
    for (int i = 0; i < size - 1; i++) {
        amount += AmountPoints(points[i], points[i + 1]) - 1;
    }
    amount += AmountPoints(points[0], points[size - 1]) - 1;
    return amount;
}
//Задание 9
double GetDirection(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool OnSegment(Point a, Point b, Point c)
{
    if ((min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)) && (min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)))
        return true;
    else
        return false;

}
bool getIsIntersect(Point a, Point b, Point c, Point d)
{
    double d1 = GetDirection(c, d, a);
    double d2 = GetDirection(c, d, b);
    double d3 = GetDirection(a, b, c);
    double d4 = GetDirection(a, b, d);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d3 > 0)))
        return true;
    else if (d1 == 0 && OnSegment(c, d, a))
        return true;
    else if (d2 == 0 && OnSegment(c, d, b))
        return true;
    else if (d3 == 0 && OnSegment(a, b, c))
        return true;
    else if (d4 == 0 && OnSegment(a, b, d))
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

//Задание 11 
int Palindrom(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }
    int n = s.size(), max = 0;
    vector<int> d(n);
    int l = 0, r = -1;
    if (n % 2 == 1) {
        for (int i = 0; i < n; ++i) {
            int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
            while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) k++;
            d[i] = k;
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
            int k = i > r ? 0 : min(d[l + r - i + 1], r - i + 1);
            while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])  k++;
            d[i] = k;
            if (i + k - 1 > r) {
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
int AmountСells(const vector <Point>& points, double sizeCell) {
    int size = points.size();
    set <Point> cell;
    for (auto elem : points) {
        elem.x /= sizeCell;
        elem.y /= sizeCell;
        if (elem.x - int(elem.x) != 0 && elem.y - int(elem.y) != 0) {
            elem.x = int(elem.x);
            elem.y = int(elem.y);
            cell.insert({ elem.x , elem.y });
        }

    }
    return cell.size();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //Задание 4
    cout << Length(0, 0, 2, 2) << endl
        << TriangleArea(3, 2, 3) << endl;

    Point a = { 0,0 };
    Point b = { 4,4 };
    Point c = { 0,4 };
    cout << Length(a, b) << endl
        << TriangleArea(a, b, c) << endl
        << AmountPoints(a, b) << endl;

    vector<Point> points = { {0,0} , {0.5,0.5} , {0.1,0.5} , {5,0.5} , {2.1,0.1} };
    cout << AmountСells(points, 1) << endl;

    cout << Palindrom("123 abc cba 321");
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