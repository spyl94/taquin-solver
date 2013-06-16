#ifndef TAQUIN_H
#define TAQUIN_H
#include "State.h"
#include "RechercheAveugle.h"
#include "FileParser.h"
#include <string>

class Taquin
{
    Algorithm* algo;
    State* state;

public:
    Taquin();
    Taquin(int taille);
    Taquin(std::string str);

    void solve();
    void randomSort();
    void setAlgorithm(Algorithm* algo);
    void dump();
    bool isSolve();
    State* getState() {return state;}
    void setState(State* state) {this->state=state;}
};

#endif // TAQUIN_H
