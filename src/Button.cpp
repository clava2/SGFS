#include <SDL2/SDL2_gfxPrimitives.h>
#include "Button.h"

SGFS_Button::SGFS_Button()
{
    mCurrentState = SGFS_BUTTON_NORMAL;
    for(int i = 0;i != SGFS_BUTTON_ACTION_ALL;i++)
    {
        mActionCallbacks[i] = NULL;
    }
    mRad = 10;
    mArea.x = 0;mArea.y = 0;mArea.w = 100;mArea.h = 40;
}

SGFS_Button::SGFS_Button(SDL_Renderer* renderer,string text):
mLabel(renderer,text)
{
    mArea.x = 0;mArea.y = 0;mArea.w = 100;mArea.h = 40;
    mBackgroundColor.r = 0;mBackgroundColor.g = 0xff;mBackgroundColor.b = 0x00;mBackgroundColor.a = 0xff;
    mRenderer = renderer;
    mText = text;
    mRad = 10;
}

void SGFS_Button::update()
{
    switch(mCurrentState)
    {
        case SGFS_BUTTON_NORMAL:
        mBackgroundColor = {0xff,0x00,0x00,0xff};
        break;
        case SGFS_BUTTON_OVER:
        mBackgroundColor = {0x00,0xff,0x00,0xff};
        break;
        case SGFS_BUTTON_DOWN:
        mBackgroundColor = {0x00,0x00,0xff,0xff};
        break;
    }
    return;
}

void SGFS_Button::render()
{
    // SDL_SetRenderDrawColor(mRenderer,mBackgroundColor.r,mBackgroundColor.g,mBackgroundColor.b,mBackgroundColor.a);
    // SDL_RenderFillRect(mRenderer,&mArea);
    roundedBoxRGBA(mRenderer,mArea.x,mArea.y,mArea.x + mArea.w,mArea.y + mArea.h,mRad,mBackgroundColor.r,mBackgroundColor.g,mBackgroundColor.b,mBackgroundColor.a);
    mLabel.render();
}


void SGFS_Button::loadMedia(SDL_Renderer* renderer,string text,YAML::Node configure)
{
    mBackgroundColor.r = 0;mBackgroundColor.g = 0xff;mBackgroundColor.b = 0x00;mBackgroundColor.a = 0xff;
    mRenderer = renderer;
    mText = text;
    mLabel.setTextColor(0x00,0xff,0x00,0xff);
    mLabel.loadMedia(mRenderer,text);
    mLabel.setCenter(mArea.x + mArea.w/2,mArea.y + mArea.h/2);
}



void SGFS_Button::handleInput(SDL_Event event)
{
    SDL_Point point;
    switch(event.type)
    {
        case SDL_MOUSEMOTION:
        {
            if(mCurrentState == SGFS_BUTTON_DOWN)
            {
                break;
            }
            point = {event.motion.x,event.motion.y};
            if(isPointInRect(point,mArea))
            {
                mCurrentState = SGFS_BUTTON_OVER;
                if((mLastState == SGFS_BUTTON_NORMAL) && (mActionCallbacks[SGFS_BUTTON_MOVE_IN]))
                {
                    mActionCallbacks[SGFS_BUTTON_MOVE_IN](mInputParam[SGFS_BUTTON_MOVE_IN],mOutputParam[SGFS_BUTTON_MOVE_OUT]);
                }
                mLastState = SGFS_BUTTON_OVER;
            }
            else
            {
                mCurrentState = SGFS_BUTTON_NORMAL;
                if((mLastState == SGFS_BUTTON_OVER) && (mActionCallbacks[SGFS_BUTTON_MOVE_OUT]))
                {
                    mActionCallbacks[SGFS_BUTTON_MOVE_OUT](mInputParam[SGFS_BUTTON_MOVE_OUT],mOutputParam[SGFS_BUTTON_MOVE_OUT]);
                }
                mLastState = SGFS_BUTTON_NORMAL;
            }
        }
        break;
        case SDL_MOUSEBUTTONDOWN:
        {
            point = {event.button.x,event.button.y};
            if(isPointInRect(point,mArea))
            {
                if(mCurrentState == SGFS_BUTTON_DOWN)
                {
                    break;
                }
                mCurrentState = SGFS_BUTTON_DOWN;
                if((mLastState == SGFS_BUTTON_NORMAL) && (mActionCallbacks[SGFS_BUTTON_PRESS_DOWN]))
                {
                    mActionCallbacks[SGFS_BUTTON_PRESS_DOWN](mInputParam[SGFS_BUTTON_PRESS_DOWN],mOutputParam[SGFS_BUTTON_PRESS_DOWN]);
                }
                mLastState = SGFS_BUTTON_DOWN;
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            point = {event.button.x,event.button.y};
            if((mCurrentState == SGFS_BUTTON_NORMAL) || (mCurrentState == SGFS_BUTTON_OVER) )
            {
                break;
            }
            if((mLastState == SGFS_BUTTON_DOWN) && (mActionCallbacks[SGFS_BUTTON_PRESS_DOWN]))
            {
                mActionCallbacks[SGFS_BUTTON_PRESS_UP](mInputParam[SGFS_BUTTON_PRESS_UP],mOutputParam[SGFS_BUTTON_PRESS_UP]);
            }
            if(isPointInRect(point,mArea))
            {
                mCurrentState = SGFS_BUTTON_OVER;
            }
            else
            {
                mCurrentState = SGFS_BUTTON_NORMAL;
            }
            mLastState = SGFS_BUTTON_NORMAL;
            break;
        }
    }
}

void SGFS_Button::setSize(int width,int height)
{
    mArea.w = width;
    mArea.h = height;
    mLabel.setCenter(mArea.x + mArea.w/2,mArea.y + mArea.h/2);
}

void SGFS_Button::setPos(int x,int y)
{
    mArea.x = x;
    mArea.y = y;
    mLabel.setCenter(mArea.x + mArea.w/2,mArea.y + mArea.h/2);
}