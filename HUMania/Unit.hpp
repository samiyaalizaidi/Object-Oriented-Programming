#include "game.hpp"
#include "drawing.hpp"
#pragma once
class Unit{
    public:
        SDL_Rect srcRect, moverRect; // for SDL
        void draw(); // same for everyone
        virtual void fly() = 0; // pure virtual function
        bool state = false; // to be used by both bee and butterfly
};