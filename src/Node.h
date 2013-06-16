#ifndef NODE_H
#define NODE_H
#include <list>
#include "Move.h"
#include "State.h"

class Node
{
    State* state;
    std::list<Move> steps;
    State* parent;
    int g_cost; // cout cumulé depuis l'etat initial
    int f_cost; // cout cumulé + heuristique

public:
    Node(State* state, int f_cost = 0) : state(state), f_cost(f_cost)
    {}

    Node(State* state, std::list<Move> steps, State* parent, int f_cost = 0, int g_cost = 0) : state(state), steps(steps), parent(parent),
        f_cost(f_cost), g_cost(g_cost)
    {}

    State* getState(){return state;}
    State* getConstState() const {return state;}
    std::list<Move> getSteps(){return steps;}
    State* getParent(){return parent;}
    int getG() const {return g_cost;}
    int getF() const {return f_cost;}

    bool operator== (Node const &o) const
    {
        if (state->getTaille() != o.getConstState()->getTaille()) return false;
        for(int i =0; i < state->getTaille()*state->getTaille(); i++){
            if (state->getTab()[i] != o.getConstState()->getTab()[i]) return false;
        }
        return true;
    }

};

#endif // NODE_H
