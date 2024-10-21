#include "arc_arete.h"
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graphe{

private:

    int nature_du_graphe;//valeur 0  si graphe oriente et valeur 1 si graphe non oriente
    int nombre_sommets;//nombre de sommets du graphes
    int nombre_arcs;//nombre d'arcs du graphe
    vector<char> liste_sommets;//liste des sommets du graphe
    vector< Arc_arete > arcs; // liste des arcs ou aretes du graphes (100 au maximum)
    mat matriceadjacence;//matrice d'adjacence du graphe

public:
    Graphe();//constructeur par defaut
    Graphe(int,int,int,vector<char>, vector<Arc_arete>,mat);//constructeur avec parametres
    
    //accesseurs et mutateurs

    int get_nature_du_graphe();
    void set_nature_du_graphe(int);
    int get_nombre_sommets();
    void set_nombre_sommets(int);
    int get_nombre_arcs();
    void set_nombre_arcs(int);
    vector<char> get_liste_sommets();
    void set_liste_sommets(vector<char>);
    vector<Arc_arete> get_arcs();
    void set_arcs(vector<Arc_arete>);
    //mat get_matriceadjacence();
    void set_matriceadjacence(mat);

    //Autres fonctions de la classe

    void graphe_affiche_mat();
    void graphe_affiche_som();
    void graphe_affiche_arc();
    void sommet();
    void initialiser();
    void ajout_arete(char,char,float);
    void build_arete();
    void ajout_sommet(char);
    void adjacence();
    void connexe();
    void oconnexe();
    vector <char> liste_adjacence(char);
    vector <char> liste_predecesseur(char);
    vector<vector<int> > ComposantesConnexes();
    void affiche_comp_con();


};