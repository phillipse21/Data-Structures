#include "libraries.h"

using namespace std;

//constructor for Cell
Cell::Cell()
{
    state = 0;
    xCoor = 0;
    yCoor = 0;
    liveNeighbors = 0;
    prevAlive = false;
    rightPtr = NULL;
    leftPtr = NULL;
    upPtr = NULL;
    downPtr = NULL;
}

//sets whether cell is alive or dead
void Cell::setState(int state)
{
    this -> state = state;
}

//sets xCoor
void Cell::setXCoor(int x)
{
    this -> xCoor = x;
}

//sets yCoor
void Cell::setYCoor(int y)
{
    this -> yCoor = y;
}

//sets number of live neighbors
void Cell::setLiveNeighbors(int x)
{
    this -> liveNeighbors = x;
}

void Cell::addToLiveNeighbors()
{
    liveNeighbors++;
}

//sets if cell was previously alive
void Cell::setPrevAlive(bool alive)
{
    this -> prevAlive = alive;
}

//sets rightPtr
void Cell::setRightPtr(Cell *newRightPtr)
{
    this -> rightPtr = newRightPtr;
}

//sets leftPtr
void Cell::setLeftPtr(Cell *newLeftPtr)
{
    this -> leftPtr = newLeftPtr;
}

//returns upPtr
void Cell::setUpPtr(Cell *newUpPtr)
{
    this -> upPtr = newUpPtr;
}

//returns downPtr
void Cell::setDownPtr(Cell *newDownPtr)
{
    this -> downPtr = newDownPtr;
}

//sets nextPtr
void Cell::setNextPtr(Cell *nextPtr)
{
    this -> nextPtr = nextPtr;
}

//sets prevPtr
void Cell::setPrevPtr(Cell *prevPtr)
{
    this -> prevPtr = prevPtr;
}

//sets topLeft
void Cell::setTopLeftPtr(Cell *topLeft)
{
    this -> topLeftPtr = topLeft;
}

//sets topRight
void Cell::setTopRightPtr(Cell *topRight)
{
    this -> topRightPtr = topRight;
}

//sets bottomLeft
void Cell::setBottomLeftPtr(Cell *bottomLeft)
{
    this -> bottomLeftPtr = bottomLeft;
}

//sets bottomRight
void Cell::setBottomRightPtr(Cell *bottomRight)
{
    this -> bottomRightptr = bottomRight;
}

//returns 1 if the cell is alive, 0 if cell is dead
int Cell::getState()
{
    return state;
}

//returns xCoor
int Cell::getXCoor()
{
    return xCoor;
}

//returns yCoor
int Cell::getYCoor()
{
    return yCoor;
}

//returns the number of live neighbors
int Cell::getLiveNeighbors()
{
    return liveNeighbors;
}

//returns true if previously alive(change color), false if not
bool Cell::getPrevAlive()
{
    return prevAlive;
}

//returns rightPtr
Cell* Cell::getRightPtr()
{
    return rightPtr;
}

//returns leftPtr
Cell* Cell::getLeftPtr()
{
    return leftPtr;
}

//returns upPtr
Cell* Cell::getUpPtr()
{
    return upPtr;
}

//returns downPtr
Cell* Cell::getDownPtr()
{
    return downPtr;
}

//returns nextPtr
Cell* Cell::getNextPtr()
{
    return nextPtr;
}

//returns prevPtr
Cell* Cell::getPrevPtr()
{
    return prevPtr;
}

//returns topLeft
Cell* Cell::getTopLeftPtr()
{
    return topLeftPtr;
}

//returns topRight
Cell* Cell::getTopRightPtr()
{
    return topRightPtr;
}

//returns bottomLeft
Cell* Cell::getBottomLeftPtr()
{
    return bottomLeftPtr;
}

//returns bottomRight
Cell* Cell::getBottomRightPtr()
{
    return bottomRightptr;
}


//Cell deconstructor
Cell::~Cell()
{
}


