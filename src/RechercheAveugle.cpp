#include "RechercheAveugle.h"
#include "iostream"
#include <algorithm>
#include <queue>
#include "Node.h"

using namespace std;

void RechercheAveugle::solve(Taquin* t) {
    if(t->getState()->isSolve()) return;

    cout << "Resolution Aveugle en cours...";

    queue<Node> open; //fifo
    vector<State> closed;

    open.push(Node(t->getState()));

    while(!open.empty()) {
        Node current = open.front();               // récupère la tete de file
        open.pop();                                // suppression de la tete de file

        cout << endl;


       list<Move> steps = current.getSteps();
        for(list<Move>::iterator it = steps.begin(); it != steps.end(); ++it){
            cout << *it;
        }
        cout << endl;


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
            if(played) { //si on a pu jouer le coup

                if(copy.isSolve()) {
                    cout << "la resolution a fonctionne !" << endl;
                    t->setState(new State(copy));

                    cout << endl << "Liste des coups: " << endl;
                    for(list<Move>::iterator it = steps.begin(); it != steps.end(); ++it){
                        cout << *it;
                    }

                    cout << endl << endl << "Affichage des 3 derniers coups joues: " << endl;
                    current.getParent()->dump();
                    current.getState()->dump();
                    copy.dump();

                    cout << endl << "closed: " << closed.size();
                    cout << endl << "opened: " << open.size() << endl << endl;
                    return;
                }

                //sinon il n'est pas résolu

                if (find(closed.begin(), closed.end(), copy) == closed.end()){ // si pas déjà présent dans fermés

                    // on l'ajoute dans ouverts
                    open.push(Node(new State(copy), steps, current.getState()));
                    // et dans fermés
                    closed.push_back(copy);
                }
            }
        }
        if(open.size() > 10000) break;
    }
    cout << "Echec de la resolution..." << endl << endl;
}
