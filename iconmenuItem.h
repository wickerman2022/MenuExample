#ifndef ICONMENU_ITEM_H
#define ICONMENU_ITEM_H

#include <SDL2/SDL_image.h>
#include "menu.h"

class IconMenuItem : public Menu
{

public:
    IconMenuItem(SDL_Renderer* renderer, string iconPath);
    virtual ~IconMenuItem();
    void addMenuItem(unique_ptr<Menu> item) override;
    void show() override;

private:
    SDL_Renderer* renderer;
    SDL_Texture* icon;
};

#endif // ICONMENU_ITEM_H