//test
void tests(Cell *firstCell)
{
    ofstream oFile("test.txt");

    Cell *traversePtr = firstCell;

    while(traversePtr->getNextPtr() != NULL)
    //while(traversePtr->getYCoor() == 0)
    {
        oFile << traversePtr->getXCoor() << " " << traversePtr->getYCoor() << " " << endl
             << "   State " << traversePtr->getState() << endl
             << "   Live Neighbors " << traversePtr->getLiveNeighbors() << endl;

        if(traversePtr->getNextPtr() != NULL)
            oFile << "   NextPtr " << traversePtr->getNextPtr()->getXCoor() << " " << traversePtr->getNextPtr()->getYCoor() << endl;
        else
            oFile << "   NextPtr NULL" << endl;

        if(traversePtr->getPrevPtr() != NULL)
            oFile << "   PrevPtr " << traversePtr->getPrevPtr()->getXCoor() << " " << traversePtr->getPrevPtr()->getYCoor() << endl;
        else
            oFile << "   PrevPtr NULL" << endl;


        if(traversePtr->getUpPtr() != NULL)
            oFile << "   UpPtr " << traversePtr->getUpPtr()->getXCoor() << " " << traversePtr->getUpPtr()->getYCoor() << endl;
        else
            oFile << "   UpPtr NULL" << endl;

        if(traversePtr->getDownPtr() != NULL)
            oFile << "   DownPtr " << traversePtr->getDownPtr()->getXCoor() << " " << traversePtr->getDownPtr()->getYCoor() << endl;
        else
            oFile << "   DownPtr NULL" << endl;


        if(traversePtr->getLeftPtr() != NULL)
            oFile << "   LeftPtr " << traversePtr->getLeftPtr()->getXCoor() << " " << traversePtr->getLeftPtr()->getYCoor() << endl;
        else
            oFile << "   LeftPtr NULL" << endl;

        if(traversePtr->getRightPtr() != NULL)
            oFile << "   RightPtr " << traversePtr->getRightPtr()->getXCoor() << " " << traversePtr->getRightPtr()->getYCoor() << endl;
        else
            oFile << "   RightPtr NULL" << endl;

        if(traversePtr->getTopLeftPtr() != NULL)
            oFile << "   TopLeftPtr " << traversePtr->getTopLeftPtr()->getXCoor() << " " << traversePtr->getTopLeftPtr()->getYCoor() << endl;
        else
            oFile << "   TopLeftPtr NULL" << endl;

        if(traversePtr->getTopRightPtr() != NULL)
            oFile << "   TopRightPtr " << traversePtr->getTopRightPtr()->getXCoor() << " " << traversePtr->getTopRightPtr()->getYCoor() << endl;
        else
            oFile << "   TopRightNULL" << endl;

        if(traversePtr->getBottomLeftPtr() != NULL)
            oFile << "   BottomLeftPtr " << traversePtr->getBottomLeftPtr()->getXCoor() << " " << traversePtr->getBottomLeftPtr()->getYCoor() << endl;
        else
            oFile << "   BottomLeftPtr NULL" << endl;

        if(traversePtr->getBottomRightPtr() != NULL)
            oFile << "   BottomRightPtr " << traversePtr->getBottomRightPtr()->getXCoor() << " " << traversePtr->getBottomRightPtr()->getYCoor() << endl;
        else
            oFile << "   BottomRightPtr NULL" << endl;

        traversePtr = traversePtr->getNextPtr();
    }
    if(traversePtr->getNextPtr() == NULL)
    {
        oFile << traversePtr->getXCoor() << " " << traversePtr->getYCoor() << " " << endl
             << "   State " << traversePtr->getState() << endl
             << "   Live Neighbors " << traversePtr->getLiveNeighbors() << endl;

        if(traversePtr->getNextPtr() != NULL)
            oFile << "   NextPtr " << traversePtr->getNextPtr()->getXCoor() << " " << traversePtr->getNextPtr()->getYCoor() << endl;
        else
            oFile << "   NextPtr NULL" << endl;

        if(traversePtr->getPrevPtr() != NULL)
            oFile << "   PrevPtr " << traversePtr->getPrevPtr()->getXCoor() << " " << traversePtr->getPrevPtr()->getYCoor() << endl;
        else
            oFile << "   PrevPtr NULL" << endl;


        if(traversePtr->getUpPtr() != NULL)
            oFile << "   UpPtr " << traversePtr->getUpPtr()->getXCoor() << " " << traversePtr->getUpPtr()->getYCoor() << endl;
        else
            oFile << "   UpPtr NULL" << endl;

        if(traversePtr->getDownPtr() != NULL)
            oFile << "   DownPtr " << traversePtr->getDownPtr()->getXCoor() << " " << traversePtr->getDownPtr()->getYCoor() << endl;
        else
            oFile << "   DownPtr NULL" << endl;


        if(traversePtr->getLeftPtr() != NULL)
            oFile << "   LeftPtr " << traversePtr->getLeftPtr()->getXCoor() << " " << traversePtr->getLeftPtr()->getYCoor() << endl;
        else
            oFile << "   LeftPtr NULL" << endl;

        if(traversePtr->getRightPtr() != NULL)
            oFile << "   RightPtr " << traversePtr->getRightPtr()->getXCoor() << " " << traversePtr->getRightPtr()->getYCoor() << endl;
        else
            oFile << "   RightPtr NULL" << endl;

        if(traversePtr->getTopLeftPtr() != NULL)
            oFile << "   TopLeftPtr " << traversePtr->getTopLeftPtr()->getXCoor() << " " << traversePtr->getTopLeftPtr()->getYCoor() << endl;
        else
            oFile << "   TopLeftPtr NULL" << endl;

        if(traversePtr->getTopRightPtr() != NULL)
            oFile << "   TopRightPtr " << traversePtr->getTopRightPtr()->getXCoor() << " " << traversePtr->getTopRightPtr()->getYCoor() << endl;
        else
            oFile << "   TopRightNULL" << endl;

        if(traversePtr->getBottomLeftPtr() != NULL)
            oFile << "   BottomLeftPtr " << traversePtr->getBottomLeftPtr()->getXCoor() << " " << traversePtr->getBottomLeftPtr()->getYCoor() << endl;
        else
            oFile << "   BottomLeftPtr NULL" << endl;

        if(traversePtr->getBottomRightPtr() != NULL)
            oFile << "   BottomRightPtr " << traversePtr->getBottomRightPtr()->getXCoor() << " " << traversePtr->getBottomRightPtr()->getYCoor() << endl;
        else
            oFile << "   BottomRightPtr NULL" << endl;

        traversePtr = traversePtr->getNextPtr();
    }


    return;
}

