#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

class Cat {
public:
     // variables globales a la c
    // Todos los metodos de clase pueden ver estas variables

    // Cat
    string name;
    string breed;
    int age;
    string vaccines;
    bool eating;
    bool sleeping;

    // Metodos de la clase Robot
    void meow();
    void walk();
    void jump();
    void scratch();
    void disobey();
};


#endif // CAT_H_INCLUDED
