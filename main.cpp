#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "SDL_Init_Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Surface* bmp = SDL_LoadBMP("/home/stas/qt-creator/projects/sdl2_next/hello.bmp");
    if (bmp == nullptr) {
        cout << "SDL_LoadBMP Error: " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr) {
        cout << "SDL_CreateTextureFromSurface Error " << SDL_GetError() << endl;
        return 1;
    }

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    SDL_Delay(2000);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
