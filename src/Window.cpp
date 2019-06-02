#include "Window.h"
#include <SDL2/SDL2_gfxPrimitives.h>

SDL_Point SGFS_Window::SGFS_WindowInitPos = {100,100};

SGFS_Window::SGFS_Window()
{
    mRenderer = NULL;
    mPos = SGFS_Window::SGFS_WindowInitPos;
    mWidth = 300;
    mHeight = 300;
    mClientRect = {10,10,280,280};
    mBackgroundColor = {0,0,0xff,0xff};
    mClientBackgroundColor = {0xff,0xff,0xff,0xff};
    SGFS_Window::SGFS_WindowInitPos.x = SGFS_Window::SGFS_WindowInitPos.x + 20;
    SGFS_Window::SGFS_WindowInitPos.y = SGFS_Window::SGFS_WindowInitPos.y + 20;


    mTitleBarHeight = 30;
}

SGFS_Window::SGFS_Window(SDL_Renderer* renderer)
{
    mRenderer = renderer;
    mPos = SGFS_Window::SGFS_WindowInitPos;
    mWidth = 300;
    mHeight = 300;
    mClientRect = {10,10,280,280};
    mBackgroundColor = {0,0,0xff,0xff};
    mClientBackgroundColor = {0xff,0xff,0xff,0xff};
    SGFS_Window::SGFS_WindowInitPos.x = SGFS_Window::SGFS_WindowInitPos.x + 20;
    SGFS_Window::SGFS_WindowInitPos.y = SGFS_Window::SGFS_WindowInitPos.y + 20;

    mTitleBarHeight = 30;
}

void SGFS_Window::handleInput(SDL_Event event)
{
}

void SGFS_Window::loadMedia(SDL_Renderer* renderer,YAML::Node configure)
{
    YAML::Node config = configure["window"];
    
    for(YAML::const_iterator ite = config.begin();ite != config.end();ite ++)
    {
        if(ite->first.as<string>() == "title")
        {
            YAML_SetTitleBar(config["title"]);
        }
        else if(ite->first.as<string>() == "main")
        {
            YAML_SetMainArea(config["main"]);
        }
        else if(ite->first.as<string>() == "client")
        {
            YAML_SetClientArea(config["client"]);
        }
    }
    mRenderer =  renderer;
}

void SGFS_Window::update()
{

}

void SGFS_Window::render()
{
    SDL_Rect titleArea = {mPos.x+1,mPos.y - mTitleBarHeight,mWidth,mTitleBarHeight};

    boxRGBA(mRenderer,titleArea.x,titleArea.y,titleArea.x + titleArea.w,titleArea.y + titleArea.h,
                    mTitleBarColor.r,mTitleBarColor.g,
                    mTitleBarColor.b,mTitleBarColor.a);
    
    boxRGBA(mRenderer,mPos.x,mPos.y,mPos.x + mWidth,mPos.y + mHeight,
                    mBackgroundColor.r,mBackgroundColor.g,
                    mBackgroundColor.b,mBackgroundColor.a);
    boxRGBA(mRenderer,mPos.x + mClientRect.x,mPos.y + mClientRect.y,mPos.x + mClientRect.x + mClientRect.w,mPos.y + mClientRect.y + mClientRect.h,
                    mClientBackgroundColor.r,mClientBackgroundColor.g,
                    mClientBackgroundColor.b,mClientBackgroundColor.a);
    mCloseButton.render();
    // mMinimumButton.render();
    // mMaximumButton.render();
    // mSettingButton.render();
}


void SGFS_Window::YAML_SetTitleBar(YAML::Node configure)
{
    string tempString;
    long tempLong;
    for(YAML::const_iterator ite = configure.begin();ite != configure.end();ite ++)
    {
        if(ite->first.as<string>() == "color")
        {
            YAML::Node inner_configure = configure["color"];
            for(YAML::const_iterator inner_ite = inner_configure.begin();inner_ite != inner_configure.end();++inner_ite)
            {
                if(inner_ite->first.as<string>() == "background")
                {
                    tempString = inner_configure["background"].as<string>();
                    sscanf(tempString.c_str(),"%lx",&tempLong);
                    mTitleBarColor.r = tempLong & 0xff000000 >> 24;
                    mTitleBarColor.g = tempLong & 0x00ff0000 >> 16;
                    mTitleBarColor.b = tempLong & 0x0000ff00 >> 8;
                    mTitleBarColor.a = tempLong & 0x000000ff;
                }
                else if(inner_ite->first.as<string>() == "close")
                {
                }
                else if(inner_ite->first.as<string>() == "minimum")
                {
                }
                else if(inner_ite->first.as<string>() == "maximum")
                {
                }
                else if(inner_ite->first.as<string>() == "frame")
                {
                }
                else
                {
                }
            }
        }
        if(ite->first.as<string>() == "size")
        {
            YAML::Node inner_configure = configure["size"];
            for(YAML::const_iterator inner_ite = inner_configure.begin();inner_ite != inner_configure.end();++inner_ite)
            {
                if(inner_ite->first.as<string>() == "height")
                {
                    mTitleBarHeight = inner_configure["height"].as<long>();
                }
                else if(inner_ite->first.as<string>() == "button-width")
                {
                }
                else if(inner_ite->first.as<string>() == "frame-width")
                {
                }
            }
        }
    }
}

void SGFS_Window::YAML_SetMainArea(YAML::Node configure)
{

}

void SGFS_Window::YAML_SetClientArea(YAML::Node configure)
{

}