#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> getEulerPath(vector<vector<int>> g)
{
	int index = find_if(g.begin(), g.end(), [](const vector<int> &sp) { return sp.size() % 2 == 1; }) - g.begin();
	stack<int> s;

	if (index < g.size())
		s.push(index);
	else
		s.push(0);

	vector<int> path;
	while (s.size())
	{
		int u = s.top();
		if (g[u].size() == 0)
		{
			path.push_back(u);
			s.pop();
			continue;
		}
		int v = g[u].back();
		g[u].pop_back();
		s.push(v);
		*find(g[v].begin(), g[v].end(), u) = g[v].back();
		g[v].pop_back();
	}
	return path;
}

int main()
{
	vector<vector<int>> g{ { 1, 2 }, { 0, 2, 3 }, { 0, 1, 3, 4 }, { 1, 2, 4 }, {2, 3} };
	for (auto v : getEulerPath(g))
		cout << v << " ";
	cout << endl;
	system("pause");
	return 0;
}
