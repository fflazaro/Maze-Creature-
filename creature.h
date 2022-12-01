//
// Created by Franchesca Lazaro on 4/28/2022.
// Assignment 3
//
#include <iostream>
#include "maze.h"


using namespace std;
#ifndef ASSIGNMENT3_CREATURE_H
#define ASSIGNMENT3_CREATURE_H

class creature : public maze{
public:
    //Constructors
    creature(const int& row, const int& col);

    //Overloaded Operators
    friend ostream &operator<<(ostream &os, creature &creature);

    //Methods
    string solve(maze &maze);
    static string reverse(string &string);
    bool traverse(maze &maze, int r, int c);


private:
    //Variables
    int row;
    int col;
    string pathWay;
    maze myMaze;

    //Friend class with maze
    friend class maze;
};
#endif //ASSIGNMENT3_CREATURE_H
