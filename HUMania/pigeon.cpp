#include "pigeon.hpp"
// pigeon implementation will go here.

// fly() is overrided from the superclass
void Pigeon::fly() 
{  
    //these conditions are animating the pigeon.
    if (srcRect.x == 7 && srcRect.y == 88)
    {
        srcRect = {0,237,153,84};
        moverRect.x += 3;
    }

    else if (srcRect.x == 0 && srcRect.y == 237)
    {
        srcRect= {2,361,159,124};
        moverRect.x += 3;
    }
       
    else 
    {
        srcRect = {7,88,155,103};
        moverRect.x += 3;
    }

    // the animal will reapear from the other side if it reaches the end of the screen width
    if (moverRect.x >= 1000) 
    {
        moverRect.x = 8;
    }
}


Pigeon::Pigeon(SDL_Rect sr, SDL_Rect mr)
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = sr;

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = mr;
}

