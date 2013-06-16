#include "Taquin.h"
#include "RechercheAveugle.h"
#include "Move.h"
#include <stdlib.h>

Taquin::Taquin() :algo(new RechercheAveugle()), state(new State(3))
{}

Taquin::Taquin(std::string str) :algo(new RechercheAveugle()), state(FileParser::parse(str))
{}

Taquin::Taquin(int taille) :algo(new RechercheAveugle()), state(new State(taille))
{}

void Taquin::solve() {
    algo->solve(this);
}

void Taquin::setAlgorithm(Algorithm* algo) {
    if (algo) {
        delete this->algo;
        this->algo = algo;
       }
}

bool Taquin::isSolve() {
    return state->isSolve();
}

void Taquin::randomSort() {
    for(int i =0; i < 1 ; i++) {
        int j = rand() % COUNT;
        switch (j)
        {
            case 0: { state->playLeft(); break; }
            case 1: { state->playRight(); break; }
            case 2: { state->playDown(); break; }
            case 3: { state->playUp(); break; }
            default: break;
        }
    }
}

void Taquin::dump() {
    state->dump();
}
