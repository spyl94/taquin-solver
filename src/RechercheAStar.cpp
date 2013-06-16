#include "RechercheAStar.h"
#include "iostream"
#include <algorithm>
#include <queue>
#include "Node.h"

using namespace std;


Node select_min_f(vector<Node>* open) {
    Node min = open->front();
    for(vector<Node>::iterator it = open->begin() + 1; it != open->end(); ++it){
        if (it->getF() < min.getF()) min = *it;
    }
    return min;
}

int manhattan(int xa, int xb, int ya, int yb) {
    int x = (xa > xb) ? (xa - xb) : (xb - xa);
    int y = (ya > yb) ? (ya - yb) : (yb - ya);
    return x + y;
}

int* generateSolve(int taille) {
    int* tab = new int[taille*taille];
    // 3x3 TODO : adaptable en n*n
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 8;
    tab[4] = 0;
    tab[5] = 4;
    tab[6] = 7;
    tab[7] = 6;
    tab[8] = 5;
    return tab;
}

int h(State state) {
    int heuristique = 0;
    int* tab = state.getTab();
    int* solve = generateSolve(state.getTaille());

    for(int i = 0; i < state.getTaille()*state.getTaille(); i++){
        if(tab[i] != solve[i]) {
            // a est le point actuel, b est sa position finale
            int j = 0;
            while (solve[j] != tab[i]) j++; // j est l'identifiant de b

            heuristique += manhattan(
                        i % state.getTaille(),      // xa
                        j % state.getTaille(),      // xb
                        i % state.getTaille() + 1,  // ya
                        j % state.getTaille() + 1); // yb
        }
    }
    return heuristique;
}

void RechercheAStar::solve(Taquin* t) {

    cout << "Resolution A-Star en cours...";

    vector<Node> open;
    vector<State> closed;

    open.push_back(Node(t->getState(), 0)); // g initial state = 0

    while(!open.empty()) {
        Node current =  select_min_f(&open);       // récupère le cout min parmis open

        if(current.getState()->isSolve()) {
            cout << "la resolution a fonctionne !" << endl;
            t->setState(new State(*current.getState()));
            list<Move> steps = current.getSteps();
            for(list<Move>::iterator it = steps.begin(); it != steps.end(); ++it){
                cout << *it;
            }
            cout << endl;
            return;
        }

        remove(open.begin(), open.end(), current);   // suppression de l'element

        if (find(closed.begin(), closed.end(), *current.getState()) == closed.end()){ // si pas déjà présent dans fermés
            closed.push_back(*current.getState());
        }

        // on joue toutes les combinaisons possibles
        for(int i =0; i < COUNT ; i++) {

            State copy = State(*current.getState());
            list<Move> steps = current.getSteps();
            bool played = false;

            switch (i)
            {
                case 0: { played = copy.playLeft(); if(played) steps.push_back(LEFT); break; }
                case 1: { played = copy.playRight(); if(played) steps.push_back(RIGHT); break; }
                case 2: { played = copy.playDown(); if(played) steps.push_back(DOWN); break; }
                case 3: { played = copy.playUp(); if(played) steps.push_back(UP); break; }
                default: break;
            }
            if(played) { //si on a pu jouer un coup

                if(find(closed.begin(), closed.end(), copy) == closed.end() &&
                        find(open.begin(), open.end(), Node(&copy)) == open.end()) // on a rien trouvé
                {
                    // on l'ajoute dans ouverts
                    open.push_back(    Node(
                                            new State(copy),
                                            steps,
                                            current.getState(),
                                            current.getG() + 1,
                                            current.getG() + 1 + h(copy)
                                        ));

                }
            }
        }
    }
    cout << "Echec de la resolution..." << endl << endl;
}
