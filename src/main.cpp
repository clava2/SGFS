#include "Label.h"

int main(int argc,char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("test",0,0,0,0,SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SGFS_Label label(renderer,"test label");

    

    TTF_Quit();
    SDL_Quit();
}