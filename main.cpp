#include "libraries.h"

/*
I didn't want to do the predictable 2D array approach so I did this kinda weird.
I made a linked list of cells(prevPtr and nextPtr) with X and Y coordinates that translate to the X,Y position
on the screen where the diamonds are printed. The cells also have right,left,up, and down pointers that point to their neighbors
if the cells are not along the border of the window. If a cell is in the top row its upPtr is NULL, if in the bottom row the
downPtr is NULL, if in the right-most column the rightPtr is NULL, and if in the left-most column the leftPtr is NULL.
If the up,down,left, or right pointer is pointing to a dead cell(a cell with the state of 0) the pointer is set to NULL.

The advantage to having the up,down,left, and right pointers is that if a pointer is NULL there is either no neighboring cell
or the neighboring cell is dead. Therefore you can quickly count the number of live neighbors a cell has by traversing
through the cells pointers and counting the pointers that do not equal NULL. This is why there must also be a nextPtr and prevPtr;
so that the structure of the linked list is not disconnected when there is a dead cell;
*/

using namespace std;

int main()
{
    int const WINDOW_HEIGHT = 50;
    int const WINDOW_WIDTH = 50;
    //srand(time(NULL));

     //Creates Screen
    initscr();
    curs_set(0); //cursor visibility

    WINDOW * mainWindow = newwin(WINDOW_HEIGHT,WINDOW_WIDTH,0,0);

    //Color Settings
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_GREEN);
    wbkgd(stdscr, COLOR_BLACK);
    wbkgd(mainWindow, COLOR_PAIR(2));
    cbreak();
    refresh();
    wrefresh(mainWindow);

    Cell *firstCell = new Cell;
    firstCell = createNewCell(0,0);
    firstCell->setUpPtr(NULL);
    firstCell->setDownPtr(NULL);
    firstCell->setLeftPtr(NULL);
    firstCell->setRightPtr(NULL);
    firstCell->setPrevPtr(NULL);
    firstCell->setNextPtr(NULL);

    createBoard(firstCell,mainWindow);

    assignUpDownPtr(firstCell);


    tests(firstCell);

    //printBoard(firstCell,mainWindow);

    endwin();
    return 0;
}
