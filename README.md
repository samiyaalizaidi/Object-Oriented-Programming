# Object Oriented Programming (Fall 2022) 

Welcome to the repository containing all my homework assignments for the Object Oriented Programming course that I took at the university in Fall 2022. Below is a brief overview of each assignment and its objectives.

## Table of Contents

- [Homework Assignments](#homework-assignments)
  - [Seeplusia](#seeplusia)
  - [GhostBusters](#ghostbusters)
  - [Package Delivery](#package-delivery)
  - [HUMania](#humania)
- [Installation and Usage](#installation-and-usage)

## Homework Assignments

### Seeplusia

**Description:** Prince Lazy has been captured by an evil wizard. You are Zeldana, a female warrior who takes it upon yourself to rescue the prince and return him to his family. You go off on a quest through the dangerous world of SeePlusia to search for the four mythical crystals of Objects. Together the crystals will give you the power to defeat the wizard and rescue Prince Lazy. The world of SeePlusia is shown in Fig. assests. It shows the different locations in the world. An arrow gives the direction of travel between locations and the number of apples required to travel from one location to other is also shown.

### GhostBusters

**Description:** The Ghost Busters is a tiny simple game to find the position of a ghost, hidden somewhere in the grid. Initially, all the blocks in the grid are locked, and then the player clicks any of the blocks to get some information about the ghost's location. Here are the rules for various objects being displayed upon click:
- A snake is drawn if the clicked block is 0-1 blocks away from the ghost
- A turtle is drawn if the clicked block is 2-3 blocks away from the ghost
- A bunny is drawn if the clicked block is 4 blocks away from the ghost
- A snake, turtle, or bunny is drawn randomly if the clicked block is more than 4 blocks away.

After exploring certain blocks of the game, the player finally busts the ghost with a right-click. If the ghost location was correct, then a ghost is drawn on that block else the game fails. The solution of this game is provided along with this homework, please play this game many times to correctly understand the working.

### Package Delivery

**Description:** For this assignment you will be implementing a binary search tree (BST) composed of Truck variable. Truck structure is defined as:
```C++
struct Truck
{
  string driver;
  double petrol;
  string regNo;
  int fullMileage;
  int emptyMileage;
};

```
You will be using the sample file, Input.txt for this assignment. Your code should however take into account that if an entry is increased or reduced (5 lines per entry) it reads all the entries in the file (You are going to assume that there are no errors in the file). 

The function ``loadTrucks()`` reads the file ``Input.txt``, and populates a BST of trucks according to the information given in the file. You can compare a truck variable is less than another truck variable based on its registration number, hence based on this comparison, you can populate the binary search tree. As you read information of a truck, a new BSTNode is created and inserted in the proper location in the BST. 

The function ``makeJourney()`` traverses all the trucks and updates their remaining fuels after a truck takes cargo and travels 60 km, drops the cargo, and returns empty based on the fuel consumption. For example, the truck information given above can make this journey, as it has 34 liters of petrol in its tank and it requires 60/9 + 60/7 = 15.23 liter of petrol. Hence the remaining fuel in this truck would be 18.77 litre. Those trucks who are unable to make the journey will not travel, and hence their fuel information will not be updated.
 
Finally, the function ``unloadTrucks()`` shows all the trucks' information in ascending order of registration number. A new file ``Trip.txt`` should be generated that will show the current state of all the Trucks. 

### HUMania

**Description:** These assignments continue the same project, HUMania. They build upon each other, with HW3 (part 2) and HW4 leading up to the final version in HW5. The HUMania project involved creating an interactive application, showcasing advanced object-oriented programming techniques such as event-driven programming, GUI design, and more complex data structures.

## Installation and Usage

1. Clone the repository to your local machine:
   ```bash
   https://github.com/samiyaalizaidi/Object-Oriented-Programming.git
   ```
2. Navigate to the directory of the homework you want to run.
3. Open the VSCode terminal and put this command to compile everything:
    ```bash
    g++ *.cpp -IC:/mingw_dev_lib/include/SDL2 -LC:/mingw_dev_lib/lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
    ```
4. Run the game by this command:
    ```bash
    ./a.exe
    ```
---

If you have any questions or suggestions, feel free to reach out.
