//Test program 

//Include local headers
#include "game_engine.h" //Game engine
#include "textmenuItem.h" //Text menu item
#include "compositemenu.h" //Menu

vector <string> menuItems = {"Start", "Load", "Options", "Help", "About" "Exit"}; //This is the main menu items list

using namespace std;

int main(int argc, char* argv[])
{
    //Initialize the game engine
    GameEngine& game = GameEngine::getInstance();
    game.init();

    //Create the main menu
    Menu* mainMenu = new CompositeMenu(game.getRenderer());
    for (unsigned long i = 0; i < menuItems.size(); i++) //use unsigned long to avoid compiler warning
    {
        mainMenu->addMenuItem(unique_ptr<Menu>(new TextMenuItem(game.getRenderer(), menuItems[i])));
    }
    
    //Run the game
    game.run();

    //Quit the game engine
    game.quit();
    return 0;
}