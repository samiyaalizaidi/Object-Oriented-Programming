#include "Unit.hpp"
#include "bee.hpp"
#include "pigeon.hpp"
#include "butterfly.hpp"


class ObjectCreator{
    public:        
        Unit* getObject(int, int); // returns pointer for the random objects
};