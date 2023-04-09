#include "iconmenuItem.h"

IconMenuItem::IconMenuItem(SDL_Renderer* renderer, string iconPath)
{
    this->renderer = renderer;
    icon = IMG_LoadTexture(renderer, iconPath.c_str());
}

IconMenuItem::~IconMenuItem()
{
    //dtor
}

void IconMenuItem::addMenuItem(unique_ptr<Menu> item)
{
    //Do nothing
}

void IconMenuItem::show()
{
    //Do nothing
}

