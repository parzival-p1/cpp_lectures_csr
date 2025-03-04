#include "Definitions.h"

void Registers::cleanRegisters()
{
    Ax = Bx = Cx = Dx = IR = 0;
}

void Registers::print()
{
    cout<<"Ax: "<<Ax<<endl;
    cout<<"Bx: "<<Bx<<endl;
    cout<<"Cx: "<<Cx<<endl;
    cout<<"Dx: "<<Dx<<endl;
    cout<<"IR: "<<IR<<endl;
}
