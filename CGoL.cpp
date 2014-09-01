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

//sets downPtr
void Cell::setPrevPtr(Cell *prevPtr)
{
    this -> prevPtr = prevPtr;
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
             << "   State " << traversePtr->getState() << endl;

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

/*
        if(traversePtr->getLeftPtr() != NULL)
            oFile << "   LeftPtr " << traversePtr->getLeftPtr()->getXCoor() << " " << traversePtr->getLeftPtr()->getYCoor() << endl;
        else
            oFile << "   LeftPtr NULL" << endl;

        if(traversePtr->getRightPtr() != NULL)
            oFile << "   RightPtr " << traversePtr->getRightPtr()->getXCoor() << " " << traversePtr->getRightPtr()->getYCoor() << endl;
        else
            oFile << "   RightPtr NULL" << endl;
*/
        traversePtr = traversePtr->getNextPtr();
    }


    return;
}

//creates board of 50 x 90 cells-dimensions of mainWindow
void createBoard(Cell *&firstCell, WINDOW * mainWindow)
{
    int height = 51;
    int width = 51;

    Cell* newCell = new Cell;
    Cell* lastCell = new Cell;

    //create all Cells and only assigns x,y,rightPtr,leftPtr
    for(int y = 0; y < height-1; y++)
    {
        for(int x = 0; x < width-1; x++)
        {
            //wclear(mainWindow);
            if(x == 0 && y == 0)
            {
                newCell = createNewCell(x+1,y);
                firstCell->setNextPtr(newCell);
                firstCell->setRightPtr(newCell);

                newCell->setPrevPtr(firstCell);
                newCell->setLeftPtr(firstCell);
                x = x+1;
            }
            else
            {
                newCell = createNewCell(x,y);
                lastCell = findCell(x,y,firstCell);

                lastCell->setNextPtr(newCell);
                newCell->setNextPtr(NULL);
                newCell->setPrevPtr(lastCell);

                lastCell->setRightPtr(newCell);
                newCell->setRightPtr(NULL);
                newCell->setLeftPtr(lastCell);
            }


            if(newCell->getState() == 1)
            {
                mvwaddch(mainWindow,newCell->getXCoor(),newCell->getYCoor(),ACS_DIAMOND);
            }
            wrefresh(mainWindow);
        }
    }


}

//assigns upPtr & down by traversing through list and finding the Cell with the same x and y-1
void assignUpDownPtr(Cell *&firstCell)
{
    int height = 50;
    int neededY = 0;
    Cell *traversePtr = firstCell;
    Cell *secondTraversePtr = firstCell;

    while(traversePtr->getNextPtr() != NULL)
    {
        if(traversePtr->getYCoor() == 0)//first row
        {
            traversePtr->setUpPtr(NULL);

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
            traversePtr->setDownPtr(NULL);

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
            //set upPtr
            while(secondTraversePtr->getXCoor() != traversePtr->getXCoor() ||
                  secondTraversePtr->getYCoor() != traversePtr->getYCoor()-1)
            {
                secondTraversePtr = secondTraversePtr->getNextPtr();
            }
            if(secondTraversePtr->getXCoor() == traversePtr->getXCoor() &&
               secondTraversePtr->getYCoor() == traversePtr->getYCoor()-1)
            {
                traversePtr->setUpPtr(secondTraversePtr);
                secondTraversePtr = firstCell;
            }

            //assign downPtr
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

        traversePtr = traversePtr->getNextPtr();
        secondTraversePtr = firstCell;
    }//end of 1st while statement
    if(traversePtr->getNextPtr() == NULL)
        return;


}


//creates new Cell
Cell* createNewCell(int xCoordinate, int yCoordinate)
{
    Cell* newCellPtr = new Cell;
    newCellPtr->setXCoor(xCoordinate);
    newCellPtr->setYCoor(yCoordinate);
    newCellPtr->setState(rand()% 2);

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

//prints board
void printBoard(Cell* firstCell, WINDOW * mainWindow)
{
    wclear(mainWindow);
  //  int height = 49;
    //int width = 89;

    Cell* traversePtr = firstCell;

   while(traversePtr->getRightPtr() != NULL)
   {
       mvwaddch(mainWindow,0,0,ACS_DIAMOND);
       traversePtr = traversePtr->getRightPtr();
   }


 /*   while(traversePtr->getXCoor() != width && traversePtr->getYCoor() != height)
    {
        if(traversePtr->getState() == 1)
        {
            mvwaddch(mainWindow,traversePtr->getYCoor(),traversePtr->getXCoor(),ACS_DIAMOND);
        }
        else
        {
            if(traversePtr->getXCoor() == width && placeSaver->getDownPtr() != NULL)
                traversePtr = placeSaver->getDownPtr();
        }
    }
*/
    return;
}
