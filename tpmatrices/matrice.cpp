#include "matrice.h"
#include <cassert>

//Constructeur
Matrice::Matrice(int m1,int n1) {
    // Notez que les parametres ne s'appellent plus m et n
    // pour ne pas melanger avec les champs!
    //*compteur = 1; // Initialisation du compteur
    m=m1;
    n=n1;
    t=new double[m*n];
    compteur = new int(1);
    get_compteur();
    cout << "Matrice creee dimension connue"<<endl;
}

//Constructeur vide


Matrice::Matrice() {
    cout << "Matrice cree vide"<<endl;
    compteur = new int(1);
    get_compteur();
}


//Constructeur de copie

Matrice::Matrice(const Matrice& B){
    compteur=B.compteur;
    m=B.m; n=B.n;
    t = new double[m*n];
    double* src=B.t;  //On initialise les deux pointeurs vers B.t et t. Pourquoi int dans le cours?
    double* dst=t;
    for(int i=0; i<m*n; i++)
        *dst++=*src++;        //pour chaque adresse, le double est copie pas a pas
    (*compteur)++; //incremente le compteur
    get_compteur();
    cout<< "Matrice copiee"<<endl;
}

//Destructeur

Matrice::~Matrice() {
    --(*compteur);
    if((*compteur)==0){            //Detruit si le compteur est à 0
        delete[] t;
        delete compteur;
        cout << "Matrice detruite"<<endl;
    }
}


double Matrice::get(int i,int j) const {
    return t[i+m*j];
}

void Matrice::set(int i,int j,double x) {
    t[i+m*j]=x;
}

void Matrice::affiche(string s) const{
    cout << s << " =" << endl;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++)
            cout << get(i,j) << " ";
        cout << endl;
    }
}

// A*B appelle A.operator*(B) donc tous
// les champs et fonctions utilises directement
// concernent ce qui etait prefixe par A. precedemment
Matrice Matrice::operator*(const Matrice& B) const {
    // On est dans l'objet A du A*B appele
    assert(n==B.m);
    Matrice C(m,B.n);
    for (int i=0;i<m;i++)
        for (int j=0;j<B.n;j++) {
            C.set(i,j,0);
            for (int k=0;k<n;k++)
                C.set(i,j,
                      C.get(i,j)+get(i,k)*B.get(k,j));

        }
    return C;
}


// Operateur egal qui est fortement recommandée a partir du moment ou on a constructeur par copie etc...

void Matrice::operator=(const Matrice& B){
    delete [] t;
    m=B.m; n=B.n;
    t = new double[m*n];
    for(int i=0;i<m*n;i++)
        t[i]=B.t[i];
}

int Matrice::nbLin() const{
    return m;
}

int Matrice::nbCol() const{
    return n;
}



// affiche la valeur du compteur

void Matrice::get_compteur() const{
    cout<<*compteur<<endl;
}





/// Definition de quelques fonctions pour generer aleatoirement, ones, et le nombre de colonne pour visualiser la copie.
///

Matrice ones(int m) {
    Matrice M(m,m);
    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            M.set(i,j,1);
    return M;
}

void InitRandom()
{
    srand((unsigned int)time(0));
}

Matrice aleatoire(int m, int n){
    Matrice M(m,n);
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            M.set(i,j,rand()%COEFFMAX);
    return M;
}

Matrice aleatoire(int m){
    return aleatoire(m,m);
}

void nombreColonnes(const Matrice m){
    cout<<"Il y a ";
    cout<<m.nbCol();
    cout<<" colonnes dans la matrice"<<endl;
}
