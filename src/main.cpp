#include <iostream>
#include <SDL.h> //Simple DirectMedia Layer: this is a cross-platform library for graphics, audio, and input handling. We'll be using this to do a bit of the heavy lifting for us (Since we dont want to go write code to handle transforms, audio, etc.)

//main functionality of the engine -> any games built in this engine will be using most of this functionality
int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("My cool new demo game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    //if window is null, we cant run the game, exit out
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // This is our main Game-loop
    bool quit = false;
    while (!quit) {
        // todo: Handle all input, update game state, render graphics, etc.
        // ...

        // Some basic event-handling. This one just checks for when someone wants to quit the game, then we continue out and destroy the window object and ultimately exit the game
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
