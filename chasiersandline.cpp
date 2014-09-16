#include "Libraries.h"

using namespace std;


Customer::Customer()
{
    timeInLine = 0;
    numOfItems = rand() % 20 + 1;
    expectedServiceTime = (numOfItems/2) * 5;
}

void Customer::setTimeInLine(int timeInLine)
{
    this->timeInLine = timeInLine;
}

void Customer::setExpectedServiceTime(int serviceTime)
{
    this->expectedServiceTime = serviceTime;
}

void Customer::setNextPtr(Customer* nextPtr)
{
    this->nextPtr = nextPtr;
}

void Customer::setPrevPtr(Customer* prevPtr)
{
    this->prevPtr = prevPtr;
}

int Customer::getTimeInLine()
{
    return timeInLine;
}

int Customer::getExpectedServiceTime()
{
    return expectedServiceTime;
}

int Customer::getNumOfItems()
{
   return numOfItems;
}

Customer* Customer::getNextPtr()
{
    return nextPtr;
}

Customer* Customer::getPrevPtr()
{
    return prevPtr;
}

void Customer::addToTimeInLine()
{
    timeInLine++;
}

void Customer::decideServiceTime()
{
    int minutes = rand() % 4 + 1;
    expectedServiceTime = minutes * 5;
}


Customer* createNewCustomer()
{
    Customer *customerToAdd = new Customer;
    customerToAdd->setNextPtr(NULL);
    customerToAdd->setPrevPtr(NULL);

    return customerToAdd;
}

void clearVector(vector <int>&timeVector)
{
    while(timeVector.size() != 0)
    {
        timeVector.pop_back();
    }
}

void addCustomerToLine(Customer *&CashierTail, Customer *&newCustomer)
{
    Customer* oldLast = CashierTail->getPrevPtr();

    oldLast->setNextPtr(newCustomer);
    CashierTail->setPrevPtr(newCustomer);

    newCustomer->setNextPtr(CashierTail);
    newCustomer->setPrevPtr(oldLast);
}

Customer* takeCustomerOutOfLine(Customer *&Cashier)
{
    Customer* leavingLine = Cashier->getNextPtr();
    Customer* newFirst = leavingLine->getNextPtr();

    leavingLine->setNextPtr(NULL);
    leavingLine->setPrevPtr(NULL);

    Cashier->setNextPtr(newFirst);
    newFirst->setPrevPtr(Cashier);

    return leavingLine;
}

int countCustomers(Customer* Cashier)
{
    int counter = 0;

    Customer *traversePtr = Cashier;

    while(traversePtr->getNextPtr() != NULL)
    {
        counter++;
        traversePtr = traversePtr->getNextPtr();
    }

    return counter;
}

void addToWaitTime(Customer* &Cashier,int numToAdd)
{
    Customer *traversePtr = Cashier;

    while(traversePtr->getNextPtr() != NULL)
    {
        traversePtr->setTimeInLine(traversePtr->getTimeInLine()+numToAdd);
        traversePtr = traversePtr->getNextPtr();
    }

}

float findAverageWait(vector <int> timeVector)
{
    int average = 0;
    int total = 0;

    for(int i = 0; i < timeVector.size(); i++)
    {
        total = total + timeVector[i];
    }

    average = total/timeVector.size();

    return average;
}

float findLongestWait(vector <int> timeVector)
{
    int longestWait = timeVector[0];

    for(int i = 0; i < timeVector.size(); i++)
    {
        if(timeVector[i] > longestWait)
            longestWait = timeVector[i];
    }

    return longestWait;
}

void simulation1Cashier1Line(int iterations, vector <int> &timeVector, ofstream &oFile)
{
    Customer *Cashier1 = new Customer;
    Customer *Cashier1Tail = new Customer;
    Cashier1->setNextPtr(Cashier1Tail);
    Cashier1->setPrevPtr(NULL);
    Cashier1Tail->setNextPtr(NULL);
    Cashier1Tail->setPrevPtr(Cashier1);

    Customer *customerToAdd = NULL;
    Customer *customerLeaving = NULL;

    int newCustomerPerMin = 0;
    int addNewCustomer = 0;
    int startMinute = 0;
    int CustomersAdded = 0;
    int serviceTime = 0;
    int startTime = 0;
    int endTime = 0;

    for(int i = 0; i < iterations;i++)
    {
        endTime = startTime+serviceTime;
        if(i == 0 || i == endTime)
        {
            if(i ==0)
            {
                customerToAdd = createNewCustomer();
                addCustomerToLine(Cashier1Tail,customerToAdd);
                serviceTime = customerToAdd->getExpectedServiceTime();
                startTime = 1;
            }
            if(i == endTime || Cashier1->getNextPtr() != Cashier1Tail)
            {
                customerLeaving = takeCustomerOutOfLine(Cashier1);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                startTime = i+1;
                serviceTime = Cashier1->getNextPtr()->getExpectedServiceTime();
            }
        }
        else
        {
            if(i == startMinute + 1)
            {
                addToWaitTime(Cashier1,1);
                newCustomerPerMin = 0;
            }

            if(newCustomerPerMin < 2)
            {
                addNewCustomer = rand() % 2;//decides if more people come to line
                if(addNewCustomer == 1)
                {
                    CustomersAdded = rand() % 3;//decides how many people join line
                    for(int x = 0; x < CustomersAdded; x++)
                    {
                        customerToAdd = createNewCustomer();
                        addCustomerToLine(Cashier1Tail,customerToAdd);
                        newCustomerPerMin++;
                    }
                }
            }
        }
    }

    oFile << "   " << iterations/5 << " minutes: " << endl;
    oFile << "      Customers served: " << timeVector.size() << endl;
    oFile << "      Average wait: " << findAverageWait(timeVector)/5 << " minute(s)" << endl;
    oFile << "      Longest wait: " << findLongestWait(timeVector)/5 << " minute(s)" << endl << endl << endl;
}

