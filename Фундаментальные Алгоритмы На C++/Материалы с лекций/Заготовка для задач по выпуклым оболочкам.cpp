// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <stack>

struct point
{
	double x, y;
	bool operator<(point &arg) const
	{
		return x*arg.y - y*arg.x > 0;
	}
	point operator+(point &p) const
	{
		return point{ x + p.x, y + p.y };
	}
	point operator-(point &p) const
	{
		return point{ x - p.x, y - p.y };
	}
};

std::vector<point> convex_hull(const std::vector<point> &P)
{
	auto p = P;
	if (p.size() < 4)
		return p;

	//поиск нижней точки и перестановка ее на 0ую позицию
	auto it = std::min_element(p.begin(), p.end(), [](point a, point b){return a.y < b.y; });
	std::iter_swap(it, p.begin());

	//сортировка точек по полярному углу
	for (int i = 1; i < p.size(); ++i)
		p[i] = p[i] - p[0];
	std::sort(p.begin() + 1, p.end());

	//обход √рехема
	std::stack<point> s;
	s.push({ 0, 0 });
	s.push(p[1]);
	int k = 2;
	while (k < p.size())
	{
		auto b = s.top();
		s.pop();
		auto a = s.top();
		if (b - a < p[k] - b)
		{
			s.push(b);
			s.push(p[k++]);
		}
	}

	std::vector<point> res;
	while (s.size())
	{
		res.push_back(s.top()+p[0]);
		s.pop();
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

