#ifndef TEXTMENU_ITEM_H
#define TEXTMENU_ITEM_H

#include "menu.h"

class TextMenuItem : public Menu
{

public:
    TextMenuItem(SDL_Renderer* renderer, string text);
    virtual ~TextMenuItem();
    void addMenuItem(unique_ptr<Menu> item) override;
    void show() override;
private:
    SDL_Renderer* renderer;
    string text;
};

#endif // TEXTMENU_ITEM_H