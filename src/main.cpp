#include "Core/GTDependencies.h"
#include "Core/GTAssets.h"
#include "Core/GTGame.h"
#include "Utils/GTUtils.h"

using namespace std;
using namespace sf;
using namespace ssvu;
using namespace ssvs;
using namespace gt;

int main()
{
	setRandomSeed();

	unsigned int width{VideoMode::getDesktopMode().width}, height{VideoMode::getDesktopMode().height};
	//width = 1440; height = 900;

	GTAssets assets;
	GameWindow gameWindow{"SSVGenetic", createStaticTimer(gameWindow, 1.0f, 0.5f, 800), width, height, 1, true};
	GTGame game{gameWindow, assets};

	gameWindow.setGameState(game.getGameState());
	gameWindow.run();

	return 0;
}
