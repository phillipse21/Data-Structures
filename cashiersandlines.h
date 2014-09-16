#ifndef cashiersandlines_H
#define cashiersandlines_H

#include "Libraries.h"

using namespace std;


class Customer
{
public:
    Customer();
    void setTimeInLine(int timeInLine);
    void setExpectedServiceTime(int serviceTime);
    void setNextPtr(Customer* nextPtr);
    void setPrevPtr(Customer* prevPtr);
    int getTimeInLine();
    int getExpectedServiceTime();
    int getNumOfItems();
    Customer* getNextPtr();
    Customer* getPrevPtr();
    void addToTimeInLine();
    void decideServiceTime();
private:
    int timeInLine;
    int expectedServiceTime;
    int numOfItems;
    Customer* nextPtr;
    Customer* prevPtr;
};

Customer* createNewCustomer();

void clearVector(vector <int>&timeVector);

void addCustomerToLine(Customer *&CashierTail, Customer* &newCustomer);

Customer* findShortestLine(Customer* Cashier1,Customer* Cashier2,Customer* Cashier3);

int countCustomers(Customer* Cashier);

void addToWaitTime(Customer* &Cashier);

float findAverageWait(vector <int> timeVector);

float findLongestWait(vector <int> timeVector);

void simulation1Cashier1Line(int iterations, vector <int> &timeVector, ofstream &oFile);

void simulationMultCashiersMultLines(int iteration, vector <int> &timeVector, ofstream &oFile);

void simulationMultCashiers1Line(int iteration, vector <int> &timeVector, ofstream &oFile);



#endif
