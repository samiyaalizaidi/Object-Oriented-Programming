#include "ObjectCreator.hpp"
Unit* ObjectCreator::getObject(int x, int y){
    int select = rand() % 3;
    switch (select)
    {
    // returning memory to draw at (x,y)
    case 0:
        return new Pigeon({7,88,155,103},{x, y, 50, 50});
    case 1:
        return new Butterfly({257, 24, 173, 134},{x, y, 50, 50});
    case 2:
        return new Bee({540, 370, 193, 115},{x, y, 50, 50});
    default:
        break;
    }
}