#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 20, nCrystalsFound = 0;
string gameState  = "Running";

string currentState = "Enchanted Forest";
// This is a demo implementation of makeMove function
// It doesn't follow the game rules at all
// You have to implement it according to game logic 

void makeMove(string direction){


	if (direction == "East"){ //When Right Arrow is pressed

		cout<<"Provide East move implementation"<<endl;
		moveEast();

		if(currentState == "Enchanted Forest"){ 
		currentState = "Sands of Quick"; // there is no coming back from sands of quick
		applesLeft--;
		gameState = "Lost";
		}
		
		// cout<<"Provide East move implementation"<<endl;
		// moveEast(); // Call this function only if warrior needs to be moved
		nCrystalsFound++;
		// gameState = "Lost";
	} 

	else if (direction == "West"){ //When Left Arrow is pressed
		cout<<"Provide West move implementation"<<endl;
		moveWest();  	// Call this function only if warrior needs to be moved
		gameState = "Lost"; //Set this gameState when the game is lost
		applesLeft--;
	}
	else if (direction == "North"){ //When Up Arrow is pressed
		cout<<"Provide North move implementation"<<endl;
		moveNorth();  	// Call this function only if warrior needs to be moved

		if(currentState == "Apples Orchard"){
			applesLeft--;
		}

		else if ((currentState == "Eisten Tunnel") && (nCrystalsFound == 4)){
			gameState = "Won";
		}

		// gameState = "Running";	// Set this gameState when the game is Won
	}
	else if (direction == "South"){//When Down Arrow is pressed
		cout<<"Provide South move implementation"<<endl;
		moveSouth();  // Call this function only if warrior needs to be moved
		gameState = "Running";
	}
}
