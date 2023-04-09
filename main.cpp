//Test program 

//Include local headers
#include "game_engine.h"
#include "menu.h"

using namespace std;

int main(int argc, char* argv[])
{
    //Initialize the game engine
    GameEngine& game = GameEngine::getInstance();
    game.init();

    //Create the menu
    Menu menu;
    
    //Run the game
    game.run();

    //Quit the game engine
    game.quit();
    return 0;
}