#include "Label.h"

SGFS_Label::SGFS_Label()
{
    mDstArea.x = 0;mDstArea.y = 0;mDstArea.w = -1;mDstArea.h = -1;
}

SGFS_Label::SGFS_Label(SDL_Renderer* renderer,string text)
{
    mDstArea.x = 0;mDstArea.y = 0;mDstArea.w = -1;mDstArea.h = -1;
    mRenderer = renderer;
    mFont = TTF_OpenFont("resource/default_font.otf",20);
    SDL_Surface* surface = TTF_RenderUTF8_Blended(mFont,text.c_str(),mTextColor);
    mTextTexture = SDL_CreateTextureFromSurface(mRenderer,surface);
    SDL_FreeSurface(surface);
}

void SGFS_Label::loadMedia(SDL_Renderer* renderer,string text)
{
    mRenderer = renderer;
    mFont = TTF_OpenFont("resources/default_font.ttf",20);
    SDL_Surface* surface = TTF_RenderUTF8_Blended(mFont,text.c_str(),mTextColor);
    mDefaultWidth = surface->w;
    mDefaultHeight = surface->h;
    if(mDstArea.w == -1)
    {
        mDstArea.w = mDefaultWidth;
    }
    if(mDstArea.h == -1)
    {
        mDstArea.h = mDefaultHeight;
    }
    mTextTexture = SDL_CreateTextureFromSurface(mRenderer,surface);
    if(!mTextTexture)
    {
        SDL_Log("Error While Loading Text Texture");
    }
    SDL_FreeSurface(surface);
}

void SGFS_Label::update()
{
    return;
}

void SGFS_Label::render()
{
    SDL_RenderCopy(mRenderer,mTextTexture,NULL,&mDstArea);
}

void SGFS_Label::setArea(int x,int y,int width,int height)
{
    mDstArea.x = x;
    mDstArea.y = y;
    if(width > -1)
    {
        mDstArea.w = width;
    }
    if(height > 0)
    {
        mDstArea.h = height;
    }
}

void SGFS_Label::setTextColor(int r,int g,int b,int a)
{
    mTextColor.r = r;
    mTextColor.g = g;
    mTextColor.b = b;
    mTextColor.a = a;
}

void SGFS_Label::setCenter(int x,int y,int width,int height)
{
    if(width > -1)
    {
        mDstArea.w = width;
    }
    if(height > 0)
    {
        mDstArea.h = height;
    }
    SDL_Log("mDstArea.w = %d,mDstArea.h = %d",mDstArea.w,mDstArea.h);
    mDstArea.x = x - mDstArea.w/2;
    mDstArea.y = y - mDstArea.h/2;
}