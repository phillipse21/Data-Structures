#include "Libraries.h"

//5 seconds = 1 minute in simulation

using namespace std;

int main()
{
    ofstream oFile("output.txt");
    srand(time(NULL));

    int iterations = 0;

    vector <int> timeWait;

    //1 cashier,1 line, 30 minutes
    oFile << "1 Cashier & 1 Line: " << endl;
    iterations = 150;//5 iterations = 1 minute
    simulation1Cashier1Line(iterations,timeWait,oFile);
    clearVector(timeWait);
    //i cashier, 1 line, 60 minutes
    iterations = 300;
    simulation1Cashier1Line(iterations,timeWait,oFile);
    clearVector(timeWait);
    //1 cashier, 1 line,120 minutes
    iterations = 600;
    simulation1Cashier1Line(iterations,timeWait,oFile);
    clearVector(timeWait);
    //1 cashier, 1 line, 480 minutes
    iterations = 2400;
    simulation1Cashier1Line(iterations,timeWait,oFile);
    clearVector(timeWait);

    //multiple cashiers, multiple lines
    oFile << "Multiple Cashiers & multiple lines" << endl;
    //30 minutes
    iterations = 150;
    simulationMultCashiersMultLines(iterations,timeWait,oFile);
    clearVector(timeWait);
    //60 minutes
    iterations = 200;
    simulationMultCashiersMultLines(iterations,timeWait,oFile);
    clearVector(timeWait);
    //120 minutes
    iterations = 600;
    simulationMultCashiersMultLines(iterations,timeWait,oFile);
    clearVector(timeWait);
    //480 minutes
    iterations = 2400;
    simulationMultCashiersMultLines(iterations,timeWait,oFile);
    clearVector(timeWait);

    oFile << "Multiple Cashiers & 1 Line" << endl;
    //30 minutes
    iterations = 150;
    simulationMultCashiers1Line(iterations,timeWait,oFile);
    clearVector(timeWait);
    //60 minutes
    iterations = 200;
    simulationMultCashiers1Line(iterations,timeWait,oFile);
    clearVector(timeWait);
    //120 minutes
    iterations = 600;
    simulationMultCashiers1Line(iterations,timeWait,oFile);
    clearVector(timeWait);
    //480 minutes
    iterations = 2400;
    simulationMultCashiers1Line(iterations,timeWait,oFile);
    clearVector(timeWait);

    return 0;
}
