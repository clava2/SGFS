#include "Game.h"

CGame::CGame()
{
    mQuit = false;
    mConfigurationFilePath = "resources/configurations/theme.yaml";
    mConfigure = YAML::LoadFile(mConfigurationFilePath);

    SDL_Init(SDL_INIT_EVERYTHING);
    mWindow = SDL_CreateWindow("test",0,0,100,100,SDL_WINDOW_FULLSCREEN_DESKTOP);
    mRenderer = SDL_CreateRenderer(mWindow,-1,SDL_RENDERER_ACCELERATED);
    TTF_Init();
    IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
    mMainTimer.start();
    mMainTimer.setFrameRate(60);
}
void CGame::loadMedia()
{
    mButton.loadMedia(mRenderer,"郑聪",mConfigure);
    mSubWindow.loadMedia(mRenderer,mConfigure);


    mButton.setPos(600,600);
    mButton.setSize(100,50);

    return;
}
void CGame::handleInput()
{
    SDL_PollEvent(&mEvent);
    mButton.handleInput(mEvent);
    switch(mEvent.type)
    {
        break;
        case SDL_KEYDOWN:
        if(mEvent.key.keysym.sym == SDLK_ESCAPE)
            mQuit = true;
    }
}
void CGame::update()
{
    mButton.update();
    mSubWindow.update();
    return;
}
void CGame::render()
{
    SDL_SetRenderDrawColor(mRenderer,0x00,0x00,0x00,0x00);
    SDL_RenderClear(mRenderer);
    mButton.render();
    mSubWindow.render();
    SDL_RenderPresent(mRenderer);
}

void CGame::loop()
{
    while(!mQuit)
    {
        mMainTimer.update();
        handleInput();
        update();
        render();
        mMainTimer.lock();
    }
}