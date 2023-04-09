#include "textmenuItem.h"

TextMenuItem::TextMenuItem(SDL_Renderer* renderer, string text)
{
    this->renderer = renderer;
    this->text = text;
}

TextMenuItem::~TextMenuItem()
{
    //dtor
}

void TextMenuItem::addMenuItem(unique_ptr<Menu> item)
{
    //Do nothing
}

void TextMenuItem::show()
{
    //Do nothing
}
