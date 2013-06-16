#ifndef RECHERCHEASTAR_H
#define RECHERCHEASTAR_H
#include "Algorithm.h"
#include "Taquin.h"
#include "State.h"

class RechercheAStar : public Algorithm
{
public:
    void solve(Taquin* t);
};

#endif // RECHERCHEASTAR_H