void simulationMultCashiersMultLines(int iteration, vector <int> &timeVector, ofstream &oFile)
{
    Customer *Cashier1 = new Customer;
    Customer *Cashier1Tail = new Customer;
    Cashier1->setNextPtr(Cashier1Tail);
    Cashier1->setPrevPtr(NULL);
    Cashier1Tail->setNextPtr(NULL);
    Cashier1Tail->setPrevPtr(Cashier1);

    Customer *Cashier2 = new Customer;
    Customer *Cashier2Tail = new Customer;
    Cashier2->setNextPtr(Cashier2Tail);
    Cashier2->setPrevPtr(NULL);
    Cashier2Tail->setNextPtr(NULL);
    Cashier2Tail->setPrevPtr(Cashier2);

    Customer *Cashier3 = new Customer;
    Customer *Cashier3Tail = new Customer;
    Cashier3->setNextPtr(Cashier3Tail);
    Cashier3->setPrevPtr(NULL);
    Cashier3Tail->setNextPtr(NULL);
    Cashier3Tail->setPrevPtr(Cashier3);

    Customer *customerToAdd = NULL;
    Customer *customerLeaving = NULL;

    int newCustomerPerMin = 0;
    int addNewCustomer = 0;
    int startMinute = 0;
    int customersAdded = 0;
    int firstLine = 0;
    int secondLine = 0;
    int thirdLine = 0;
    int serviceTime1 = 0;
    int serviceTime2 = 0;
    int serviceTime3 = 0;
    int startTime1 = 0;
    int startTime2 = 0;
    int startTime3 = 0;
    int availabeCashiers = 0;

    serviceTime1 = Cashier1->getNextPtr()->getExpectedServiceTime();
    serviceTime2 = Cashier2->getNextPtr()->getExpectedServiceTime();
    serviceTime3 = Cashier3->getNextPtr()->getExpectedServiceTime();

    int endTime1 = startTime1 + serviceTime1;
    int endTime2 = startTime2 + serviceTime2;
    int endTime3 = startTime3 + serviceTime3;

    for(int i = 0; i < iteration;i++)
    {
        endTime1 = startTime1 + serviceTime1;
        endTime2 = startTime2 + serviceTime2;
        endTime3 = startTime3 + serviceTime3;

        if(i == 0 || i == endTime1 || i == endTime2 || i == endTime3)
        {
            if(i == 0)
            {
                customerToAdd = createNewCustomer();
                addCustomerToLine(Cashier1Tail,customerToAdd);

                customerToAdd = createNewCustomer();
                addCustomerToLine(Cashier2Tail,customerToAdd);

                customerToAdd = createNewCustomer();
                addCustomerToLine(Cashier3Tail,customerToAdd);

                serviceTime1 = Cashier1->getNextPtr()->getExpectedServiceTime();
                serviceTime2 = Cashier2->getNextPtr()->getExpectedServiceTime();
                serviceTime3 = Cashier3->getNextPtr()->getExpectedServiceTime();
                startTime1 = 1;
                startTime2 = 1;
                startTime3 = 1;

            }
            if(i == endTime1 && Cashier1->getNextPtr() != Cashier1Tail)
            {
                customerLeaving = takeCustomerOutOfLine(Cashier1);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                serviceTime1 = Cashier1->getNextPtr()->getExpectedServiceTime();
                startTime1 = i + 1;
            }
            if(i == endTime2 && Cashier2->getNextPtr() != Cashier2Tail)
            {
                customerLeaving = takeCustomerOutOfLine(Cashier2);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                serviceTime2 = Cashier2->getNextPtr()->getExpectedServiceTime();
                startTime2 = i+1;
            }
            if(i == endTime3 && Cashier3->getNextPtr() != Cashier3Tail)
            {
                customerLeaving = takeCustomerOutOfLine(Cashier3);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                serviceTime3 = Cashier3->getNextPtr()->getExpectedServiceTime();
                startTime3 = i+1;
            }
        }
        else
        {
            if(i == startMinute + 1)
            {
                addToWaitTime(Cashier1,1);
                addToWaitTime(Cashier2,1);
                addToWaitTime(Cashier3,1);
                newCustomerPerMin = 0;
            }

             if(newCustomerPerMin < 2)
            {
                addNewCustomer = rand() % 2;//decides if more people come to line
                if(addNewCustomer == 1)
                {
                    customersAdded = rand() % 3;//decides how many people join line
                    for(int x = 0; x < customersAdded; x++)
                    {
                        customerToAdd = createNewCustomer();
                        firstLine = countCustomers(Cashier1);
                        secondLine = countCustomers(Cashier2);
                        thirdLine = countCustomers(Cashier3);
                        if(firstLine == secondLine || firstLine == thirdLine)
                            addCustomerToLine(Cashier1Tail,customerToAdd);
                        else if(secondLine == thirdLine)
                            addCustomerToLine(Cashier2Tail,customerToAdd);
                        else
                        {
                            if(firstLine < secondLine && firstLine < thirdLine)
                                addCustomerToLine(Cashier1Tail,customerToAdd);
                            else if(secondLine < firstLine && secondLine < thirdLine)
                                addCustomerToLine(Cashier2Tail,customerToAdd);
                            else
                                addCustomerToLine(Cashier3Tail,customerToAdd);
                        }
                        newCustomerPerMin++;
                    }
                }
            }
        }
    }

    oFile << "   " << iteration/5 << " minutes: " << endl;
    oFile << "      Customers served: " << timeVector.size() << endl;
    oFile << "      Average wait: " << findAverageWait(timeVector)/5 << " minute(s)" << endl;
    oFile << "      Longest wait: " << findLongestWait(timeVector)/5 << " minute(s)" << endl << endl << endl;
}

