#ifndef COMPOSITE_MENU_H
#define COMPOSITE_MENU_H

#include <vector> // Include vector class
#include "menu.h"

//Class for composite menu which contains different menu items (text, icon, etc.)
class CompositeMenu : public Menu
{
public:
    CompositeMenu(SDL_Renderer* renderer);
    virtual ~CompositeMenu();
    void addMenuItem(unique_ptr<Menu> item) override;
    void show() override;

private:
    SDL_Renderer* renderer;
    vector<unique_ptr<Menu>> items;
};

#endif // COMPOSITE_MENU_H