#include<SDL.h>
#include "ObjectCreator.hpp"
#include<vector>
#include<list>
using namespace std;

class HUMania{

    public:
        list<Unit*> unt; // It's a list that can store Unit* type objects
            
        void drawObjects(); // draws and moves all objects
        void createObject(int, int); // obtains a dynamic memory 
        
        ~HUMania(); // dtor to release all dynamically allocated memort
};