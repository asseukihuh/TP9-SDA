#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue  = 0;
    ptrF->Tete = 0;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if (!(fileVide(ptrF)))
    {
        strcpy(*ptrE,ptrF->Elts[ptrF->Tete]);
        ptrF->Tete = (ptrF->Tete + 1) % MAX ; 
        return 1;
    }
return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if(!(filePleine(ptrF))){
        ptrF->Queue = (ptrF->Queue + 1) % MAX ;
        strcpy(ptrF->Elts[ptrF->Queue-1],*ptrE);
        return 1;
    }
return 0;
} 

int fileVide(const  T_File *ptrF) // qd Tete == 0 
{
    if (ptrF->Tete == ptrF->Queue) return 1;
return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if (ptrF->Tete == ptrF->Queue + 1) return 1;
return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    printf("Affichage File \n\n");
    for( int i = ptrF->Tete ; i<ptrF->Queue; i = (i + 1) % MAX) {
    printf("File : %s \n",ptrF->Elts[i]);
    }
}






