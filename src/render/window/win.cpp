#include "win.h"

// Test color values
const int red = 128;
const int green = 0;
const int blue = 64;
const int alpha = 0;

// Something to draw some lines in the window
void draw(SDL_Renderer *Renderer, int xP1, int xp1, int yp1, int xp2, int yp2)
{
    SDL_SetRenderDrawColor(Renderer, red, green, blue, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(Renderer);
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLine(Renderer, xP1, 180, 90, 30);
    SDL_RenderDrawLine(Renderer, xP1, 280, 100, 130);
    SDL_RenderDrawLine(Renderer, xP1, 380, 110, 230);

    SDL_RenderDrawLine(Renderer, xP1, 380, 320, 30);
    SDL_RenderDrawLine(Renderer, xP1, 380, 110, 230);

    SDL_RenderDrawLine(Renderer, xp1, yp1, xp2, yp2);

    SDL_RenderPresent(Renderer);
}

void tRender(const char *progName)
{
    std::cout << progName << std::endl;

    SDL_Event evnt;

    bool run = true;
    int x1Pos = 320;

    // Draw a line
    bool first = true;
    int xP = 0, yP = 0;
    int xP1 = 0, yP1 = 0;
    int xP2 = 0, yP2 = 0;

    // Returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        run = false;
    }
    SDL_Window *win = SDL_CreateWindow(progName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);

    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    while (run)
    {
        while (SDL_PollEvent(&evnt) != 0)
        {
            if (evnt.type == SDL_QUIT) // If the user presses the [X] window button
                run = false;
            else if (evnt.type == SDL_KEYDOWN) // Keyboard input
            {
                switch (evnt.key.keysym.sym)
                {
                case SDLK_ESCAPE: // Stops the program if ESC is pressed
                    run = false;
                    break;

                case SDLK_w:
                    x1Pos++;
                    break;
                case SDLK_s:
                    x1Pos--;
                    break;

                default:
                    break;
                }
            }
            else if (evnt.type == SDL_MOUSEBUTTONUP) // Mouse input
            {
                Uint32 buttons;
                SDL_PumpEvents(); // Makes sure we have the latest mouse state
                if (first)
                {
                    buttons = SDL_GetMouseState(&xP1, &yP1);
                    SDL_Log("Mouse cursor is at %d, %d", xP1, yP1);
                    first = false;
                }
                else
                {
                    buttons = SDL_GetMouseState(&xP2, &yP2);
                    SDL_Log("Mouse cursor is at %d, %d", xP2, yP2);
                    first = true;
                }
            }
        }

        draw(renderer, x1Pos, xP1, yP1, xP2, yP2); // Some user interaction has been implemented
    }

    SDL_Quit();
    std::cout << "The program has stopped." << std::endl;
}

void writeTable() // Test function
{
    int res = 0;
    for (int i = 1; i < 11; i++)
    {
        for (int n = 1; n < 11; n++)
        {
            res = i * n;
            std::cout << res << " ";
        }
        std::cout << "\n";
    }
}