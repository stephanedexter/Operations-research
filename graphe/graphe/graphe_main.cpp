#include "graphe.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
 
using namespace std;
 
int main()
{    
     cout<<endl; 
    cout<<"                  TP C++ (Implemation Graphe et manipulation)                 "<<endl;
    cout<<endl;
    int c;
    while (c!=3)
    {
        cout<<"                                    MENU                        "<<endl;
        cout<<endl;

        cout<<"             1-Construire un graphe et afficher des informations sur le graphe                  "<<endl;
        cout<<endl;

        cout<<"             2- lire un graphe à partir d'un fichier et afficher des informations sur ce graphe                  "<<endl;
        cout<<endl;

        cout<<"             3-Quitter                          "<<endl;
        cout<<endl;
        
        cout<<"Veiller le chiffre qui correspond à l'action que vous desirez effectuer sur le menu"<<endl;
        cout<<endl;

        do
        {
            cin>>c;
        }while((c!=1)and(c!=2)and(c!=3));
        

            if(c==1)
            {
                int n;
                Graphe g;
                cout<<"Entrer le nombre de sommet de votre graphe"<<endl;
                cin>>n;
                g.set_nombre_sommets(n);
                g.initialiser();
                cout<<" la matrice d'adjacence du graphe initialisee a 0 :"<<endl;
                g.graphe_affiche_mat();
                cout<<"*******************************"<<endl;
                g.sommet();
                cout<<"*******************************"<<endl;
                cout<<" les sommets du graphe sont :"<<endl;
                g.graphe_affiche_som();
                cout<<"*******************************"<<endl;
                g.build_arete();
                cout<<"*******************************"<<endl;
                if(g.get_nature_du_graphe()==0)
                    cout<<"votre graphe est orienté"<<endl;
                else
                    cout<<"votre graphe n'est pas oriente"<<endl;
                cout<<"*******************************"<<endl;
                if(g.get_nature_du_graphe()==0)
                    cout<<"les arcs du graphe sont :"<<endl;
                else
                    cout<<"les aretes du graphe sont :"<<endl;
                g.graphe_affiche_arc();
                cout<<"*******************************"<<endl;
                cout<<" la matrice d'adjacence du graphe :"<<endl;
                g.graphe_affiche_mat();
                cout<<"*******************************"<<endl;
                g.adjacence();
                cout<<"*******************************"<<endl;
                if(g.get_nature_du_graphe()==0)
                    g.oconnexe();
                else
                    g.connexe();
                cout<<"*******************************"<<endl;
                g.ComposantesConnexes();
                if(g.get_nature_du_graphe()==0)
                    {}
                else
                    g.affiche_comp_con();
                cout<<"*******************************"<<endl;
                //g.affiche_comp_con();
                cout<<"*******************************"<<endl;
                g.ajout_sommet('s');
                cout<<" les sommets du graphe sont :"<<endl;
                g.graphe_affiche_som();
                cout<<"*******************************"<<endl;
                g.ajout_arete('c','s',5);
                if(g.get_nature_du_graphe()==0)
                    cout<<"les arcs du graphe sont :"<<endl;
                else
                    cout<<"les aretes du graphe sont :"<<endl;
                g.graphe_affiche_arc();
                cout<<"*******************************"<<endl;
                cout<<" la matrice d'adjacence de votre nouveau graphe :"<<endl;
                g.graphe_affiche_mat();
                cout<<"*******************************"<<endl;
                g.adjacence();
                cout<<"*******************************"<<endl;
                if(g.get_nature_du_graphe()==0)
                    g.oconnexe();
                else
                    g.connexe();
                cout<<"*******************************"<<endl;
                g.ComposantesConnexes();
                if(g.get_nature_du_graphe()==0)
                    {}
                else
                    g.affiche_comp_con();
                cout<<"*******************************"<<endl;
                //g.affiche_comp_con();
                cout<<"*******************************"<<endl;
                /*if(g.connexe())
                    cout<<"ce graphe est  connexe"<<endl;
                else
                    cout<<"ce graphe n'est connexe"<<endl; */
                      
                

            }
            if(c==2)
            {
                ifstream fichier("test.txt", ios::in);  // on ouvre en lecture
        
                if(fichier)  // si l'ouverture a fonctionné
                {
                    int entier1,entier2,entier3;
                    char caractere,init,fin;
                    float weight;
                    Arc_arete a;
                    vector<Arc_arete> arc;
                    Graphe g;
                    vector<char> lsom;
                    mat mat_adj,mat_poids;
        
                        fichier >> entier1;
                        cout << entier1 <<endl;;  // on affiche la ligne
                        g.set_nombre_sommets(entier1);
                        g.initialiser();
                        cout<<" la matrice d'adjacence du graphe initialisée à 0 :"<<endl;
                        g.graphe_affiche_mat();
                        fichier >> caractere;
                        while(caractere != '*')
                        {
                            lsom.push_back(caractere);
                            fichier>>caractere;
                        }
                        g.set_liste_sommets(lsom);
                        cout<<" les sommets du graphe sont :"<<endl;
                        g.graphe_affiche_som();

                        fichier>>entier2;
                        cout<<entier2<<endl;
                        g.set_nature_du_graphe(entier2);

                        fichier>>entier3;
                        cout<<entier3<<endl;
                        g.set_nombre_arcs(entier3);
                        fichier>>init;
                        cout<<init<<endl;
                        while(init != '$')
                        {
                            a.set_initial(init);
                            fichier>>fin;
                            cout<<fin<<endl;
                            a.set_final(fin);
                            fichier>>weight;
                            cout<<weight<<endl;
                            a.set_poids(weight);
                            arc.push_back(a);

                            for(int it=0;it<g.get_liste_sommets().size();it++)
                            {
                                if (g.get_liste_sommets()[it]==init)
                                {
                                    for(int fn=0;fn<g.get_liste_sommets().size();fn++)
                                    {
                                        if(g.get_liste_sommets()[fn]==fin)
                                        {
                                            if(g.get_nature_du_graphe()==1)
                                            {
                                                mat_adj[it][fn]=1;
                                                mat_adj[fn][it]=1;
                                                mat_poids[it][fn]=weight;
                                                mat_poids[fn][it]=weight;
                                            }
                                        else{
                                                mat_adj[it][fn]=1;
                                                mat_poids[it][fn]=weight;
                                            }
                                        }
                                    }

                                }
                
                            }
                            fichier>>init;
                        }
                        g.set_arcs(arc);
                        g.set_matriceadjacence(mat_adj);
                        if(g.get_nature_du_graphe()==1)
                            cout<<" les aretes du graphe sont :"<<endl;
                        else
                            cout<<" les arcs du graphe sont :"<<endl;
                        g.graphe_affiche_arc();
                        cout<<"*******************************"<<endl;
                        cout<<" la matrice d'adjacence du graphe est :"<<endl;
                        g.graphe_affiche_mat();
                        cout<<"*******************************"<<endl;
                        g.connexe();
                        cout<<"*******************************"<<endl;
                        g.oconnexe();
                        cout<<"*******************************"<<endl;
                        g.ComposantesConnexes();
                        if(g.get_nature_du_graphe()==0)
                             {}
                         else
                             g.affiche_comp_con();
                        cout<<"*******************************"<<endl;
                        g.affiche_comp_con();
                        cout<<"*******************************"<<endl;
                        cout<<endl;
                
                        //fichier.close();
                }
                else
                        cerr << "Impossible d'ouvrir le fichier !" << endl;
                        cout<<endl;
            }

                
    }    
  
        return 0;
}








