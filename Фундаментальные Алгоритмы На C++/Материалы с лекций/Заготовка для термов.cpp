#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
using namespace std;

enum term_t
{
	t_var,
	t_const,
	t_op,
	t_fun,
	t_opbr,
	t_clbr
};

struct term
{
	string name;
	term_t type;

};

vector<term> get_terms_from_expression(const string &s);
vector<term> get_postfix_from_terms(vector<term> &terms);
double calculate_postfix(vector<term> &terms, const map<string, double> &vars);
pair<string, map<string, double>> get_expressing_from_stream(istream &inp);

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

// 0. Получение данных из потока

// 1. Разбиение исходного выражения на термы

// 2. Преобразование в постфиксную запись

// 3. Вычисление постфиксной записи
// map<string, double> vars; - для хранения значений переменных
// map<string, double(*)(stack<double> &s)> ops - для хранения операций