#include "matrice.h"

//ATTENTION : Mon programme fonctionne en mode release, seulement en mode Debug parfois ca crash parfois ca compile mais tout en haut
//Du programme il y a le message suivant :
//FTH: (6864): *** Fault tolerant heap shim applied to current process. This is usually due to previous crashes. ***
//En regardant sur internet j'ai cru comprendre que tous ceux qui avaient cette mention tentaient de la desactiver

int main()
{
    InitRandom();
    Matrice M[DIMENSION];
    for(int i=0; i<NBMATRICES;i++)
    {
        M[i] = aleatoire(DIMENSION);
        M[i].affiche(to_string(i) + " eme matrice");
    }

    Matrice A = M[0]*M[1];
    A.affiche("A");
    nombreColonnes(A);
    return 0;
}
