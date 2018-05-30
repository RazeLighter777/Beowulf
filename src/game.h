#include <utility>
#include <SFML/Graphics.hpp>


//The root object of the game. Handles rendering objects to the screen, playing sounds,
//processing input, and handling events.

class Game {
public:

	//Initializes the game at the given window size.
	Game(std::pair<unsigned, unsigned> windowSize);

	//Begin the game loop
	void run();

private:

	//Process the events created by the player(s)
	void processEvents();

	//Update the game accordingly
	void update(); 

	//Render the games objects to the screen
	void render();

	sf::RenderWindow mWindow;

};