void simulationMultCashiers1Line(int iteration, vector <int> &timeVector, ofstream &oFile)
{
    Customer *Line = new Customer;
    Customer *EndLine = new Customer;
    Line->setNextPtr(EndLine);
    Line->setPrevPtr(NULL);
    EndLine->setNextPtr(NULL);
    EndLine->setPrevPtr(Line);

    Customer *customerToAdd = NULL;
    Customer *customerLeaving = NULL;

    int newCustomerPerMin = 0;
    int addNewCustomer = 0;
    int startMinute = 0;
    int customersAdded = 0;
    int cashiersFree = 3;
    int startTime1 = 0;
    int startTime2 = 0;
    int startTime3 = 0;
    int endTime1 = 0;
    int endTime2 = 0;
    int endTime3 = 0;
    int serviceTime1 = 0;
    int serviceTime2 = 0;
    int serviceTime3 = 0;

    for(int i = 0; i < iteration;i++)
    {
        endTime1 = startTime1 + serviceTime1;
        endTime2 = startTime2 + serviceTime2;
        endTime3 = startTime3 + serviceTime3;
        if(i == 0 || i == endTime1 || i == endTime2 || i == endTime3)
        {
            if(i == 0)
            {
                customerToAdd = createNewCustomer();
                addCustomerToLine(EndLine,customerToAdd);
                customerToAdd = createNewCustomer();
                addCustomerToLine(EndLine,customerToAdd);
                customerToAdd = createNewCustomer();
                addCustomerToLine(EndLine,customerToAdd);
            }
            if(i == endTime1 && Line->getNextPtr() != EndLine)
            {
                customerLeaving = takeCustomerOutOfLine(Line);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                startTime1 = i+1;
                serviceTime1 = Line->getNextPtr()->getExpectedServiceTime();
            }
            if(i == endTime2 && Line->getNextPtr() != EndLine)
            {
                customerLeaving = takeCustomerOutOfLine(Line);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                startTime2 = i+1;
                serviceTime2 = Line->getNextPtr()->getExpectedServiceTime();
            }
            if(i == endTime3 && Line->getNextPtr() != EndLine)
            {
                customerLeaving = takeCustomerOutOfLine(Line);
                timeVector.push_back(customerLeaving->getTimeInLine());
                delete customerLeaving;
                startMinute = i;
                startTime3 = i+1;
                serviceTime3 = Line->getNextPtr()->getExpectedServiceTime();
            }
        }
      else
        {
            if(i == startMinute + 1)
            {
                addToWaitTime(Line,1);
                newCustomerPerMin = 0;
            }

             if(newCustomerPerMin < 2)
            {
                addNewCustomer = rand() % 2;//decides if more people come to line
                if(addNewCustomer == 1)
                {
                    customersAdded = rand() % 3;//decides how many people join line
                    for(int x = 0; x < customersAdded; x++)
                    {
                        customerToAdd = createNewCustomer();
                        addCustomerToLine(EndLine,customerToAdd);
                        newCustomerPerMin++;
                    }
                }
            }
        }
    }

    oFile << "   " << iteration/5 << " minutes: " << endl;
    oFile << "      Customers served: " << timeVector.size() << endl;
    oFile << "      Average wait: " << findAverageWait(timeVector)/5 << " minute(s)" << endl;
    oFile << "      Longest wait: " << findLongestWait(timeVector)/5 << " minute(s)" << endl << endl << endl;
}
