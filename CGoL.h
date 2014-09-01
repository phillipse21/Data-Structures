#ifndef CGol_H
#define CGoL_H

#include "libraries.h"

using namespace std;

class Cell
{
public:
    Cell();
    void setState(int state);
    void setXCoor(int x);
    void setYCoor(int y);
    void setLiveNeighbors(int x);
    void setPrevAlive(bool alive);
    void setRightPtr(Cell *newRightPtr);
    void setLeftPtr(Cell *newLeftPtr);
    void setUpPtr(Cell *newUpPtr);
    void setDownPtr(Cell *newDownPtr);
    void setNextPtr(Cell *nextPtr);
    void setPrevPtr(Cell *prevPtr);
    int getState();
    int getXCoor();
    int getYCoor();
    int getLiveNeighbors();
    bool getPrevAlive();
    Cell* getRightPtr();
    Cell* getLeftPtr();
    Cell* getUpPtr();
    Cell* getDownPtr();
    Cell* getNextPtr();
    Cell* getPrevPtr();
    ~Cell();
private:
    int state;//1=alive;0=dead
    int xCoor;
    int yCoor;
    int liveNeighbors;
    bool prevAlive;
    Cell *rightPtr;
    Cell *leftPtr;
    Cell *upPtr;
    Cell *downPtr;
    Cell *nextPtr;
    Cell *prevPtr;
};

//test
void tests(Cell *firstCell);

//creates board of 50 x 90 cells-dimensions of mainWindow
void createBoard(Cell *&firstCell, WINDOW * mainWindow);

//prints board
void printBoard(Cell *firstCell, WINDOW * mainWindow);

//assigns upPtr & down by traversing through list and finding the Cell with the same x and y-1
void assignUpDownPtr(Cell *&firstCell);

//finds cells on end of rows and changes left or right pointers
void breakRows(Cell *&firstCell);

//creates new Cell
Cell* createNewCell(int xCoordinate, int yCoordinate);

//finds last cell in list
Cell* findCell(int xCoordinate, int yCoordinate,Cell *firstCell);

#endif
