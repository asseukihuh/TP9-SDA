#include "pile.h"



//Fonctionne

void initPile( T_Pile * P)
{
    P->nbElts = 0;
}

//Fonctionne

int pilepleine(const  T_Pile *P)
{
    return P->nbElts == MAX;
}

//Fonctionne

int pilevide(const  T_Pile *P)
{
    return P->nbElts == 0;
}

//Fonctionne

int empiler(T_Pile * P, T_Elt e) {
    if (pilepleine(P)) 
        return 0; 
    affecterElt(&P->Elts[P->nbElts], &e); 
    P->nbElts++;
    return 1; 
}

//Fonctionne

int depiler( T_Pile * P, T_Elt *pelt)  //renvoie 0 si pile vide, sinon 1
{
    if (pilevide(P))
        return 0; 
    affecterElt(pelt, &P->Elts[P->nbElts -1]);
    P->nbElts--;
    return 1; 
}

//Fonctionne

T_Elt sommet(const  T_Pile *P) {
    if (pilevide(P)) return 0;
    afficherElt(&P->Elts[P->nbElts - 1]);
    return 1; 
}

//Fonctionne

int hauteur(const  T_Pile *P)
{
    return P->nbElts;
}

void afficherPile(T_Pile * P) 
{
    T_Pile temp = *P;
    T_Elt elt;
    while (!pilevide(&temp)) { 
        depiler(&temp, &elt); 
        afficherElt(&elt);
    } 
}








