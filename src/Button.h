#ifndef _SGFS_BUTTON_H
#define _SGFS_BUTTON_H

#include <SDL2/SDL.h>
#include <string>
#include <yaml-cpp/yaml.h>

#include "Label.h"
#include "commonFunction.h"

using std::string;

enum SGFS_BUTTON_STATE
{
    SGFS_BUTTON_NORMAL,
    SGFS_BUTTON_OVER,
    SGFS_BUTTON_DOWN,
    SGFS_BUTTON_ALL
};

enum SGFS_BUTTON_ACTION
{
    SGFS_BUTTON_MOVE_IN,
    SGFS_BUTTON_MOVE_OUT,
    SGFS_BUTTON_PRESS_DOWN,
    SGFS_BUTTON_PRESS_UP,
    SGFS_BUTTON_ACTION_ALL
};

typedef void (*callback)(void* param,void* output);

class SGFS_Button
{
    private:
    SDL_Rect            mArea;
    string              mText;
    SDL_Renderer*       mRenderer;
    SGFS_Label          mLabel;
    SDL_Texture*        mTextures[SGFS_BUTTON_ALL];
    SGFS_BUTTON_STATE   mCurrentState;
    SGFS_BUTTON_STATE   mLastState;
    SDL_Color           mBackgroundColor;
    SGFS_BUTTON_ACTION  mAction;
    callback            mActionCallbacks[SGFS_BUTTON_ACTION_ALL];
    void*               mInputParam[SGFS_BUTTON_ACTION_ALL];
    void*               mOutputParam[SGFS_BUTTON_ACTION_ALL];

    int                 mRad;
    public:

    SGFS_Button();

    SGFS_Button(SDL_Renderer* renderer,string text);

    void handleInput(SDL_Event event);

    void loadMedia(SDL_Renderer* renderer,string text,YAML::Node configure);

    void update();

    void render();

    void setSize(int width,int height);

    void setPos(int x,int y);
};


#endif