#include "rectangle.h"
#include <string>
int main() {
	string cmd;
	while (cin >> cmd, cmd != "quit") {
		if (cmd == "square") {
			int width;
			cin >> width;
			Square square(width);
			square.print();
		}
		else if (cmd == "nonsquare") {
			int width, height;
			cin >> width >> height;
			NonSquare nonsquare(width, height);
			nonsquare.print();
		}
	}
}