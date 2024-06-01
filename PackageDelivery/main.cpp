// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include "node.hpp"
// #include <fstream>
// #include <vector>
#include "bst.cpp"
using namespace std;

/* 
References:
- the file reading and writing codes are from Codio's C++ fundamentals course.
- bst algorithms are from DSA.
*/

BSTNode* root = NULL; // this is the root of BST

// You have to define the functions below
BSTNode* loadTrucks(BST* bst);
void makeJourney(BST* bst, BSTNode* root);
void unloadTrucks(BST* bst, BSTNode* root);

int main()
{
	BST* bst = new BST(); // all the truck objects are in this bst
    root = loadTrucks(bst);	
    makeJourney(bst, root);
    bst->printInorder(root); // just for testing
	unloadTrucks(bst, root); 
	delete bst; // deletes the memory allocated by the new operator
    return 0;
}

// returns the root node of the bst
BSTNode* loadTrucks(BST* bst){
	BSTNode* root = nullptr;
    string path = "Input.txt";
	int counter = 0; // for the switch case, truck obj is populated with the help of this	
	Truck x; // temp variable to populate the bst
	try {
		ifstream file;
		string read;
		file.open(path);
		if (!file) {
			throw runtime_error("File failed to open.");
		}
		while(!file.eof()){
			getline(file, read, '\n'); //specify newline as delimiter
			switch (counter)
			{
				case 0:
					x.driver = read;
					counter++;
					break;
				
				case 1:
					x.petrol = stod(read);
					counter++;
					break;

				case 2:
					x.regNo = read;
					counter++;
					break;

				case 3:
					x.fullMileage = stoi(read);
					counter++;
					break;

				case 4:				
					x.emptyMileage = stoi(read);
					root = bst->insert(root, x);
					counter = 0; // set to zero because all the info has been read
					break;

				default:
					break;
			}
		}
		
		file.close();
		}
		catch (exception& e) {
			cerr << e.what() << endl;
		}
		return root; // pointer of the bst root
    
}

void makeJourney(BST* bst, BSTNode* root){
	// simply calls class' own function
	bst->journey(root);
}

void unloadTrucks(BST* bst, BSTNode* root){
	// calls the class function
	bst->write(root);
}