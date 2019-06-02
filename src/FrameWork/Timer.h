#ifndef _TIMER_H
#define _TIMER_H

#include <SDL2/SDL.h>

class CTimer
{
    private:
    Uint32 mStartTime;
    Uint32 mPuaseTime;

    bool mPause;
    Uint32 mPauseTime;

    bool mStop;
    
    Uint32 mUpdateTime;
    Uint32 mLockTime;

    public:

    CTimer();
    Uint32 getCurrentTime();
    void start();
    void pause();
    void resume();
    void stop();

    void setFrameRate(Uint32 frameRate);
    void update();
    void lock();
};

#endif