#include <iostream>
#include "BasicRoom.h"
#include "game.h"

int main() {
	Game* game = new Game(std::pair<unsigned, unsigned>(768,512));
	game->run();
	return 0;
}
