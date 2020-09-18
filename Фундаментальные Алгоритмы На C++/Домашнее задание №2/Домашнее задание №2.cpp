#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//Задание 1
//Не рекомендую брать этот способ(Лепчинский на него выеживается), но лучше я не придумал
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

//Задание 2
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

int AmountСells(const vector<Point>& points, double sizeCell)
{
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

//Задание 3
template <typename type>

vector<type> AdjacentFind(const vector<type>& vec)
{
	if (vec.size() < 2)
		return vector<type>(0);

	for (int i = 0; i < vec.size() - 1; i++)
		if (vec[i] == vec[i + 1]) return vector<type>(2) = { vec[i], vec[i + 1] };
	return vector<type>(0);
}

//Задание 4
template <typename type>

bool Sorted(const vector<type>& vec)
{
	if (vec.size() < 2)
		return true;

	for (int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] > vec[i + 1]) return false;
	}
	return true;
}

//Задание 5
template <typename type>

int ValueCount(const vector<type>& vec, type value)
{
	int count = 0;
	for (auto elem : vec) {
		if (elem == value) count++;
	}
	return count;
}

//Задание 6
template <typename type>

bool PermutatedArrays(const vector<type>& vecFirst, const vector<type>& vecSecond)
{
	vector<type> copyFirst = vecFirst;
	vector<type> copySecond = vecSecond;

	if (!Sorted(copyFirst)) sort(copyFirst.begin(), copyFirst.end());
	if (!Sorted(copySecond)) sort(copySecond.begin(), copySecond.end());
	return copyFirst == copySecond ? true : false;
}

int main()
{
	vector<int> vec{ 3, 1 };
	vector<int> vecPermutated{ 3, 3, 3, 1, 1, 1, 2 };
	//Задание 3
	//AdjacentFind(vector<int>(0) = { });
	//Задание 4
	cout << Sorted(vec) << endl;
	//Задание 5
	cout << ValueCount(vec, 1) << endl;
	//Задание 6
	cout << PermutatedArrays(vec, vecPermutated) << endl;
	system("pause");
	return 0;
}
/*
1. Написать функцию, определяющую длину наибольшего палиндрома внутри заданной строки(Повтор из прошлого дз)
2. Написать функцию, вычисляющую кол - во клеток которые проткнули иглой(Повтор из прошлого дз)
3. Написать шаблонную функцию AdjacentFind для отыскания в заданном массиве пары одинаковых рядом стоящих значений
4. Написать шаблонную функцию Sorted, проверяющую переданный массив на упорядоченность
5. Написать шаблонную функцию ValueCount, подсчитывающую количество вхождений заданного элемента в массив
6. Написать шаблонную функцию PermutatedArrays, проверяющую, что два переданных массива являются перестановками друг друга
*/