//creates board of 50 x 90 cells-dimensions of mainWindow
void createBoard(Cell *&firstCell, Cell*&tempCell)
{
    int height = 30;
    int width = 30;

    Cell* newCell = new Cell;
    Cell* lastCell = new Cell;
    Cell* secondCell = new Cell;
    Cell* secondLastCell = new Cell;

    //create all Cells and only assigns x,y,rightPtr,leftPtr
    for(int y = 0; y < height-1; y++)
    {
        for(int x = 0; x < width-1; x++)
        {
            if(x == 0 && y == 0)
            {
                newCell = createNewCell(x+1,y);
                secondCell = newCell;

                firstCell->setNextPtr(newCell);
                firstCell->setRightPtr(newCell);

                newCell->setPrevPtr(firstCell);
                newCell->setLeftPtr(firstCell);

                tempCell->setNextPtr(secondCell);
                tempCell->setRightPtr(secondCell);

                secondCell->setPrevPtr(tempCell);
                secondCell->setRightPtr(NULL);

                x = x+1;
            }
            else
            {
                newCell = createNewCell(x,y);
                secondCell = newCell;
                lastCell = findCell(x,y,firstCell);
                secondLastCell = findCell(x,y,firstCell);

                lastCell->setNextPtr(newCell);
                newCell->setNextPtr(NULL);
                newCell->setPrevPtr(lastCell);

                lastCell->setRightPtr(newCell);
                newCell->setRightPtr(NULL);
                newCell->setLeftPtr(lastCell);
            }
        }
    }
}

