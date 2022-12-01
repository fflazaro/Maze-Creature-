//
// Created by Franchesca Lazaro on 4/28/2022.
// Assignment 3
//
#include <iostream>
using namespace std;

#ifndef ASSIGNMENT3_MAZE_H
#define ASSIGNMENT3_MAZE_H

#endif //ASSIGNMENT3_MAZE_H


class maze {
public:
    //Variables
    int rowExit;
    int columnExit;
    int widthMaze;
    int heightMaze;

    //Bounds for the array
    static const int rowNum = 100, colNum = 100;

    //2d Array
    char mazeArray[rowNum][colNum]{};

    //Constructors

    //Default constructor
    maze();

    //Constructor that takes in a file
    explicit maze(const string& filename);

    //Overloaded Operator
    //Overloaded << to print out the maze
    friend ostream &operator<<(ostream &os, maze &maze);

    //Returns boolean
    bool isClear(int row, int column) const;
    bool isWall(int row, int column) const;
    bool isPath(int row, int column) const;
    bool isVisited(int row, int column) const;
    static bool isValidSpot(int row, int column);

    //Returns void
    void markAsPath(int row, int column);
    void markAsVisited(int row, int column);
    void printMaze();

private:
    //Methods
    int readFile(const string& filename);
};


