#include "Matrix.h"

void Matrix::show_bin() {
	glBegin(GL_POINTS);
	glPointSize(1);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (table_bin[x][y] == 1) {
				glColor3f(1, 1, 1);
			}
			else {
				glColor3f(0, 0, 0);
			}
			glVertex2d(x, y);
		}
	}
	glEnd();
	glFlush();
}

void Matrix::matrix_bin_transform() {

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int r = table_r[x][y];
			if (r > 127) r = 255; else r = 0;

			int g = table_g[x][y];
			if (g > 127) g = 255; else g = 0;

			int b = table_b[x][y];
			if (b > 127) b = 255; else b = 0;
			if (r == 0 && b == 0 && g == 0) {
				table_bin[x][y] = 0;
			}
			else {
				table_bin[x][y] = 1;
			}
		}

	}
}
void Matrix::show_border() {
	glBegin(GL_POINTS);
	glPointSize(1);
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			if (
				table_bin[x - 1][y + 1] == 1 && table_bin[x][y + 1] == 1 && table_bin[x + 1][y + 1] == 1 &&
				table_bin[x - 1][y] == 1 && table_bin[x][y] == 1 && table_bin[x + 1][y] == 1 &&
				table_bin[x - 1][y - 1] == 1 && table_bin[x][y - 1] == 1 && table_bin[x + 1][y - 1] == 1
				) {
				glColor3f(0, 0, 0);
				glVertex2d(x - 1, y + 1); glVertex2d(x, y + 1); glVertex2d(x + 1, y + 1);
				glVertex2d(x - 1, y); glVertex2d(x, y); glVertex2d(x + 1, y);
				glVertex2d(x - 1, y - 1); glVertex2d(x, y - 1); glVertex2d(x + 1, y - 1);

				table_show_border[x - 1][y + 1] = 0;  table_show_border[x][y + 1] = 0; table_show_border[x + 1][y + 1] = 0;
				table_show_border[x - 1][y] = 0; table_show_border[x][y] = 0; table_show_border[x + 1][y] = 0;
				table_show_border[x - 1][y - 1] = 0; table_show_border[x][y - 1] = 0; table_show_border[x + 1][y - 1] = 0;
			}
			else {
				if (table_bin[x][y] == 1) {
					glColor3f(1, 1, 1);
					table_show_border[x - 1][y + 1] = 1;  table_show_border[x][y + 1] = 1; table_show_border[x + 1][y + 1] = 1;
					table_show_border[x - 1][y] = 1; table_show_border[x][y] = 1; table_show_border[x + 1][y] = 1;
					table_show_border[x - 1][y - 1] = 1; table_show_border[x][y - 1] = 1; table_show_border[x + 1][y - 1] = 1;
				}
				else {
					glColor3f(0, 0, 0);
					table_show_border[x - 1][y + 1] = 0;  table_show_border[x][y + 1] = 0; table_show_border[x + 1][y + 1] = 0;
					table_show_border[x - 1][y] = 0; table_show_border[x][y] = 0; table_show_border[x + 1][y] = 0;
					table_show_border[x - 1][y - 1] = 0; table_show_border[x][y - 1] = 0; table_show_border[x + 1][y - 1] = 0;
				}
				glVertex2d(x, y);
				glVertex2d(x - 1, y + 1); glVertex2d(x, y + 1); glVertex2d(x + 1, y + 1);
				glVertex2d(x - 1, y); glVertex2d(x, y); glVertex2d(x + 1, y);
				glVertex2d(x - 1, y - 1); glVertex2d(x, y - 1); glVertex2d(x + 1, y - 1);
			}
		}
	}
	glEnd();
	glFlush();
}

void Matrix::resize(int _width, int _height)
{
	height = _height;
	width = _width;

	table_r.assign(width, vector<int>(height));
	table_g.assign(width, vector<int>(height));
	table_b.assign(width, vector<int>(height));
	erase.assign(width, vector<int>(height, 0));
	table_show_border_ext.assign(width, vector<int>(height, 0));
	table_show_border.assign(width, vector<int>(height, 0));


	table_bin.assign(width, vector<int>(height, 1));
}

void Matrix::setr(int x, int y, int color) { table_r[x][y] = color; }
void Matrix::setg(int x, int y, int color) { table_g[x][y] = color; }
void Matrix::setb(int x, int y, int color) { table_b[x][y] = color; }
int Matrix::getr(int x, int y) { return table_r[x][y]; }
int Matrix::getg(int x, int y) { return table_g[x][y]; }
int Matrix::getb(int x, int y) { return table_b[x][y]; }