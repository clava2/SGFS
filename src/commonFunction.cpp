#include "commonFunction.h"

bool isPointInRect(SDL_Point point, SDL_Rect rect)
{
    if((point.x <= (rect.x + rect.w))&&(point.x >= rect.x) && (point.y <= (rect.y + rect.h)) && (point.y >= rect.y))
        return true;
    return false;
}