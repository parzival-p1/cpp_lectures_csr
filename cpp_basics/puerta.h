#ifndef PUERTA_H_INCLUDED
#define PUERTA_H_INCLUDED

// Definicion de la clase

class Door {
public:
     // variables globales a la c
    // Todos los metodos de clase pueden ver estas variables

    // Atributos de la clase Door
    string material;
    string name;
    float height;
    float width;
    bool open;
    bool peephole; // mirilla

    // Constructores
    Door();
    Door(string);
    Door(string, string);
    Door(string, string, float, float);

    // Metodos de la clase Door
    void openDoor();
    void closeDoor();
    void isOpen();

};

// I M P L E M E N T A C I O N  D E  L O S  M E T O D O S

Door::Door()
{
    open = false;
    name = "Sin nombre";
    material = "unknown";
    cout << "Llamando al constructor 1" << endl;
}

Door::Door(string name)
{
// var de clase = parametro
    this->name = name;
    open = false;
    material = "unknown";
    cout << "Llamando al constructor 2" << endl;
}

Door::Door(string name, string material)
{
    this->name = name;
    this->material = material;
    open = false;
    cout << "Llamando al constructor 3" << endl;

}

Door::Door(string name, string material, float height, float width)
{
    this->name = name;
    this->material = material;
    this->height = height;
    this->width = width;
    open = false;
    cout << "Llamando al constructor 4" << endl;
}

void Door::openDoor(){
    open = true;
}

void Door::closeDoor()
{
    open = false;
}

void Door::isOpen()
{
    if(open)
        cout << "La puerta " << name << " esta abierta" << endl;
    else
        cout << "La puerta " << name << " esta cerrada" << endl;
}

#endif // PUERTA_H_INCLUDED
