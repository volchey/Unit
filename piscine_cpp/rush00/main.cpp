
#include "src/Game.hpp"

int main()
{
	system("afplay music/music.mp3 &");
	Game	game;
	game.start();
	system("pkill afplay");

    return 0;
}