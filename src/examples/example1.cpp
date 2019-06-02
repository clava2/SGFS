#include "../FrameWork/Game.h"

int main(int argc,char* argv[])
{
    CGame game;
    game.loadMedia();
    game.loop();
}