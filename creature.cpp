//
// Created by Franchesca Lazaro on 4/28/2022.
// Assignment 3
//
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#include "creature.h"

//Overloaded operator to print maze
ostream &operator<<(ostream &os, creature &creature) {
    os << "C(" << creature.row << ", " << creature.col << ")" << endl;
    return os;
}

//Creature constructor to take in starting location
creature::creature(const int &r, const int &c) {
    row = r;
    col = c;
}


//Function to solve a maze
//Will return the pathway of the creature
string creature::solve(maze &maze){
    //If the creature is out of the maze, return X
    if (col > maze.widthMaze || row > maze.heightMaze  ) {
        pathWay = "X";
        cout << pathWay << endl;
        return pathWay;
    }
    //Traverse the maze and if there is no exit, return X
    if (traverse(maze, row, col)){
        //Function has to reverse pathway for the correct solution
        reverse(pathWay);
        cout << pathWay << endl;
        return pathWay;
    } else {
        pathWay = "X";
        cout << pathWay << endl;
        return pathWay;
    }
}

//This function is the one responsible for the creature traversing the maze and making a pathway towards the exit if there is one
bool creature::traverse(maze &maze, int r, int c){

    //Base Case
    if (r == maze.rowExit && c == maze.columnExit && maze.isClear(r,c)) {
        //Mark the coordinate as part of the path
        maze.markAsPath(r,c);
        return true;
    }

    //If the creature is out of bounds, return false
    if (!maze.isValidSpot(r,c) ){
        return false;
    }

    //If the creature is in a place that is not clear, return false
    if (!maze.isClear(r,c)){
        return false;
    }

    //If the creature has already marked the coordinate as part of path, return false
    if(maze.isPath(r,c)){
        return false;
    }

    //Only move if the creature is in bounds and is in a clear spot
    if(maze.isValidSpot(r,c) && maze.isClear(r,c)){
        //Mark current location in the maze
        maze.markAsPath(r,c);

        //Try going north
        if (traverse(maze, r-1, c)){
            pathWay = pathWay + "N";
            return true;
        }

        //Try going south
        if (traverse(maze, r+1,c)){
            pathWay = pathWay + "S";
            return true;
        }

        //Try going east
        if (traverse(maze, r, c+1)){
            pathWay = pathWay + "E";
            return true;
        }

        //Try going west
        if (traverse(maze, r, c-1)){
            pathWay = pathWay + "W";
            return true;
        }

        //If you are in a dead end, mark the place as visited
        maze.markAsVisited(r,c);
        return false;
    }
    return false;
}

//Function to reverse a string
string creature::reverse(string &string) {
    ::reverse(string.begin(), string.end());
    return string;
}






