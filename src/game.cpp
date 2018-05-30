#include <game.h>

void Game::run() 
{
	while (mWindow.isOpen()) 
	{
		processEvents();
		update();
		render();
	}
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
