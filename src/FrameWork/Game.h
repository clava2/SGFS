#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <yaml-cpp/yaml.h>
#include <string>

#include "Timer.h"
#include "../Button.h"
#include "../Window.h"

class CGame
{
    private:
    CTimer mMainTimer;
    bool    mQuit;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Event mEvent;

    SGFS_Button mButton;

    SGFS_Window mSubWindow;

    YAML::Node mConfigure;

    std::string mConfigurationFilePath;

    public:

    CGame();
    void loadMedia();
    void handleInput();
    void update();
    void render();
    void loop();
};


#endif