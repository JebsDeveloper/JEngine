#include "Game.h"

#include <stdexcept>

int main(int argc, char* argv[]) {
	Game game = Game();

	try {
		game.run();
	} catch (std::exception e) {
		std::cerr << "An Exception Occurred: " << e.what() << ".\n";
	}

	return 0;
}
