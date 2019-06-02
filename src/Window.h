#ifndef _SGFS_WINDOW_H
#define _SGFS_WINDOW_H

#include "Button.h"

class SGFS_Window
{
    private:

    const int SGFS_WINDOW_DEFAULT_WIDTH = 300;
    const int SGFS_WINDOW_DEFAULT_HEIGHT = 300;

    int                 mTitleBarHeight;
    SDL_Color           mTitleBarColor;

    SDL_Renderer*       mRenderer;

    SDL_Point           mPos;
    int                 mWidth;
    int                 mHeight;
    SGFS_Button         mCloseButton;
    SGFS_Button         mSettingButton;
    SGFS_Button         mMaximumButton;
    SGFS_Button         mMinimumButton;
    SGFS_Label          mTitle;

    SDL_Rect            mClientRect;
    SDL_Color           mBackgroundColor;
    SDL_Color           mClientBackgroundColor;

    static SDL_Point    SGFS_WindowInitPos;

    public:

    SGFS_Window();

    SGFS_Window(SDL_Renderer* renderer);

    void handleInput(SDL_Event event);

    void loadMedia(SDL_Renderer* renderer,YAML::Node configure);

    void update();

    void render();

    void YAML_SetTitleBar(YAML::Node configure);
    void YAML_SetMainArea(YAML::Node configure);
    void YAML_SetClientArea(YAML::Node configure);

};


#endif