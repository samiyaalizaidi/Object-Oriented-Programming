#include <iostream>
#include "node.hpp"
#include <fstream>
using namespace std;

// for file reading
ofstream file1("Trip.txt");
class BST{
    
        // user must not be able to change the root directly
        BSTNode* root;

        // helper functions
        void calculate(BSTNode* root){
            double full = 60.0 / ((root->val).fullMileage);
            double empty = 60.0 / ((root->val).emptyMileage);

            // only change when the truck has enough petrol to make the journey
            if((full + empty) < ((root->val).petrol)){
                ((root->val).petrol) = ((root->val).petrol) - (full + empty);
            }
        }
        // using inorder traversal to write in the ascending order
        void writeFile(BSTNode* root){
            if(root == NULL){

                return;
            }
            writeFile(root->left);
            // writing into the file
            file1 << (root->val).driver << "\n" << (root->val).petrol << "\n" << (root->val).regNo << "\n" << (root->val).fullMileage << "\n" << (root->val).emptyMileage << endl; 
            cout << "writing" << endl;
            writeFile(root->right);
        }

        // deletes the bst memory allocated through 'new'
        // using the post order traversal logic because we need the root to delete all others
        // so delete the root in the end
        void releaseMemory(BSTNode* root){
            if(root == NULL){
                return;
            }
            releaseMemory(root->left); // completely releases all the memory at the left side
            releaseMemory(root->right); // completely releases all the memory at the right side
            delete root; // releases the root when all other vertices are deleted            
        }

    public:
        // constructor
        BST(){
            root = NULL;
        }

        // insert truck object in bst using recursion
        BSTNode* insert(BSTNode* root, Truck x){
            // keeps on traversing until an empty node is found to insert the obj
            if(root == NULL){
                root = new BSTNode();
                root->val = x;                         
            }
            else if((root->val).regNo > x.regNo){
                root->left = insert(root->left, x);
            }
            else{
                root->right = insert(root->right, x);
            }  
            return root;          
        }

        // this function is for debugging
        void printInorder(BSTNode* node){
            if (node == NULL)
                return;

            printInorder(node->left);    
            cout << (node->val).driver << "\n" << (node->val).petrol << endl;        
            printInorder(node->right);
        }
        
        // using inorder traversal to make changes
        void journey(BSTNode* node){
            if(node == NULL){
                return;
            }
            journey(node->left); // traverses the left side first
            calculate(node);
            journey(node->right); // then traverses the right side

        }

        void write(BSTNode* root){
            // passes the root to the writing function
            writeFile(root);
            // closes the file
            file1.close();
            cout << "file writing done." << endl;

        } 

        // destructor
        ~BST(){
            // release all the memory
            releaseMemory(root);
            // success message
            cout << "memory released!" << endl;
        }
};