//Simple game engine using SDL2

#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <iostream> 
#include <memory> //For std::unique_ptr
#include <stdexcept> //For std::runtime_error
#include <SDL2/SDL.h> // Include SDL2
#include <SDL2/SDL_ttf.h> //SDL2 TrueType Font

//Singleton class for game engine
class GameEngine
{
public:
    //Get the instance of the game engine
    static GameEngine& getInstance()
    {
        static GameEngine instance;
        return instance;
    }

    //Initialize the game engine
    bool init();

    //Run the game engine
    void run();

    //Quit the game engine
    void quit();

    //Game logic
    void update(unsigned int dt); //dt is the time since the last update in milliseconds

    //get the SDL2 renderer
    SDL_Renderer* getRenderer() const { return renderer.get(); }
private:
    //Private constructor and destructor to prevent multiple instances
    GameEngine();
    ~GameEngine();

    std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window; //SDL2 window
    std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer; //SDL2 renderer
    std::unique_ptr<TTF_Font, void(*)(TTF_Font*)> font; //SDL2 TrueType Font
};

#endif // GAME_ENGINE_H