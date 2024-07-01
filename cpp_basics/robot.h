#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

class Robot {
private:
    // atributos privados

    // Robot
    string name;
    string brand;
    int build_year;
    int serial_num;
    bool active;

public:
    // Metodos de la clase Robot publicos
    Robot(); // constructor x default
    Robot(string name);

    void walk();
    void activate();

    void set_name(string new_name);
    string get_name();
    ~Robot(); // destructor
};

Robot::Robot(){
    this->name = "Unknown";
    cout<<"Robot Unknown was created"<<endl;
}

Robot::Robot(string name) {
    this->name = name;
    cout<<"Robot "<<this->name<<" was created"<<endl;
}

void Robot::walk(){
    cout<<"The robot "<<this->name<<" is walking..."<<endl;
}

void Robot::activate() {
    cout<<"The robot "<<this->name<<" is active..."<<endl;
}

Robot::~Robot(){

    cout<<"Robot "<<this->name<<" was destroyed"<<endl;
}

void Robot::set_name(string new_name){
    if(new_name=="R2-D2"){
        this->name = "Error";
    }else {
        this->name = new_name;
    }

}

string Robot::get_name(){
    return this->name;
}

#endif // ROBOT_H_INCLUDED
