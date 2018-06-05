#include "game.h"

void Game::run() 
{
	while (mWindow.isOpen()) 
	{
		processEvents();
		update();
		render();
	}
}

Game::Game(std::pair<unsigned, unsigned> windowSize) : mWindow(sf::VideoMode(windowSize.first, windowSize.second), "Beowulf")
{
	world = new World(*this, 
	"../saves/sv1.sav",
	std::vector<EntityFactory*>({new LocalEntityFactory<BasicEntity>()}),
	std::vector<ItemFactory*>(),
	std::vector<EffectFactory*>(),
	std::vector<RoomFactory*>({new LocalRoomFactory<BasicRoom>()}),
	*static_cast<WorldGenerator*>(NULL));
	
}
void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        //Close the window if the game is terminated
	if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::update() 
{

}

void Game::render() {
	mWindow.clear();

	//TODO: Render everything on the screen.

	mWindow.display();
}


sf::SoundBuffer& Game::getSound(std::string soundname)
{
	for (int i = 0; i < gameSounds.size(); i++)
	{
		if (soundname == gameSounds[i].first)
		{
			return *(gameSounds[i].second);
		}
	}
	exit(1);
}

sf::Texture& Game::getTexture(std::string texturename)
{
	
	for (int i = 0; i < gameTextures.size(); i++)
	{
		if (texturename == gameTextures[i].first)
		{
			return *(gameTextures[i].second);
		}
	}
	exit(1);
}