//assigns upPtr & down by traversing through list and finding the Cell with the same x and y-1
void assignUpDownPtr(Cell *&firstCell)
{
    int height = 30;
    Cell *traversePtr = firstCell;
    Cell *secondTraversePtr = firstCell;

    while(traversePtr->getNextPtr() != NULL)
    {
        if(traversePtr->getYCoor() == 0)//first row
        {
            //find cell for downPtr by traversing through list with secondTraversePtr until
            //secondTraversePtr's x = traversePtr's x and secondTraversPtr's y = traversePtr's y + 1
            while(secondTraversePtr->getXCoor() != traversePtr->getXCoor() ||
                  secondTraversePtr->getYCoor() != traversePtr->getYCoor()+1)
            {
                secondTraversePtr = secondTraversePtr->getNextPtr();
            }
            if(secondTraversePtr->getXCoor() == traversePtr->getXCoor() &&
               secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
            {
               //set downPtr & reset secondTraversePtr
               traversePtr->setDownPtr(secondTraversePtr);
            }
        }
         else if(traversePtr->getYCoor() == height-1)//bottom row
        {
            while(secondTraversePtr->getXCoor() != traversePtr->getXCoor() ||
                  secondTraversePtr->getYCoor() != traversePtr->getYCoor()-1)
            {
                secondTraversePtr = secondTraversePtr->getNextPtr();
            }
            if(secondTraversePtr->getXCoor() == traversePtr->getXCoor() &&
               secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
            {
                traversePtr->setUpPtr(secondTraversePtr);
            }
        }//end of else if statement
       else
        {
            while(secondTraversePtr->getNextPtr() != NULL)
            {
                if(secondTraversePtr->getXCoor() == traversePtr->getXCoor() &&
                   secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
                {
                    traversePtr->setUpPtr(secondTraversePtr);
                }

                if(secondTraversePtr->getXCoor() == traversePtr->getXCoor() &&
                   secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                {
                    //set downPtr & reset secondTraversePtr
                    traversePtr->setDownPtr(secondTraversePtr);
                }

                secondTraversePtr = secondTraversePtr->getNextPtr();
            }
        }
        traversePtr = traversePtr->getNextPtr();
        secondTraversePtr = firstCell;
    }//end of 1st while statement

    assignBorderPointers(firstCell);
    assignBorderPointers(secondTraversePtr);

}

//assigns topLet, topRight, bottomLeft, and bottomRight
void assignDiagnals(Cell *&firstCell)
{
    int width = 30;
    int height = 30;
    Cell *traversePtr = firstCell;
    Cell *secondTraversePtr = firstCell;

    while(traversePtr->getNextPtr() != NULL)
    {
        if(traversePtr->getYCoor() == 0)//top row
        {
            traversePtr->setTopLeftPtr(NULL);
            traversePtr->setTopRightPtr(NULL);
            if(traversePtr->getXCoor() == 0)//top left cell
            {
                traversePtr->setBottomLeftPtr(NULL);
                while(secondTraversePtr->getNextPtr() != NULL)
                {
                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()+1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                    {
                        traversePtr->setBottomRightPtr(secondTraversePtr);
                    }
                    secondTraversePtr = secondTraversePtr->getNextPtr();
                }
            }//end of top left cell
            else if(traversePtr->getXCoor() == width-1)//top right cell
            {
                traversePtr->setBottomRightPtr(NULL);

                while(secondTraversePtr->getNextPtr() != NULL)
                {
                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()-1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                    {
                        traversePtr->setBottomLeftPtr(secondTraversePtr);
                    }
                    secondTraversePtr = secondTraversePtr->getNextPtr();
                }
            }
            else
            {
                while(secondTraversePtr->getNextPtr() != NULL)
                {
                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()-1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                    {
                        traversePtr->setBottomLeftPtr(secondTraversePtr);
                    }

                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()+1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                    {
                        traversePtr->setBottomRightPtr(secondTraversePtr);
                    }

                    secondTraversePtr = secondTraversePtr->getNextPtr();
                }
            }//end of else-topRow
        }//end of main if
        else if(traversePtr->getYCoor() == height)//bottom row
        {
            traversePtr->setBottomLeftPtr(NULL);
            traversePtr->setBottomRightPtr(NULL);
            if(traversePtr->getXCoor() == 0)//bottom left cell
            {
                traversePtr->setTopLeftPtr(NULL);
                while(secondTraversePtr->getNextPtr() != NULL)
                {
                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()+1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
                    {
                        traversePtr->setTopRightPtr(secondTraversePtr);
                    }
                    secondTraversePtr = secondTraversePtr->getNextPtr();
                }
            }
            else
            {
                while(secondTraversePtr->getNextPtr() != NULL)
                {
                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()-1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
                    {
                        traversePtr->setTopLeftPtr(secondTraversePtr);
                    }

                    if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()+1 &&
                       secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
                    {
                        //set downPtr & reset secondTraversePtr
                        traversePtr->setTopRightPtr(secondTraversePtr);
                    }
                    secondTraversePtr = secondTraversePtr->getNextPtr();
                }
            }
        }
        else
        {
            while(secondTraversePtr->getNextPtr() != NULL)
            {
                if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()-1 &&
                    secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
                {
                    traversePtr->setTopLeftPtr(secondTraversePtr);
                }

                if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()+1 &&
                    secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
                {
                    traversePtr->setTopRightPtr(secondTraversePtr);
                }

                if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()-1 &&
                   secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                {
                    traversePtr->setBottomLeftPtr(secondTraversePtr);
                }

                if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()+1 &&
                   secondTraversePtr->getYCoor() == traversePtr->getYCoor()+1)
                {
                    traversePtr->setBottomRightPtr(secondTraversePtr);
                }

                secondTraversePtr = secondTraversePtr->getNextPtr();
            }
        }

        traversePtr = traversePtr->getNextPtr();
        secondTraversePtr = firstCell;
    }//end of while loop
    if(traversePtr->getNextPtr() == NULL)//last cell
    {
        secondTraversePtr = firstCell;
        traversePtr->setTopRightPtr(NULL);
        traversePtr->setBottomLeftPtr(NULL);
        traversePtr->setBottomRightPtr(NULL);

        while(secondTraversePtr->getNextPtr() != NULL)
        {
            if(secondTraversePtr->getXCoor() == traversePtr->getXCoor()-1 &&
               secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
            {
                traversePtr->setTopLeftPtr(secondTraversePtr);
            }
            secondTraversePtr = secondTraversePtr->getNextPtr();
        }
    }
}


//assigns left or right pointers to NULL if cell is in left-most or right-most columns
void assignBorderPointers(Cell *&firstCell)
{
    int width = 30;
    Cell* traversePtr = firstCell;

    //assign border cells' left/right pointers to NULL
    while(traversePtr->getNextPtr() != NULL)
    {
        if(traversePtr->getXCoor() == 0)
            traversePtr->setLeftPtr(NULL);
        else if(traversePtr->getXCoor() == width-1)
            traversePtr->setRightPtr(NULL);

        traversePtr = traversePtr->getNextPtr();
    }
    if(traversePtr->getNextPtr() == NULL)
        traversePtr->setRightPtr(NULL);

}


//assigns left,right,up, and down pointers to NULL if neighboring cell's state is 0
//adds to cell's liveNeighbor count if pointer is pointing to cell with state of 1
void findLiveNeighbors(Cell *&firstCell)
{
    Cell* traversePtr = firstCell;
    int width = 30;
    int height = 30;

    while(traversePtr->getNextPtr() != NULL)
    {
        traversePtr->setLiveNeighbors(0);

        if(traversePtr->getUpPtr() != NULL)
        {
            if(traversePtr->getUpPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getDownPtr() != NULL)
        {
            if(traversePtr->getDownPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getLeftPtr() != NULL)
        {
            if(traversePtr->getLeftPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getRightPtr() != NULL)
        {
            if(traversePtr->getRightPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getTopLeftPtr() != NULL)
        {
            if(traversePtr->getTopLeftPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getTopRightPtr() != NULL)
        {
            if(traversePtr->getTopRightPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getBottomLeftPtr() != NULL)
        {
            if(traversePtr->getBottomLeftPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        if(traversePtr->getBottomRightPtr() != NULL)
        {
            if(traversePtr->getBottomRightPtr()->getState() == 1)
                traversePtr->addToLiveNeighbors();
        }

        traversePtr = traversePtr->getNextPtr();
    }
}


//creates new Cell
Cell* createNewCell(int xCoordinate, int yCoordinate)
{
    Cell* newCellPtr = new Cell;
    newCellPtr->setXCoor(xCoordinate);
    newCellPtr->setYCoor(yCoordinate);
    newCellPtr->setState(rand()% 2);
    newCellPtr->setTopLeftPtr(NULL);
    newCellPtr->setTopRightPtr(NULL);
    newCellPtr->setBottomLeftPtr(NULL);
    newCellPtr->setBottomRightPtr(NULL);

    return newCellPtr;
}


//finds last cell in list
Cell* findCell(int xCoordinate, int yCoordinate,Cell *firstCell)
{
    Cell *traversePtr = firstCell;

    if(firstCell->getRightPtr() == NULL)
    {
        return firstCell;
    }
    else
    {
        while(traversePtr->getRightPtr() != NULL)
        {
            traversePtr = traversePtr->getRightPtr();
        }
        return traversePtr;
    }
}

//determines the state of the cell for the next generation
void applyRules(Cell *&firstCell,Cell *&secondCell)
{
    Cell *traversePtr = firstCell;
    Cell *secondTraversePtr = secondCell;

    while(traversePtr->getNextPtr() != NULL)
    {
        if(traversePtr->getState() == 1)
        {
            //cell with < two live neighbors dies
            if(traversePtr->getLiveNeighbors() < 2)
            {
                secondTraversePtr->setState(0);
            }
            else if(traversePtr->getLiveNeighbors() == 2 || traversePtr->getLiveNeighbors() == 3)//cell with 2 or 3 live neighbors lives
            {
                secondTraversePtr->setState(1);
            }
            else if(traversePtr->getLiveNeighbors() > 3)//cell with > 3 live neighbors dies
            {
                secondTraversePtr->setState(0);
            }
        }
        //dead cell with 3 neighbors comes to live
        else if(traversePtr->getState() == 0 && traversePtr->getLiveNeighbors() == 3)
        {
            secondTraversePtr->setState(1);
        }

        traversePtr = traversePtr->getNextPtr();
        secondTraversePtr = secondTraversePtr->getNextPtr();
    }
    if(traversePtr->getNextPtr() == NULL)
    {
        if(traversePtr->getState() == 1)
        {
            //cell with < two live neighbors dies
            if(traversePtr->getLiveNeighbors() < 2)
                secondTraversePtr->setState(0);
            //cell with 2 or 3 live neighbors lives
            else if(traversePtr->getLiveNeighbors() == 2 || traversePtr->getLiveNeighbors() == 3)
                secondTraversePtr->setState(1);
            //cell with > 3 live neighbors dies
            else if(traversePtr->getLiveNeighbors() > 3)
                secondTraversePtr->setState(0);
        }
        //dead cell with 3 neighbors comes to live
        else if(traversePtr->getState() == 0 && (traversePtr->getLiveNeighbors() == 3))
            secondTraversePtr->setState(1);
    }
}

//prints board
void printBoard(Cell *firstCell)
{
    int width = 30;
    int height =30;

    Cell *traversePtr = firstCell;

    //clears screen before every generation
    system("CLS");

    //print "*" if cell is alive
    while(traversePtr->getNextPtr() != NULL)
    {
        if(traversePtr->getState() == 1)
        {
            cout << "*";

            if(traversePtr->getXCoor() == width-2)
            {
                cout << endl;
            }
        }
        else
        {
            if(traversePtr->getXCoor() == width-2)
            {
                cout << " " << endl;
            }
            else
            {
                cout << " ";
            }
        }
        traversePtr = traversePtr->getNextPtr();
    }
    if(traversePtr->getNextPtr() == NULL)
    {
        if(traversePtr->getState() == 1)
        {
            cout << "*" << endl;
        }
        else
            cout << " " << endl;
    }
}


//copy new generation onto firstCell
void copyChanges(Cell *&firstCellPtr,Cell *&secondCellPtr)
{
    Cell *traversePtr = firstCellPtr;
    Cell *secondTraversePtr = secondCellPtr;

    while(secondTraversePtr->getNextPtr() != NULL)
    {
        traversePtr->setState(secondTraversePtr->getState());
        traversePtr->setLiveNeighbors(secondTraversePtr->getLiveNeighbors());
        traversePtr->setUpPtr(secondTraversePtr->getUpPtr());
        traversePtr->setDownPtr(secondTraversePtr->getDownPtr());
        traversePtr->setTopLeftPtr(secondTraversePtr->getTopLeftPtr());
        traversePtr->setTopRightPtr(secondTraversePtr->getTopRightPtr());
        traversePtr->setBottomLeftPtr(secondTraversePtr->getBottomLeftPtr());
        traversePtr->setBottomRightPtr(secondTraversePtr->getBottomRightPtr());
        traversePtr->setNextPtr(secondTraversePtr->getNextPtr());
        traversePtr->setPrevPtr(secondTraversePtr->getPrevPtr());

        traversePtr = traversePtr->getNextPtr();
    }
    if(secondTraversePtr->getNextPtr() == NULL)
    {
        traversePtr->setState(secondTraversePtr->getState());
        traversePtr->setLiveNeighbors(secondTraversePtr->getLiveNeighbors());
        traversePtr->setUpPtr(secondTraversePtr->getUpPtr());
        traversePtr->setDownPtr(secondTraversePtr->getDownPtr());
        traversePtr->setTopLeftPtr(secondTraversePtr->getTopLeftPtr());
        traversePtr->setTopRightPtr(secondTraversePtr->getTopRightPtr());
        traversePtr->setBottomLeftPtr(secondTraversePtr->getBottomLeftPtr());
        traversePtr->setBottomRightPtr(secondTraversePtr->getBottomRightPtr());
        traversePtr->setNextPtr(secondTraversePtr->getNextPtr());
        traversePtr->setPrevPtr(secondTraversePtr->getPrevPtr());
    }
}

