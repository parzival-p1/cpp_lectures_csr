#include "Airbnb.h"
#include "Guest.h"
#include "Host.h"

Airbnb::Airbnb()
{

    cout<<"AirBnb creado"<<endl;
}

Airbnb::~Airbnb(){
    // si la agrego en el .h en la definicion de la clase, la implemento aqui.
// declaracion e implementacioon
}


/**
 * Run - inicializa el programa
 */
void Airbnb::run()
{
    airbnbMenu();
}

void Airbnb::airbnbMenu()
{
    int opt;

    do {
        cout<<"1. Arrendadores"<<endl;
        cout<<"2. Arrendatarios"<<endl;
        cout<<"3. Propiedades"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Opcion: ";
        cin >> opt;

        switch (opt) //  H A C E R  L O S   MENUS, Declararla en el .h e implementarla aqui
        {
            case 1: hostMenu(); break;
            case 2: guestMenu(); break;
            case 3: propertyMenu(); break;
            case 0: cout<<"Gracias por utilizar AirBnb! 😇"<<endl; break;
            default: cout<<"La opcion ingresada no es valida"<<endl; break;
        }

    } while (opt != 0);
}

void Airbnb::hostMenu()
{
    int opt;

    do {
        cout<<"1. Eliminar arrendador"<<endl;
        cout<<"2. Modificar arrendador"<<endl;
        cout<<"3. Listar arrendadores"<<endl;
        cout<<"4. Imprimir propiedades de un arrendador"<<endl;
        cout<<"5. Calificar al arrendatario"<<endl;
        cout<<"0. Regresar al menu principal"<<endl;
        cout<<"Opcion: ";
        cin >> opt;

        switch (opt)
        {
            case 1: deleteHost(); break;
            case 2: editHost(); break;
            case 3: printHosts(); break;
            case 4: printHostProperties(); break; // imprimir las propiedades de un host dado
            case 5: rateGuest(); break;
            case 0: break;
            default: cout<<"La opcion ingresada no es valida"<<endl; break;
        }

    } while (opt != 0);
}

void  Airbnb::guestMenu()
{
    int opt;

    do {
        cout<<"1. Crear nuevo arrendatario"<<endl;
        cout<<"2. Eliminar arrendatario"<<endl;
        cout<<"3. Modificar arrendatario"<<endl;
        cout<<"4. Listar arrendatarios"<<endl;
        cout<<"0. Regresar al menu principal"<<endl;
        cout<<"Opcion: ";
        cin >> opt;

        switch (opt)
        {
            case 1:  addGuest(); break;
            case 2:  deleteGuest(); break;
            case 3:  editGuest(); break;
            case 4:  listGuest(); break;
            case 0:  break;
            default: cout<<"La opcion ingresada no es valida"<<endl; break;
        }

    } while (opt != 0);
}

void Airbnb::propertyMenu()
{
    int opt;

    do {

        cout<<"1. Crear nueva propiedad"<<endl;
        cout<<"2. Eliminar propiedad"<<endl;
        cout<<"3. Modificar propiedad"<<endl;
        cout<<"4. Listar todas las propiedades"<<endl;
        cout<<"5. Imprimir detalles de una propiedad"<<endl;
        cout<<"6. Mostrar el top 5 de propiedades"<<endl;
        cout<<"0. Regresar al menu principal"<<endl;
        cout<<"Opcion: ";
        cin >> opt;

        switch (opt)
        {
            case 1:  addProperty(); break;
            case 2:  deleteProperty(); break;
            case 3:  editProperty(); break;
            case 4:  properties.listProperties(); break;
            case 5:  printProperty(); break;
            case 6:  showTopFive(); break;
            case 0:  break;
            default: cout<<"La opcion ingresada no es valida"<<endl; break;
        }

    } while (opt != 0);
}

// Host Functions
void Airbnb::createHost(unsigned int index) // T A R E A  anlaizar la funcion
{
//  class objeto
    Host newhost;
    string name; // name obj de tipo string
    string lastName;
    int Id;

    cout<<"Introduza el nombre: ";
    cin>>name;
    newhost.Setname(name);

    cout<<"Introduzca el apellido:  ";
    cin>>lastName;
    newhost.SetlastName(lastName);

    cout<<"Introduzca su ID: ";
    cin>>Id;
    newhost.SetId(Id);

    if(index >= 0 && index < properties.GetMAX() && index < properties.Getlast())
        properties.Getelement(index).Sethost(newhost);
    else
        cout<<"No se pudo agregar el host, indice invalido"<<endl;
}

void Airbnb::addHost(unsigned int index)
{
    properties.printHosts();
    properties.addHost(index);
}


void Airbnb::printHosts() // esta imprimie todos los host
{
    properties.printHosts();
}

   //1. esta funcion imprime todas las propiedades que pertenecen a un host
  //2. para listar las propiedades de un host tengo que preguntar por un host
 //3. para seleccionar un host tengo que listar todos los hosts, para lograr esto se manda a llamar la func
// printHosts();
void Airbnb::printHostProperties()
{
    unsigned int opt; // i+1
    // paso 3
    printHosts();

    // paso 2
    cout<<"Seleccione un host: ";
    cin>>opt;
    if (opt <= 0 || opt >= properties.Getlast())
        cout<<"El host ingresado es invalido!"<<endl;
    else
    {
        opt--;
        //paso 1
        properties.printProperties(opt);
    }
}

void Airbnb::editHost()
{
    int pIndex;

    properties.listProperties();
    cout<<"Seeleciona la propiedad que contiene al host a editar: ";
    cin>>pIndex;

    if (pIndex > 0 && pIndex <= properties.Getlast())
        properties.editHost(pIndex-1);
    else
        cout<<"Regresando al menu principal"<<endl;
}

