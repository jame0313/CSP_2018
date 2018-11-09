#include "draw_shape.h"
#include <string>

int main() {
	int canvas_width, canvas_height;
	cin >> canvas_width >> canvas_height;
	string cmd;
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "rect") {
			int xpos, ypos, height, width;
			char brush;
			cin >> xpos >> ypos >> height >> width >> brush;
			Rectangle shape(xpos, ypos, height, width, brush);
			cout << "Area: " << shape.GetArea() << endl;
			cout << "Perimeter: " << shape.GetPerimeter() << endl;
			shape.Draw(canvas_width,canvas_height);
		}
		else if (cmd == "square") {
			int xpos, ypos, width;
			char brush;
			cin >> xpos >> ypos >> width >> brush;
			Square shape(xpos, ypos, width, brush);
			cout << "Area: " << shape.GetArea() << endl;
			cout << "Perimeter: " << shape.GetPerimeter() << endl;
			shape.Draw(canvas_width, canvas_height);
		}
		else if (cmd == "diamond") {
			int xpos, ypos, radius;
			char brush;
			cin >> xpos >> ypos >> radius >> brush;
			Diamond shape(xpos, ypos, radius, brush);
			cout << "Area: " << shape.GetArea() << endl;
			cout << "Perimeter: " << shape.GetPerimeter() << endl;
			shape.Draw(canvas_width, canvas_height);
		}
	}
}