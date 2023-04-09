#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h> // Include SDL2

using namespace std;

//Abstract class for menu
class Menu
{
public:
    Menu() {};
    virtual ~Menu() = 0;
    virtual void addMenuItem(unique_ptr<Menu> item) = 0;
    virtual void show() = 0;
private:
    SDL_Renderer* renderer;
};

#endif // MENU_H