void Airbnb::deleteHost()
{
    int pIndex;

    properties.listProperties();
    cout<<"Selecciona la propiedad: ";
    cin>>pIndex;

    if (pIndex > 0 && pIndex <= properties.Getlast())
        properties.deleteHost(pIndex-1);
    else
        cout<<"Regresando al menu principal"<<endl;
}

// califica al guest cambiarle el nombre
void Airbnb::rateGuest()
{
    // 1. Listar las propiedades y seleccionar una propiedad
    int opt, guestId, rate;

    properties.listProperties();

    cout<<"Elija la propiedad a calificar ";
    cin>>opt;

    // 2. Listar los guests y seleccionar un guest (no reusar la var de select de prop) poner otra var
    properties.listGuests(opt-1);
    cout<<"Seleccion el Guest: ";
    cin>>guestId;

    // 3. Caificar a ese guest
    cout<<"Califique en una escala del 1 al 5, siendo cinco la mayor puntuacion.";
    cin>>rate;
    properties.setGuestRate(opt-1, guestId-1, rate);
}

// Property Functions

/**
 * addProperty - Agrega un nuevo elemento al catalogo
 *
 */
void Airbnb::addProperty()
{
    Property newProperty; // creo una nueva instancia
    string stemp;
    int itemp;

    cout<<"Introduzca el nombre de la propiedad: ";
    cin>>stemp;
    newProperty.Setname(stemp);

    cout<<"Introduzca el numero de habitaciones: ";
    cin>>itemp;
    newProperty.Setrooms(itemp);

    cout<<"La propiedad tiene cocina? si/no";
    cin>>stemp;
    newProperty.Setkitchen(stemp);

    cout<<"La propiedad acepta mascotas? si/no";
    cin>>stemp;
    newProperty.SetpetFriendly(stemp);

    cout<<"La propiedad tiene estacionamiento? si/no";
    cin>>stemp;
    newProperty.Setparking(stemp);

// objeto de tipo propertyArrayList
    properties.InsertLast(newProperty);

    cout<<"1. Crear nuevo host"<<endl;
    cout<<"2. Seleccionar un host"<<endl;
    cout<<"0. Terminar"<<endl;
    cout<<"Opcion: ";
    cin>>itemp;
    switch (itemp)
    {
        case 1: createHost(properties.Getlast()-1); break;
        case 2: addHost(properties.Getlast()-1); break;
        case 0: break;
        default: cout<<"Opcion no valida"<<endl;
    }
    cout<<"La propiedad se ha agregado con exito!"<<endl;
}

/**
 * prinProperty - imprime los elementos de la propiedad
 *
 */
void Airbnb::printProperty()
{
    properties.listProperties();
    properties.printProperty();
}

/**
 * editProperty - edita las caracteristicas de la propiedad
 *
 */
void Airbnb::editProperty()
{
    int pIndex;

    properties.listProperties();
    cout<<"Elija la propiedad a editar: ";
    cin>>pIndex;

    properties.editProperty(pIndex-1);
}

/**
 * deleteProperty: elimina una propiedadz
 *
 */
 // H A C E R  D E L E T E  P R O P E R T Y
void Airbnb::deleteProperty()
{
    int pIndex;

    properties.listProperties();
    cout<<"Elija la propiedad a eliminar: ";
    cin>>pIndex;

    properties.deleteProperty(pIndex-1);
}


void Airbnb::showTopFive()
{
    properties.showTopFive();
}

void Airbnb::rateProperty(unsigned int property)
{
    // 1. Listar las propiedades y seleccionar una propiedadd
    int rate;

    // 3. Calificar esa propiedad
    cout<<"Califica en una escala del 1 al 5, siendo 5 la mayor puntuacion.";
    cin>>rate;
    properties.setPropertyRate(property, rate);
}

void Airbnb::addGuest()
{
    int property;
    string temp;
    Guest newGuest;

    cout<<"Dame el nombre del guest: ";
    cin>>temp;
    newGuest.Setname(temp);

    cout<<"Dame el apellido del guest: ";
    cin>>temp;
    newGuest.SetlastName(temp);

    cout<<"Introduzca la fecha de check in (dd/mm/aaaa): ";
    cin>>temp;
    newGuest.SetcheckIn(temp);

    cout<<"Introduzca la fecha de checkout (dd/mm/aaaa): ";
    cin>>temp;
    newGuest.SetcheckOut(temp);

    properties.listProperties();
    cout<<"Elija la propiedad donde se va a insertar el guest: ";
    cin>>property;
    properties.addGuest(property-1, newGuest); // property=index-1
    rateProperty(property-1);
}

void Airbnb::editGuest()
{
    int pIndex, gIndex;

    properties.listProperties();
    cout<<"Selecciona una propiedad: ";
    cin>>pIndex;

    properties.listGuests(pIndex-1);
    cout<<"Seleccione un guest: (0 para cancelar)";
    cin>>gIndex;

    if (gIndex != 0)
        properties.editGuest(pIndex-1, gIndex-1);
    else
        cout<<"Regresando al menu principal"<<endl;
}

void Airbnb::deleteGuest()
{
    int pIndex, gIndex;

    properties.listProperties();
    cout<<"Selecciona la propiedad: ";
    cin>>pIndex;

    properties.listGuests(gIndex);
    cout<<"Seleccione el guest a eliminar: (0 para cancelar)";
    cin>>gIndex;

    if (gIndex != 0)
        properties.deleteGuest(pIndex-1, gIndex-1);
    else
        cout<<"Regresando al menu principal"<<endl;
}

void Airbnb::listGuest()
{
    unsigned int property;
    properties.listProperties();
    cout<<"Elija la propiedad a listar sus guests: ";
    cin>>property;

    properties.listGuests(property-1);
}
