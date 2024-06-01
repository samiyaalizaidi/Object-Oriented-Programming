#include "bee.hpp"
// pigeon implementation will go here.
void Bee::fly() 
{
    // this condition is to make the bee hover for a while with 5% probability.
    int a = rand() % 100;
    if (a <= 5)
        {
            int count = 0;
            while (count != 10)
            {
                count += 1;
            }
        }

        // if the above condition is not fullfilled the bee will move.
        else 
        {
            moverRect.x += 3; 
        }
    
    //here animation is happening.
    if (srcRect.x == 63 && srcRect.y == 619) 
        srcRect = {234,630,163,162};
    
    else if (srcRect.x == 234 && srcRect.y == 630)
        srcRect = {409,650,171,147};
    
    else 
        srcRect = {63,619,151,166};  

    // if the bee goes out of the screen this condition will become true and the bee object will be deleted in HUMania.cpp file.
    if (moverRect.x >= 1000) 
    {
        state = true; // flag; tells us that the bee has exited the screen and should be removed
    } 
}

Bee::Bee(SDL_Rect sr, SDL_Rect mr) //calling the constructor and passing the srcRect and moverRect values. 
{
    srcRect = sr;
    moverRect = mr;
}