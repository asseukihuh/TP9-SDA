#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = 0;
    ptrF->Tete = 0;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
    if (!(fileVide(ptrF)))
    {
        affecterElt(ptrE, &ptrF->Elts[ptrF->Tete]);
        ptrF->Tete = (ptrF->Tete + 1) % MAX ;
        
        return 1;
        
    }
return 0;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{   printf("test");
    if(!(filePleine(ptrF)) == 1){
        affecterElt(&ptrF->Elts[ptrF->Queue],ptrE);
        ptrF->Queue = (ptrF->Queue + 1) % MAX; 
        printf("ajout\n"); 
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
    if (ptrF->Tete == ((ptrF->Queue + 1) % MAX)) return 1;
return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    printf("Affichage File \n\n");
    int i = ptrF->Tete ;
    while ( i != ptrF->Queue){
        afficherElt(&ptrF->Elts[i]);
        i = i + 1;
        i = i % MAX;
    }
    printf("Fin");
}

void testFile(T_File * mafile , T_Elt * elmt){
    int chx;
    do{
    chx = menuFile();
    switch (chx)
    {
    case 1 :
        printf("\n\tInitialisation de la File\n");
        initFile(mafile);
        break;
    case 2 : 
        printf("\nAjouter un élément à la File\n");
        printf("Sasir Élément : \n\t");
        saisirElt(elmt);
        ajouter(mafile,elmt);
        printf("\nAjout réussi\n");
        break ;
    case 3 :
        printf("\nRetirer un élément de la File\n");
        retirer(mafile,elmt);
        printf("\nL'élément retiré est : ");
        afficherElt(elmt);
        break;
    case 4 :
        printf("\nAfficher la File\n");
        afficherFile(mafile);
        break;
    default:
        break;
    }
}while(chx!=0);

}

int menuFile(){
    int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : Init File");
printf("\n 2 : Ajouter file");
printf("\n 3 : Retirer file");
printf("\n 4 : Afficher file ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}


