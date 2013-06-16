#include <iostream>
#include "Taquin.h"
#include "Algorithm.h"
#include "RechercheAveugle.h"
#include "RechercheAStar.h"
#include <windows.h>

using namespace std;


int main()
{
    Taquin* t = new Taquin("T1.txt");
    t->setAlgorithm(new RechercheAveugle());
    t->solve();

    system("pause");

    t = new Taquin("T2.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T3.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T4.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T5.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T6.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T7.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T8.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T9.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    t = new Taquin("T10.txt");
    t->setAlgorithm(new RechercheAStar());
    t->solve();

    system("pause");

    //t->randomSort();

    return 0;
}

