#include <iostream>
using namespace std;

typedef int mat[52][52];

class Arc_arete{

private:

    char initial;// sommet initial
    char fnal;// sommet final
    float poids;// cout de l'arc ou arete

public:

    Arc_arete();// constructeur par defaut
    Arc_arete(char,char,float);//constructeur avec parametres

    //les accesseurs et les mutateurs
    char get_initial();
    void set_initial(char);
    char get_final();
    void set_final(char);
    float get_poids();
    void set_poids(float);
    bool operator ==(Arc_arete);

    //Autres fontions de la classe 
    
      void arc_affiche();// affiche les attributs d'un objet de type Arc_arete


};
