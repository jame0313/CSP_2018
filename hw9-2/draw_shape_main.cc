// draw_shape_main.cc
#include <iostream>
#include <string>
#include <vector>
#include "draw_shape.h"

using namespace std;

int main() {
	vector<Shape*> shapes;

	size_t row, col;
	cin >> row >> col;
	Canvas canvas(row, col);
	canvas.Print();

	while (true) {
		string tok;
		cin >> tok;
		if (tok == "add") {
			string type;
			cin >> type;
			if (type == "rect") {
				int xpos, ypos, width, height;
				char brush;
				cin >> xpos >> ypos >> width >> height >> brush;
				shapes.push_back(new Rectangle(xpos, ypos, width, height, brush));
			}
			else if (type == "tri_up") {
				int xpos, ypos, height;
				char brush;
				cin >> xpos >> ypos >> height >> brush;
				shapes.push_back(new UpTriangle(xpos, ypos, height, brush));
			}
			else if (type == "tri_down") {
				int xpos, ypos, height;
				char brush;
				cin >> xpos >> ypos >> height >> brush;
				shapes.push_back(new DownTriangle(xpos, ypos, height, brush));
			}
			else if (type == "diamond") {
				int xpos, ypos, radius;
				char brush;
				cin >> xpos >> ypos >> radius >> brush;
				shapes.push_back(new Diamond(xpos, ypos, radius, brush));
			}
			else continue;
		}
		else if (tok == "draw") {
			canvas.Clear();
			for (int i = 0; i < shapes.size(); ++i) shapes[i]->Draw(&canvas);
			canvas.Print();
		}
		else if (tok == "delete") {
			int number;
			cin >> number;
			if (0 <= number && number < shapes.size()) shapes.erase(shapes.begin()+number);
		}
		else if (tok == "dump") {
			for (int i = 0; i < shapes.size(); ++i) {
				cout << i << ' ';
				shapes[i]->Print();
				cout << endl;
			}
		}
		else if (tok == "resize") {
			int row, col;
			cin >> row >> col;
			canvas.Resize(row, col);
		}
		else {
			break;
		}
	}

	for (int i = 0; i < shapes.size(); ++i) delete shapes[i];
	shapes.clear();
	return 0;
}
