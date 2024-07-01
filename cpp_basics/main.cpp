#include <iostream>
#include <string>
using namespace std;
#include "robot.h"

void createRobot(){
    Robot r("C3-PO");
    r.activate();
}

int main()
{
//    Door door1, door2("Puerta de entrada"), door3("Puerta del banho", "Madera");
//
//    door1.isOpen();
//    door2.isOpen();
//    door3.isOpen();

    createRobot();
    Robot r1, r2("R2-D2");
    r1.walk();
    r2.walk();
    r1.set_name("Pedro");
    r1.walk();

    return 0;
}

/**
 * Dar 3 clases diferentes con al menos 5 atributos c/u y 3 metodos (no incluye constructores)
 * Como seria la clase Netflix (que attributos y metodos tendria) que aplican para Netflix
 *
 */
