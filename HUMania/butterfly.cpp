#include "butterfly.hpp"

void Butterfly::fly() 
{    
    //the butterfly will enter this condition as no state is defined.
    if (state == false) 
    {      
        moverRect.x += 3; 
        moverRect.y += 3; //butterfly will move downwards

        //these conditions are animating the butterfly
        if (srcRect.x == 256 && srcRect.y == 24) 
            srcRect = {257,182,192,214};

        else if (srcRect.x == 257 && srcRect.y == 182)
            srcRect = {284,433,247,178};

        else
            srcRect = {256,24,174,134};
    
        // if butterfly reaches the bottom of the screen it's state will change and the condition will change to else
        if (moverRect.y >= 550)
        {
            state = true;
        }

        //if the butterfly reaches the far right of the screen then it will reapper from the other side
        else if (moverRect.x >= 1000)
        {
            moverRect.x = 0;
        }
    }
    
    else //the butterfly will enter this condition as soon as the state becomes true.
    {
        moverRect.x += 3;
        moverRect.y -= 3; //here the butterfly moves upwards.
        
        //these conditions are animating the butterfly
        if (srcRect.x == 256 && srcRect.y == 24)
        srcRect = {257,182,192,214};

        else if (srcRect.x == 257 && srcRect.y == 182)
        srcRect = {284,433,247,178};

        else
        srcRect = {256,24,174,134};
    
        // if butterfly reaches the top of the screen it's state will change and the condition will change to if.
        if (moverRect.y <= 2)
        {
            state = false;
        }

        //if the butterfly reaches the far right of the screen then it will reapper from the other side
        else if (moverRect.x >= 1000)
        {
            moverRect.x = 0;
        } 
    }   
}
Butterfly :: Butterfly (SDL_Rect sr, SDL_Rect mr) //calling the constructor and passing the srcRect and moverRect values. 
{
    srcRect = sr;
    moverRect = mr;
}