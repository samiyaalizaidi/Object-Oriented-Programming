#include "Unit.hpp"

class Butterfly : public Unit{
    public:
        void fly(); // virtual function 
        Butterfly(SDL_Rect sr, SDL_Rect mr); // ctor
};
