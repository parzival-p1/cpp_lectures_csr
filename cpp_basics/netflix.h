#ifndef NETFLIX_H_INCLUDED
#define NETFLIX_H_INCLUDED

class Netflix {
public:
    // variables globales a la c
    // Todos los metodos de clase pueden ver estas variables

    // Netflix
    string profile;
    string categories[100];
    string recommended;
    float duration;
    float rating;
    bool play;
    bool stop;

    // Metodos de la clase Netflix
    void isPlaying();
    void itStop();
};


#endif // NETFLIX_H_INCLUDED
