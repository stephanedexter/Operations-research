#include "graphe.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<queue>
 
using namespace std;

int main()

{   
    int n;
    Graphe g;
    cout<<"Entrer le nombre de sommet de votre graphe"<<endl;
    cin>>n;
    g.set_nombre_sommets(n);
    g.initialiser();
    g.graphe_affiche_mat();
    g.set_nombre_sommets(n);
    cout<<" la matrice d'adjacence du graphe initialisee a 0 :"<<endl;
    g.sommet();
    g.build_arete();
    g.graphe_affiche_mat();
    g.ComposantesConnexes();
    g.affiche_comp_con();
    /*cout<<"*******************************"<<endl;
    g.sommet();
    cout<<"*******************************"<<endl;
    g.graphe_affiche_som();
    g.build_arete();
    cout<<"*******************************"<<endl;
    g.graphe_affiche_arc();
    cout<<"*******************************"<<endl;
    cout<<" la matrice d'adjacence du graphe :"<<endl;
    g.graphe_affiche_mat();
    cout<<"*******************************"<<endl;
    g.adjacence();
    cout<<"*******************************"<<endl;
    g.connexe();
    g.oconnexe();
    cout<<"*******************************"<<endl;*/


    return 0;
}
    

