//
// Created by Franchesca Lazaro on 4/28/2022.
// Assignment 3
//
#include <iostream>
#include <fstream>
#include <string>
#include "maze.h"
using namespace std;

//Default constructor
maze::maze() {
    widthMaze = 0;
    heightMaze = 0;
    rowExit = 0;
    columnExit =0 ;
}

//Constructor to read in a file
maze::maze(const string& filename) {
    widthMaze = 0;
    heightMaze = 0;
    rowExit = 0;
    columnExit =0 ;
    readFile(filename);
}

//Overloaded <<
//Prints the maze
//Prints the width and height of the maze
//Prints the exit row and the exit column
ostream &operator<<(ostream &os, maze &maze) {
    class maze temp = maze;
    temp.printMaze();
    cout << "*: Part of the Path to Exit" << endl;
    cout << "+: Visited Square (Not part of the path to exit)" << endl;
    cout << "_________________________________________" << endl;
    return os;
}

//Function to read in a file
int maze::readFile(const string& filename) {
    fstream myFile;
    myFile.open(filename.c_str());

    if (myFile.is_open()){
        myFile >> widthMaze >> heightMaze;
        myFile >> rowExit >> columnExit;

        char line[100];
        myFile.getline(line, 100);
        for (int r = 0; r < heightMaze; r++){
            myFile.getline(line, 100);
            for (int c = 0; c < widthMaze; c++){
                mazeArray[r][c] = line[c];
            }
        }
        myFile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
    return 0;
}

//Function to print the array
void maze::printMaze() {
    for (int r = 0; r < heightMaze; r++){
        for (int c = 0; c < widthMaze; c++)
            cout << mazeArray[r][c];
        cout << endl;
    }
}

//Function to check if the coordinate is clear
bool maze::isClear(int row, int column) const {
    return mazeArray[row][column] != 'x';
}

//Function to check if the coordinate is a wall
bool maze::isWall(int row, int column) const {
    return !isClear(row, column);
}

//Function to check if the coordinate is part of the path
bool maze::isPath(int row, int column) const {
    if (mazeArray[row][column] == '*'){
        return true;
    }
    return false;
}

//Function to check if the coordinate has been visited
bool maze::isVisited(int row, int column) const {
    if (mazeArray[row][column] == '+'){
        return true;
    }
    return false;
}

//Function to mark coordinate as part of the path
void maze::markAsPath(int row, int column) {
    mazeArray[row][column] = '*';
}

//Function to mark the coordinate as visited
void maze::markAsVisited(int row, int column) {
    mazeArray[row][column] = '+';
}

//Check to see if the creature is out of bounds (doesn't take into consideration the height/width of the maze)
bool maze::isValidSpot(int row, int column){
    if (row > 100 || column > 100 || row < 0 || column < 0 ) {
        return false;
    }
    return true;
}







