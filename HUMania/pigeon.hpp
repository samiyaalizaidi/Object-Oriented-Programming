#include "Unit.hpp"
#pragma once
class Pigeon : public Unit {
    public:    
        void fly(); // virtual function
        Pigeon(SDL_Rect sr,SDL_Rect mr); // ctor
};

