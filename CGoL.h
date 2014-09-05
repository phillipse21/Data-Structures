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
    void addToLiveNeighbors();
    void setPrevAlive(bool alive);
    void setRightPtr(Cell *newRightPtr);
    void setLeftPtr(Cell *newLeftPtr);
    void setUpPtr(Cell *newUpPtr);
    void setDownPtr(Cell *newDownPtr);
    void setNextPtr(Cell *nextPtr);
    void setPrevPtr(Cell *prevPtr);
    void setTopLeftPtr(Cell *topLeft);
    void setTopRightPtr(Cell *topRight);
    void setBottomLeftPtr(Cell *bottomLeft);
    void setBottomRightPtr(Cell *bottomRight);
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
    Cell* getTopLeftPtr();
    Cell* getTopRightPtr();
    Cell* getBottomLeftPtr();
    Cell* getBottomRightPtr();
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
    Cell *topLeftPtr;
    Cell *topRightPtr;
    Cell *bottomLeftPtr;
    Cell *bottomRightptr;
    Cell *nextPtr;
    Cell *prevPtr;
};

//test
void tests(Cell *firstCell);

//creates board of 50 x 90 cells-dimensions of mainWindow
void createBoard(Cell *&firstCell,Cell *&tempCell);

//prints board
void printBoard(Cell *firstCell);

//assigns upPtr & downPtr by traversing through list and finding the Cell with the same x and y-1/y+1
void assignUpDownPtr(Cell *&firstCell);

//assigns topLet, topRight, bottomLeft, and bottomRight
void assignDiagnals(Cell *&firstCell);

//assigns left or right pointers to NULL if cell is in left-most or right-most columns
void assignBorderPointers(Cell *&firstCell);

//assigns left,right,up, and down pointers to NULL if neighboring cell's state is 0
//adds to cell's liveNeighbor count if pointer is pointing to cell with state of 1
void findLiveNeighbors(Cell *&firstCell);

//creates new Cell
Cell* createNewCell(int xCoordinate, int yCoordinate);

//finds last cell in list
Cell* findCell(int xCoordinate, int yCoordinate,Cell *firstCell);

//determines the state of the cell for the next generation
void applyRules(Cell *&firstCellPtr,Cell *&secondCellPtr);

//copy new generation onto firstCell
void copyChanges(Cell *&firstCellPtr,Cell *&secondCellPtr);

#endif
