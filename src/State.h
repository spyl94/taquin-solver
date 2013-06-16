#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
#include <set>
#include "Move.h"

class State
{
    int* tab;
    int taille;
    bool checkSolve(int,int,Move,std::set<int>*);
    int findEmpty();

public:
    State(int taille);
    State(int taille, int* tab);
    State(const State &);
    void dump() const;
    bool isSolve();

    int getTaille() const {return taille;}
    int* getTab() const {return tab;}


    bool playLeft();
    bool playRight();
    bool playUp();
    bool playDown();

    bool operator== (State const &o) const
    {
        if (taille != o.taille) return false;
        for(int i =0; i < taille*taille; i++){
            if (tab[i] != o.tab[i]) return false;
        }
        return true;
    }
};

#endif // STATE_H
