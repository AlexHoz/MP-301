#include "stdafx.h"
#include <string>
#include <stack>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <random>

std::mt19937 mtrand;

const int default_max_count = 50000;

template <typename T>
class stackm
{
	T* m;
	int count;
public:
	stackm(int max_count = default_max_count);
	~stackm();
	void push(const T& elem);
	void pop();
	T& top();
	int size() const;
	void swap(stackm<T> &arg) { std::swap(count, arg.count); std::swap(m, arg.m); }
};

namespace std
{
	template<typename T>
	void swap(stackm<T> &a, stackm<T> &b)
	{
		a.swap(b);
	}
}

template <typename T>
stackm<T>::stackm(int max_count)
{
	count = 0;
	m = new T[max_count];
}

template <typename T>
stackm<T>::~stackm()
{
	delete[] m;
}

template <typename T>
void stackm<T>::pop()
{
	--count;
}

template <typename T>
void stackm<T>::push(const T& elem)
{
	m[count++] = elem;
}

template <typename T>
T& stackm<T>::top()
{
	return m[count - 1];
}

template <typename T>
int stackm<T>::size() const
{
	return count;
}

template <typename T>
class stackl
{
	struct node
	{
		T data;
		node* next;
	};
	node* Top;
	int count;
public:
	stackl();
	~stackl();
	void push(const T& elem);
	void pop();
	T& top();
	int size() const;
	void swap(stackl<T> &arg) { std::swap(count, arg.count); std::swap(Top, arg.Top); }
};

namespace std
{
	template<typename T>
	void swap(stackl<T> &a, stackl<T> &b)
	{
		a.swap(b);
	}
}

template <typename T>
stackl<T>::stackl()
{
	count = 0;
	Top = nullptr;
}

template <typename T>
void stackl<T>::push(const T& elem)
{
	++count;
	Top = new node{ elem, Top };
}

template <typename T>
void stackl<T>::pop()
{
	auto p = Top->next;
	delete Top;
	Top = p;
	--count;
}

template <typename T>
int stackl<T>::size() const
{
	return count;
}

template <typename T>
T& stackl<T>::top()
{
	return Top->data;
}

template <typename T>
stackl<T>::~stackl()
{
	while (count)
		pop();
}

template <typename Stack>
void move_top(Stack& src, Stack& dest)
{
	dest.push(src.top());
	src.pop();
}

template <typename Stack>
void move_stack(Stack& src, Stack& dest)
{
	while (src.size())
		move_top(src, dest);
}

template <typename Stack>
bool EqualStacks(Stack& s1, Stack& s2)
{
	if (s1.size() != s2.size())
		return false;
	Stack s1_copy, s2_copy;
	bool res = true;
	while (s1.size())
	{
		if (s1.top() != s2.top())
		{
			res = false;
			break;
		}
		move_top(s1, s1_copy);
		move_top(s2, s2_copy);
	}
	move_stack(s1_copy, s1);
	move_stack(s2_copy, s2);
	return res;
}

template <typename Stack>
void dumb_sort_stack(Stack& s)
{
	if (s.size() <= 1)
		return;
	Stack res, tmp;
	while (s.size())
	{
		move_top(s, res);
		while (s.size())
			if (s.top() < res.top())
			{
				move_top(res, tmp);
				move_top(s, res);
			}
			else
				move_top(s, tmp);
		move_stack(tmp, s);
	}
	move_stack(res, s);
}

template <typename Stack>
void quick_sort_stack(Stack& s)
{
	if (s.size() <= 1)
		return;
	Stack L, G, E;
	//auto e = s.top();
	int n = mtrand()%s.size();
	for (int i = 0; i<n; ++i)
		move_top(s, E);
	auto e = s.top();
	s.pop();
	move_stack(E, s);
	E.push(e);
	
	while (s.size())
	{
		if (s.top() > e)
			move_top(s, G);
		else if (s.top() < e)
			move_top(s, L);
		else
			move_top(s, E);
	}
	quick_sort_stack(L);
	quick_sort_stack(G);
	move_stack(G, E);
	move_stack(E, s);
	move_stack(L, G);
	move_stack(G, s);
}

template <typename Stack>
void merge_stacks(Stack &src1, Stack &src2, Stack &dest)
{
	while (src1.size() && src2.size())
	{
		if (src1.top() < src2.top())
			move_top(src2, dest);
		else
			move_top(src1, dest);
	}
	move_stack(src2, dest);
	move_stack(src1, dest);
}

template <typename Stack>
void extract_sorted_stack(Stack &src, Stack &dest)
{
	if (!src.size())
		return;
	move_top(src, dest);
	while (src.size() && src.top() >= dest.top())
		move_top(src, dest);
}

template <typename Stack>
void merge_sort_stack(Stack &s)
{
	if (s.size()<2) return;
	int k = 0;
	Stack tmp1, tmp2, res;
	do{
		k = 0;
		while (s.size())
		{
			extract_sorted_stack(s, tmp1);
			extract_sorted_stack(s, tmp2);
			merge_stacks(tmp1, tmp2, res);
			++k;
		}
		std::swap(s, res);
	} while (k > 1);
}

template <typename F>
int exec_time(F f)
{
	auto start = GetTickCount();
	f();
	return GetTickCount() - start;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//std::vector<int> numbers{ 12, 4, 5, 9, 1, 0, 7, 3, 8, 1, 2, 9, 7, 5, 3, 0, 6 };
	std::vector<int> numbers;
	for (int i = 0; i < 50000; ++i)
		numbers.push_back(rand());

	stackm<int> sm;
	stackl<int> sl;
	std::stack<int> s;
	for (auto e : numbers)
	{
		sm.push(e);
		sl.push(e);
		s.push(e);
	}

	std::cout << "stackm: " << exec_time([&]() {merge_sort_stack(sm); }) << std::endl;
	std::cout << "stackl: " << exec_time([&]() {merge_sort_stack(sl); }) << std::endl;
	std::cout << "stack : " << exec_time([&]() {merge_sort_stack(s); }) << std::endl;

	merge_sort_stack(sm);
	merge_sort_stack(sl);
	merge_sort_stack(s);

	//while (sm.size())
	//{
	//	std::cout << sm.top() << " ";
	//	sm.pop();
	//}
	//std::cout << std::endl;
	//while (sl.size())
	//{
	//	std::cout << sl.top() << " ";
	//	sl.pop();
	//}
	//std::cout << std::endl;
	//while (s.size())
	//{
	//	std::cout << s.top() << " ";
	//	s.pop();
	//}
	//std::cout << std::endl;
	return 0;
}
