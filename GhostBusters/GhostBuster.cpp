#include "GhostBuster.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>

using namespace std;

// Currently rows and columns are set to 8, however your game implementation should work for any other number
const int rows = 8, cols = 8;

// grid will store characters matrix of rows*cols size, you have to allocate memory to it in initialize function below
char* grid = NULL;

// Ghost will be placed over this location
int ghostRow, ghostCol;

// *****************************************************************************************************
// No change zone: Don't change anything until the next stars line
// *****************************************************************************************************

// Don't Change it: Screen width and height values
const int width = 1000, height = 600;

// Don't Change: This function is dealing with SDL and currently it's complete. Don't change anything here
void drawOneBlock(SDL_Renderer* renderer, SDL_Texture* texture, int row, int col, char sym){
    int xbox = width/cols;
    int ybox = height/rows;
    SDL_Rect src;
    switch(sym){
        case 'L': src = {141, 7, 104, 113}; break;
        case 'S': src = {427, 12, 129, 103}; break;
        case 'T': src = {268, 10, 130, 111}; break;
        case 'B': src = {0, 3, 114, 111}; break;
        case 'G': src = {571, 0, 123, 121}; break;
        case 'Z': src = {571, 0, 25, 25}; break;
        case 'F': src = {707, 16, 90, 86}; break;
    }
    SDL_Rect mov = { xbox*col, ybox*row, xbox - 10, ybox - 10};
    SDL_RenderCopy(renderer, texture, &src, &mov);
}

void drawBlocks(SDL_Renderer* renderer, SDL_Texture* texture){
    // Call drawOneBlock for all of the blocks of grid
    // for example to draw a snake over block (3, 5) you call it this way:
    // drawOneBlock(renderer, texture, 3, 5, 'S');
    if(grid == NULL) return;
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            drawOneBlock(renderer, texture, i, j, grid[i*cols+j]);
        }   
    }
}

// *****************************************************************************************************
// No change zone ends here
// *****************************************************************************************************



// To Do zone: 

bool ended = false;

/* 
The purpose of the function is to randomly assign 
an animal to a block if the distance is greater than 5.
*/
char randomGenerator(){
    int number = rand() % (3);
    switch (number){
        case 0:
            return 'S';

        case 1:
            return 'T';

        case 2:
            return 'B';
    }
}

void initialize(){
    // Create memory for grid here, it should be one dimensional array.
    // The memory should be rows*cols size.
    // Initialize entire grid with 'L' so that locks are displayed all over

    // generate two random numbers and store in ghostRow and ghostCol variables
    // assigning random variables using the function rand()
    ghostRow = rand() % (rows);
    ghostCol = rand() % (cols);
    cout << "ghost's location: " << ghostCol << ", " << ghostRow << endl;
    // allocate dynamic memory
    grid = new char[rows*cols];

    //initializing the grid with L
    for(int i = 0; i < (rows*cols); i++){
        grid[i] = 'L';
    }
}

void huntGhost(int x, int y){
    // this function is called every time you click on the screen
    // x, y are screen coordinates, you need to identify the block from these coordinates and using screen width and height values
    // each block size is width/cols x height/rows
    // according to game rules you need to put appropriate character in the grid for that block
    // Place 'S' to draw a snake --> 0 and 1
    // place 'T' to draw a turtle --> 2 and 3
    // place 'B' to draw a bunny --> 4 and 5

    // find out the height and width of a single block
    float width_of_one = width / cols;
    float height_of_one = height / rows;

    // find out the coordinates of the chosen block
    int xBlock = (x  / width_of_one);
    int yBlock = (y / height_of_one);

    cout << "the coordinates of the clicked box are: " << xBlock << ", " << yBlock << endl; 

    // find the distance of ghost and the selected box;
    int distance = pow((pow((xBlock - ghostCol), 2) + pow((yBlock - ghostRow), 2)), 0.5);

    cout << "the distance from the ghost is: " << distance << endl; 

    // if the game has ended, nothing will change

    if(!ended){

        if((distance >= 0) && (distance <= 1)){
            // snake
            grid[(yBlock * cols) + xBlock] = 'S';
        }
        else if((distance >= 2) && (distance <= 3)){
            // turtle        
            grid[(yBlock * cols) + xBlock] = 'T';
        }
        else if((distance >= 4) && (distance <= 5)){
            //bunny
            grid[(yBlock * cols) + xBlock] = 'B';
        }
        else{
            // select a random animal using randomGenerator()
            grid[(yBlock * cols) + xBlock] = randomGenerator();
            cout << "random" << endl;
        }
    }
}

void bustGhost(int x, int y){
    // this function is called when you right-click
    // it should work only one time, and you decide whether game is won or failed
    // once the game is won/failed, nothing in game should change anymore.
    // according to game rules you need to put appropriate character in the grid for that block
    // place 'S' to draw snake, when the game is won
    // place 'F' to draw failed symbol, when the game is failed

    // find out the height and width of a single block
    float width_of_one = width / cols;
    float height_of_one = height / rows;

    // find out the coordinates of the chosen block
    int xBlock = (x  / width_of_one);
    int yBlock = (y / height_of_one);

    cout <<"the coordinates of the right clicked box are: " << xBlock << ", " << yBlock << endl; 

    // find the distance between the ghost and the selected box:
    int distance = pow((pow((xBlock - ghostCol), 2) + pow((yBlock - ghostRow), 2)), 0.5);

    cout << "the distance from the ghost is with the right click: " << distance << endl; // --> works fine till here.
    /* 
    if the block is the same as ghost's location, the distance would be zero, hence a ghost
    will appear on right click. Otherwise the game would be lost.
    But first, make sure that the game hasnt already ended.
    */
    if(!ended){
        if(distance == 0){
            grid[(yBlock * cols) + xBlock] = 'G';
            cout << "game won!" << endl;
        }
        else{
            grid[(yBlock * cols) + xBlock] = 'F';
            cout << "you lose :(" << endl;
        }
        ended = true;
    }
}

void quitGhostBuster(){
    // delete the grid here
    if(ended){
        delete [] grid;
        grid = nullptr;
    }
}