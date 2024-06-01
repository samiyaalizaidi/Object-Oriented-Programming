#include "Unit.hpp"

class Bee : public Unit{
    public:
        void fly(); // virtual function 
        Bee(SDL_Rect sr, SDL_Rect mr); // ctor
};