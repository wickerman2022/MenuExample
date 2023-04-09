#include "game_engine.h"

//Constructor and destructor
GameEngine::GameEngine() : window(nullptr, SDL_DestroyWindow), renderer(nullptr, SDL_DestroyRenderer), font(nullptr, TTF_CloseFont)
{
    //Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error("SDL2 could not initialize! SDL2 Error: " + std::string(SDL_GetError()));
    }

    //Initialize SDL2_ttf
    if (TTF_Init() < 0)
    {
        throw std::runtime_error("SDL2_ttf could not initialize! SDL2_ttf Error: " + std::string(TTF_GetError()));
    }
}

GameEngine::~GameEngine()
{
    //Quit SDL2_ttf
    TTF_Quit();

    //Quit SDL2
    SDL_Quit();
}

//Initialize the game engine
bool GameEngine::init()
{
    //Create window
    window.reset(SDL_CreateWindow("SDL2 Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN));
    if (window == nullptr)
    {
        throw std::runtime_error("Window could not be created! SDL2 Error: " + std::string(SDL_GetError()));
    }

    //Create renderer for window
    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED));
    if (renderer == nullptr)
    {
        throw std::runtime_error("Renderer could not be created! SDL2 Error: " + std::string(SDL_GetError()));
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);

    //Open the font
    font.reset(TTF_OpenFont("arial.ttf", 28));
    if (font == nullptr)
    {
        throw std::runtime_error("Failed to load font! SDL2_ttf Error: " + std::string(TTF_GetError()));
    }

    return true;
}

//Run the game engine
void GameEngine::run()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        //Update the game
        update(0);

        //Clear screen
        SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer.get());

        //Render red filled quad
        SDL_Rect fillRect = { 240, 190, 100, 100 };
        SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer.get(), &fillRect);

        //Render green outlined quad
        SDL_Rect outlineRect = { 240, 190, 100, 100 };
        SDL_SetRenderDrawColor(renderer.get(), 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderDrawRect(renderer.get(), &outlineRect);

        //Update screen
        SDL_RenderPresent(renderer.get());
    }
}

//Quit the game engine
void GameEngine::quit()
{
    //Destroy window
    window.reset();

    //Quit SDL2_ttf
    TTF_Quit();

    //Quit SDL2
    SDL_Quit();
}

//Game logic
void GameEngine::update(unsigned int dt)
{
    //TODO: Add game logic here
}