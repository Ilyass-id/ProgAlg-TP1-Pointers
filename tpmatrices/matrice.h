#ifndef MATRICE_H
#define MATRICE_H

#endif // MATRICE_H

#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const int COEFFMAX = 10; //On génere des matrices ou les nombres prennent une valeur aleatoire dans 0-9.
const int NBMATRICES = 2; // nombre de matrices qu'on genere aleatoirement qu'on va multiplier etc..
const int DIMENSION = 3; //dimension des matrices aleatoires


class Matrice {
private:
    int m,n;
    double* t;
    int* compteur;
public:
    Matrice(int m1,int n1);
    Matrice();
    Matrice(const Matrice& B);
    ~Matrice();

    double get(int i,int j) const;              //renvoi l'element (i,j)
    void set(int i,int j,double x);             //defini l'element (i,j) = x
    void affiche(string s) const;               //affiche la matrice

    Matrice operator*(const Matrice& B) const;
    void operator=(const Matrice& B);

    int nbLin() const;                          //renvoi le nombre de lignes dans la matrice
    int nbCol() const;                          //renvoi le nombre de colonnes dans la matrice

    void get_compteur() const;                  //renvoi le nombre associé au pointeur (*compteur)
};


//Definition de quelques fonctions pour generer aleatoirement une matrice, une matrice remplie de 1

void InitRandom();
Matrice ones(int m);
Matrice aleatoire(int m);
Matrice aleatoire(int m, int n);

//Definition de fonction juste pour s'assurer que la copie fonctionne bien
void nombreColonnes(const Matrice m);
