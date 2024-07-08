#include"Display.hpp"

int main(int argc, char** argv) {
	Display display;
	display.init(argc, argv);
	display.draw();
	return 0;
}
