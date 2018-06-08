#include "game.h"

void Game::run() 
{
	while (mWindow.isOpen()) 
	{
		processEvents();
		update();
		render();
		world->saveWorld();
	}
}

Game::Game(std::pair<unsigned, unsigned> windowSize) : mWindow(sf::VideoMode(windowSize.first, windowSize.second), "Beowulf")
{
	world = new World(*this, 
	"../saves/sv1.sav",
	std::vector<EntityFactory*>({new LocalEntityFactory<BasicEntity>(),
	new LocalEntityFactory<Player>()}),
	std::vector<ItemFactory*>(),
	std::vector<EffectFactory*>(),
	std::vector<RoomFactory*>({new LocalRoomFactory<BasicRoom>()}),
	*new TestWorldGenerator());
	
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
	world->update();
}

void Game::render() {
	mWindow.display();
}


sf::SoundBuffer& Game::getSound(std::string soundname)
{
	//Try to find the sound if it's already loaded.
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
	//Try to find the texture if it is already loaded. 	
	for (int i = 0; i < gameTextures.size(); i++)
	{
		if (texturename == gameTextures[i].first)
		{
			return *(gameTextures[i].second);
		}
	}
	sf::Texture* newtexture = new sf::Texture();
	newtexture->loadFromFile(texturename);
	gameTextures.push_back(std::pair<std::string, sf::Texture*>(texturename, newtexture));
	return *newtexture;
	exit(1);
}

sf::RenderWindow& Game::exposeWindow()
{
	return mWindow;
}