#ifndef _Matrix
#define _Matrix
#include <vector> 
#include "glut.h"
using namespace std;

class Matrix {
	int width, height;
	vector<vector <int> > table_r;
	vector<vector <int> > table_g;
	vector<vector <int> > table_b;
	vector<vector <int> > table_bin;

	vector<vector <int> > erase;
	vector<vector <int> > table_show_border_ext;
	vector<vector <int> > table_show_border;
public:
	void show_bin();
	void matrix_bin_transform();
	void show_border();
	void resize(int _width, int _height);
	void setr(int x, int y, int color);
	void setg(int x, int y, int color);
	void setb(int x, int y, int color);
	int getr(int x, int y);
	int getg(int x, int y);
	int getb(int x, int y);
};
#endif