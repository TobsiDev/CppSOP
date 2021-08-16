#include "win.h"

void tRender(const char *progName)
{
    std::cout << progName << std::endl;

    SDL_Event evnt;

    int red = 128;
    int green = 0;
    int blue = 64;
    int alpha = 0;

    bool run = true;

    // returns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        run = false;
    }
    SDL_Window *win = SDL_CreateWindow(progName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    SDL_Renderer *renderer;

    renderer = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
    while (run)
    {
        while (SDL_PollEvent(&evnt) != 0)
        {
            if (evnt.type == SDL_QUIT)
                run = false;
            else if (evnt.type == SDL_KEYDOWN)
            {
                switch (evnt.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    run = false;
                    break;

                    /*//RED UP AND DOWN
                case SDLK_w:
                    if (red < 255)
                        red++;
                    break;
                case SDLK_s:
                    if (red < 255)
                        red--;
                    break;*/

                default:
                    break;
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    std::cout << "The program has stopped." << std::endl;
}

void writeTable()
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