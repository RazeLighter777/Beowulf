#ifndef GAME
#define GAME

#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//The root object of the game. Handles rendering objects to the screen, playing sounds,
//processing input, and handling events.

class Game {
public:

	//Initializes the game at the given window size.
	Game(std::pair<unsigned, unsigned> windowSize);

	//Begin the game loop
	void run();

	//Returns the texture named by the string.
	sf::Texture& getTexture(std::string textureName);

	//Returns the sound named by the string.
	sf::SoundBuffer& getSound(std::string soundname);



private:

	//Runs the game menu loop
	void runGameMenu();

	//Process the events created by the player(s)
	void processEvents();

	//Update the game accordingly
	void update(); 

	//Render the games objects to the screen
	void render();

private:

	//The window in which the game will draw itself.
	sf::RenderWindow mWindow;
	//The vector of pointers to sound buffers. The sound buffer will be managed to keep it under size.
	std::vector<sf::SoundBuffer*> gameSounds;
	//The vector of pointers to game textures. The textures will be managed to keep it under size.
	std::vector<sf::Texture*> gameTextures;


};
#endif
