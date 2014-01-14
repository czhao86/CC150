#include <iostream>
using namespace std;

enum colors
{
	red, green, blue, yellow
};

bool paint(colors color[][5], int x, int y, colors oc, colors nc)
{
	if (x<0 || x>5) return false;
	if (y<0 || y>5) return false;
	if (color[x][y] == oc)
	{
		color[x][y] = nc;
		paint(color, x - 1, y, oc, nc);
		paint(color, x + 1, y, oc, nc);
		paint(color, x, y - 1, oc, nc);
		paint(color, x, y + 1, oc, nc);
	}
	return true;
}

int main()
{
	colors pic[5][5] = {
		{ red, green, green, blue, yellow },
		{ green, red, yellow, green, green },
		{ green, red, red, blue, green },
		{ red, green, red, green, yellow },
		{ red, yellow, red, blue, yellow }
	};
	for (int i = 0; i<5; ++i){
		for (int j = 0; j<5; ++j)
			cout << pic[i][j] << " ";
		cout << endl;
	}
	paint(pic, 2, 2, red, yellow);
	for (int i = 0; i<5; ++i){
		for (int j = 0; j<5; ++j)
			cout << pic[i][j] << " ";
		cout << endl;
	}
	return 0;
}
