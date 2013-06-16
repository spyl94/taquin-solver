#include "State.h"

using namespace std;

State::State(int taille, int* tab) : taille(taille), tab(tab)
{}

State::State(int taille)
{
    tab = new int[taille*taille];
    this->taille = taille;

    for(int i = 0 ; i < taille*taille ; i++) {
        this->tab[i] = i;
    }
}
State::State(const State &old)
{
    this->taille = old.taille;
    this->tab = new int[taille*taille];

    for(int i = 0 ; i < taille*taille ; i++) {
        this->tab[i] = old.tab[i];
    }
}

void State::dump() const {
    cout << endl << "Dump:" << endl;
    for(int i = 0 ; i < taille*taille ; i++) {
        cout << tab[i];
        if(tab[i] < 10 && taille*taille > 10) cout << " ";
        cout << "|";
        if( (i+1) % taille == 0) cout << endl;
    }
    cout << endl;
}

bool State::checkSolve(int i, int j, Move move, set<int>* previous){
    if (j == taille*taille) return true;
    if (move == RIGHT) {
        if (((i+1) % taille == 0) || previous->find(i+1) != previous->end()) return checkSolve(i,j,DOWN,previous);
        previous->insert(i);
        return tab[i] == j ? checkSolve(i+1,j+1,move,previous) : false;
    }
    if (move == DOWN) {
        if (i >= taille*taille - taille || previous->find(i+taille) != previous->end()) return checkSolve(i,j,LEFT,previous);
        previous->insert(i);
        return tab[i] == j ? checkSolve(i+taille,j+1,move,previous) : false;
    }
    if (move == LEFT) {
        if (i % taille == 0 || previous->find(i-1) != previous->end()) return checkSolve(i,j,UP,previous);
        previous->insert(i);
        return tab[i] == j ? checkSolve(i-1,j+1,move,previous) : false;
    }
    if (move == UP) {
        if (i < taille || previous->find(i-taille) != previous->end()) return checkSolve(i,j,RIGHT,previous);
        previous->insert(i);
        return tab[i] == j ? checkSolve(i-taille,j+1,move,previous) : false;
    }
}

bool State::isSolve(){
    set<int> previous;
    return checkSolve(0,1,RIGHT,&previous);
}

int State::findEmpty(){
    for(int i = 0 ; i < taille*taille; i++){
        if (tab[i] == 0) return i;
    }
    return -1; // should not happen
}

bool State::playLeft(){
    int i = findEmpty();
    if((i+1) % taille == 0) return false;
    swap(tab[i],tab[i+1]);
    return true;
}

bool State::playRight(){
    int i = findEmpty();
    if(i % taille == 0) return false;
    swap(tab[i],tab[i-1]);
    return true;
}

bool State::playUp(){
    int i = findEmpty();
    if (i >= taille*taille - taille) return false;
    swap(tab[i],tab[i+taille]);
    return true;
}

bool State::playDown(){
    int i = findEmpty();
    if (i-taille < 0) return false;
    swap(tab[i],tab[i-taille]);
    return true;
}
