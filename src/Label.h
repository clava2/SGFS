#ifndef _SGFS_H
#define _SGFS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>

using std::string;

class SGFS_Label
{
    private:
    string          mText;
    SDL_Renderer*   mRenderer;
    SDL_Texture*    mTextTexture;
    TTF_Font*       mFont;
    int             mFontSize;
    SDL_Color       mTextColor;

    SDL_Rect        mDstArea;

    int             mDefaultWidth;
    int             mDefaultHeight;

    public:

    SGFS_Label();

    SGFS_Label(SDL_Renderer* renderer,string text);

    void loadMedia(SDL_Renderer* renderer = NULL,string text = "Label");

    void setTextColor(int r,int g,int b,int a);

    void update();

    void render();

    void setArea(int x,int y,int width = -1,int height = -1);

    void setCenter(int x,int y,int width = -1,int height = -1);

};

#endif