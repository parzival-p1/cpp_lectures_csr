#include "Process.h"

Process::Process()
{
    int number;
    srand(time(NULL));
    pid = (rand() % 9000) + 1000;
    number = rand() % 10;
    fileName = "assembly" + to_string(number) + ".txt";
    cout<<"pid: "<<pid<<" "<<fileName<<endl;
    //decoder = new Decoder(sFileName);
    Sleep(1000);
}
