// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

int testPile();


int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier file.c");
printf("\n 2 : tester mon fichier pile.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

int menu2()
{

int choix2;
printf("\n\n\n TEST PILE");
printf("\n\n\n 1 : initialiser");
printf("\n 2 : pilevide");
printf("\n 3 : pilepleine");
printf("\n 4 : empiler");
printf("\n 5 : depiler");
printf("\n 6 : sommet");
printf("\n 7 : hauteur");
printf("\n 8 : afficher");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix2);
return choix2;
}

int main(T_Pile * P)
{
T_File mafile;
T_Pile mapile;
int chx;
// int taille;
//char chaine[20];

T_Elt element;
T_Elt peltt;

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		testPile(&mapile);
		break;
	case 2 : //testez toutes vos fonctions par un jeu de test de votre choix
		//initPile(&mapile);
		//empiler(&mapile, elementtest);
		//empiler(&mapile, elementtest1);
		//empiler(&mapile, elementtest);
		//empiler(&mapile, elementtest1);
		//sommet(&mapile);
		// testFile(&mafile); //TP9 partie 1 : à ecrire 
		break; 
	case 3 : 
		//scanf("%s",chaine); //une chaine de longueur <=MAX
		//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}

int testPile(T_Pile * P)
{
	int chx2;

	do
	{
	chx2=menu2();
	switch (chx2)
		{
		case 1 :  
			initPile(&mapile);
			break;
		case 2 : 
			printf("\n");
			if(pilevide(&mapile))
				printf("la pile est vide !")
			else 
				printf("la pile n'est pas vide !")
			break; 
		case 3 :
			printf("\n");
			if(pilepleine(&mapile))
				printf("la pile est pleine !")
			else 
				printf("la pile n'est pas pleine !")
			break; 
		case 4 : 
			printf("\n");
			printf("saisir un element : ");
			saisirElt(&element);
			empiler(&mapile, element);
			break;
		case 5 : 
			depiler(&mapile, peltt);
			break;
		case 6 : 
			printf("Le sommet de la pile est : ");
			sommet(&mapile);
			break;
		case 7 : 
			printf("La hauteur de la pile est : %d", hauteur(&mapile));
			break;
		case 8 : 
			printf("Affichage de la pile : ");
			afficherPile(&mapile);
			break;
	}while(chx!=0);
	
	printf("\nau plaisir de vous revoir ...\n");
	return 0;
	}
}