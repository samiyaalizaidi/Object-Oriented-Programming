#include <iostream>
#include "HUMania.hpp"
#include <typeinfo>

void HUMania::drawObjects()
{
    Unit* h = new Bee({540, 370, 193, 115},{30, 40, 50, 50}); // for comparison
    for(Unit* animal: unt){	
        if(animal != nullptr){	
            animal->draw(); // display
            animal->fly();	// move
        }
        // delete and remove the bee if it has exited the window
        if((typeid(*animal).name() == typeid(*h).name()) && (animal->state)){
            delete animal; // release memory
            unt.remove(animal); // remove from the list
            animal = nullptr; 
            cout << "bee deleted" << endl;
        }
    } 
    delete h; // delete the dynamically created object for comparison
    h = nullptr;
}

// creates new objects 
void HUMania::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    ObjectCreator object; // to add into the list
    unt.push_back(object.getObject(x, y)); // pushes a dynamically created object into the list
}

HUMania::~HUMania(){
    for(Unit* animal: unt){
        // delete only the ones that are not nullptr
        if(animal != nullptr){
            delete animal;
        }
    }
    unt.clear(); // clear the list
    cout << "everything deleted" << endl;
}