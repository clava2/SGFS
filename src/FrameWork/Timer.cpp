#include "Timer.h"

CTimer::CTimer()
{
}

Uint32 CTimer::getCurrentTime()
{
    return SDL_GetTicks() - mStartTime;
}
void CTimer::start()
{
    mStartTime = SDL_GetTicks();
}
void CTimer::pause()
{
    mPause = true;
    mPauseTime = SDL_GetTicks();
}
void CTimer::resume()
{
    mPause = false;
    mStartTime = SDL_GetTicks() - mPauseTime + mStartTime;
}
void CTimer::stop()
{
    mStop = true;
}
void CTimer::update()
{
    mUpdateTime = SDL_GetTicks();
}
void CTimer::lock()
{
    SDL_Delay(mLockTime - (SDL_GetTicks() - mUpdateTime));
}

void CTimer::setFrameRate(Uint32 frameRate)
{
    mLockTime = 1000.0/frameRate;
}