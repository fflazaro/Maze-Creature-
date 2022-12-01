//
// Created by Franchesca Lazaro on 4/28/2022.
// Assignment 3
//
#include <iostream>
#include "creature.h"
using namespace std;

//Declarations of test methods
void checkValidFile();
void checkMaze();
void printInvalidMaze();
void printValidMaze();
void checkCreatureLocation();
void solveMaze();
void solveDeadEnd();
void solveExit();
void solveNoTunnels();
void solveNoExit();
void outOfBounds(int i, int i1);

int main() {
    checkMaze();
    return 0;
}

//Testing for the maze
void checkMaze() {
    cout << "TEST AN INVALID FILE." << endl;
    checkValidFile();
    cout << "_________________________________________" << endl;

    cout << "PRINT AN INVALID MAZE." << endl;
    printInvalidMaze();

    cout << "PRINT A VALID MAZE." << endl;
    printValidMaze();

    cout << "CHECKS WHAT HAPPENS IF CREATURE IS IN AN INVALID SPOT." << endl;
    cout << "ALSO PRINT CREATURE LOCATION." << endl;
    checkCreatureLocation();
    cout << "_________________________________________" << endl;

    cout << "CHECK IF THE CREATURE CAN SOLVE A MAZE." << endl;
    solveMaze();

    cout << "CHECK IF THE CREATURE CAN SOLVE A MAZE IF IT'S IN AN AREA THAT CAN'T GET TO THE EXIT." << endl;
    solveDeadEnd();

    cout << "CHECK TO SEE WHAT HAPPENS IF CREATURE IS ALREADY AT THE EXIT." << endl;
    solveExit();

    cout << "CHECK TO SEE IF THE CREATURE CAN SOLVE A MAZE WITH NO TUNNELS." << endl;
    solveNoTunnels();

    cout << "CHECK TO SEE WHAT WILL HAPPEN IF CREATURE IS IN A MAZE WITH NO EXITS." << endl;
    solveNoExit();

    cout << "CHECK TO SEE WHAT WILL HAPPENS IF CREATURE STARTING LOCATION IS OUT OF BOUNDS." << endl;
    cout << "--> IF Y COORD IS OUT OF BOUNDS." << endl;
    outOfBounds(1,21);
    cout << "--> IF X COORD IS OUT OF BOUNDS." << endl;
    outOfBounds(-1, 20);

}

//Implementation of test functions

void outOfBounds(int i, int i1) {
    maze m ("maze.txt");
    creature c (i, i1);
    c.solve(m);
}

void solveNoExit() {
    maze m ("mazeNoExit1.txt");
    creature c (5,7);
    c.solve(m);
    cout << m;
}

void solveNoTunnels() {
    maze m ("mazeSimple.txt");
    creature c(5,7);
    c.solve(m);
    cout << m;
}

void solveExit() {
    maze m("maze0.txt");
    creature c(0, 8);
    c.solve(m);
    cout << m;
}

void solveDeadEnd() {
    maze m("maze0.txt");
    creature c(1,3);
    c.solve(m);
    cout << m;
}

void solveMaze() {
    maze m("maze.txt");
    creature c(2, 15);
    c.solve(m);
    cout << m;
}

void checkCreatureLocation() {
    maze m("maze.txt");
    creature c(0,0);
    c.solve(m);
    cout << c;
}

void printValidMaze() {
    maze m("maze.txt");
    cout << m;
}

void printInvalidMaze() {
    maze m("unavailable.txt");
    cout << m;
}

void checkValidFile() {
    maze m("unavailable.txt");
}
