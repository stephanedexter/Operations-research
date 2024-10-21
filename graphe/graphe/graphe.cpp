#include "graphe.h"
#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
using namespace std;



string liste_sommet="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

Graphe::Graphe()
{
    /*cout<< "Entrez le nombre de sommets de votre graphe: valeur comprise entre 0 et 52"<<endl;
    do
    {
        cin>>nombre_sommets;
    } while(nombre_sommets<0 || nombre_sommets>52);
     
    mat g;
    for(int i=0;i<nombre_sommets;i++){
        for(int j=0;j<nombre_sommets;j++){
            matriceadjacence[i][j]=0;
        }
    }*/
    nombre_sommets=0;
    nombre_arcs=0;
   
    
}

Graphe::Graphe(int nat, int ns, int na, vector<char> list, vector<Arc_arete> arc, mat madj)
{

    nature_du_graphe=nat;
    nombre_sommets=ns;
    nombre_arcs=na;
    liste_sommets=list;
    arcs=arc;
    
}

int Graphe::get_nature_du_graphe()
{

    return nature_du_graphe;
}

void Graphe::set_nature_du_graphe(int nat)
{

    nature_du_graphe=nat;
}

int Graphe::get_nombre_sommets()
{

    return nombre_sommets;
}

void Graphe::set_nombre_sommets(int ns)
{

    nombre_sommets=ns;
}

int Graphe::get_nombre_arcs()
{

    return nombre_arcs;
}

void Graphe::set_nombre_arcs(int na)
{

    nombre_arcs=na;
}
    
vector<char> Graphe::get_liste_sommets()
{

    return liste_sommets;
}

void Graphe::set_liste_sommets( vector<char> ls)
{

    liste_sommets=ls;
}
    
vector<Arc_arete> Graphe::get_arcs()
{

    return arcs;
}
void Graphe::set_arcs(vector<Arc_arete> arc)
{

    arcs=arc;
}

void Graphe::set_matriceadjacence(mat tab)

{
    for(int i=0;i<nombre_sommets;i++)
    {
        for(int j=0;j<nombre_sommets;j++)
        {
            matriceadjacence[i][j]=tab[i][j];
        }

    } 
}

void Graphe::graphe_affiche_mat()
{

    for(int i=0;i<nombre_sommets;i++)
    {
        for(int j=0;j<nombre_sommets;j++){
            cout<<"  "<<matriceadjacence[i][j];
        }
        cout<<endl;

    } 
}

void Graphe::graphe_affiche_som()
{
    
    //cout<<" les sommets du graphe sont :"<< endl;
    for(auto it:liste_sommets){
        cout<<it<<" , ";
    }
    cout<<endl;

    
}

void Graphe::graphe_affiche_arc()
{
    
    //cout<<" les arcs du graphe sont :"<< endl;
    int i=1;
    if(nature_du_graphe==1)
    {
        for(auto it:arcs)
        {
            cout<<"arete numero "<< i <<endl;
            it.arc_affiche();
            i++;
        }
    }
     if(nature_du_graphe==0)
    {
        for(auto it:arcs)
        {
            cout<<"arc numero "<< i <<endl;
            it.arc_affiche();
            i++;
        }
    }
    
    cout<<endl;
}


void Graphe::initialiser()
{

    
    for(int i=0;i<nombre_sommets;i++){
        for(int j=0;j<nombre_sommets;j++){
            matriceadjacence[i][j]=0;
        }
    }
}

void Graphe::build_arete()
{
    cout<<"Entrez la nature de votre graphe: 0 s'il est oriente et 1 sinon"<<endl;
    do{
        cin>>nature_du_graphe;
    }while((nature_du_graphe!=0)and(nature_du_graphe!=1));

    cout<<"Entrez le nombre d'arc du graphe"<<endl;

    do{
        cin>>nombre_arcs;
    }while((0>nombre_arcs)||(nombre_arcs>100));
    cout<<"Entrez le sommet initiale,(touche entree), le sommet final, (touche entree), le poids de l'arc, (touche entree),"<<endl;
    char in,fn;
    float w;
    for (int i=0;i<nombre_arcs;i++){
        do
        {
            cin>>in>>fn>>w;
        } while ((std::find(liste_sommets.begin(), liste_sommets.end(), in) == liste_sommets.end())||(std::find(liste_sommets.begin(), liste_sommets.end(), fn) == liste_sommets.end()) );

        Arc_arete a(in,fn,w);
        arcs.push_back(a);
        for(int init=0;init<liste_sommets.size();init++){
            if (liste_sommets[init]==in){
                for(int fin=0;fin<liste_sommets.size();fin++){
                    if(liste_sommets[fin]==fn){
                        if(nature_du_graphe==1){
                            matriceadjacence[init][fin]=1;
                            matriceadjacence[fin][init]=1;
                        }
                        else{
                            matriceadjacence[init][fin]=1;
                        }
                    }
                }

                }
        
        }
    }
    

}

void Graphe::ajout_sommet(char s)
{

    vector<char>::iterator it;
    it = find (liste_sommets.begin(),liste_sommets.end(),s);
    if (it !=liste_sommets.end()){}
    else
    liste_sommets.push_back(s);
    nombre_sommets++;    

}

void Graphe::ajout_arete(char ini,char fn, float w)
{
    Arc_arete arr(ini,fn,w);
    int retour;
    vector<char>::iterator ch1,ch2;
    for(int eg=0;eg<arcs.size();eg++)
    {
        if (arr==arcs[eg])
        {
            retour=1;
            break;
        }
            
        else
            retour=0;
    }
    if (retour==1){cout<<"cet arete exixte deja"<<endl;}
    else
    {
       for(int init=0;init<liste_sommets.size();init++){
            if (liste_sommets[init]==ini){
                for(int fin=0;fin<liste_sommets.size();fin++){
                    if(liste_sommets[fin]==fn){
                        if(nature_du_graphe==1){
                            arcs.push_back(arr);
                            matriceadjacence[init][fin]=1;
                            matriceadjacence[fin][init]=1;
                        }
                        else{
                            arcs.push_back(arr);
                            matriceadjacence[init][fin]=1;
                        }
                    }
                }

                }
        
        }
       
    }   

}

void Graphe::sommet()
{
    
    char s;
    cout<<"Entrez les sommets du graphe sous forme de caractere alphabetique (majuscule ou minuscule)"<<endl;
    cout<<" par orde de position : du premier sommet au dernier sommet"<<endl;
    for(int i=0;i<nombre_sommets;i++){
        do 
        {
            cin>>s;
        }
        while(liste_sommet.find(s) == std::string::npos);
        liste_sommets.push_back(s);

    }
}

vector<char> Graphe::liste_adjacence(char som)
{   
    vector<char> liste;
    for(int i=0;i<nombre_sommets;i++)
    {
             if(liste_sommets[i]==som)
             {
                for(int j=0;j<nombre_sommets;j++)
                {
                    if(matriceadjacence[i][j]==1)
                    {
                        liste.push_back(liste_sommets[j]);
                    }
                }
             }
    }
    return liste;         
}

vector<char> Graphe::liste_predecesseur(char som)
{   
    vector<char> liste;
    for(int i=0;i<nombre_sommets;i++)
    {
             if(liste_sommets[i]==som)
             {
                for(int j=0;j<nombre_sommets;j++)
                {
                    if(matriceadjacence[j][i]==1)
                    {
                        liste.push_back(liste_sommets[j]);
                    }
                }
             }
    }
    return liste;         
}




void Graphe::adjacence()
{

    if(nature_du_graphe==1)
    {
        for(int i=0;i<nombre_sommets;i++)
        {
             cout<<"les sommets adjacents au sommet "<< liste_sommets[i]<< " sont : "<< endl;
             for(int j=0;j<liste_adjacence(liste_sommets[i]).size();j++){
                
                     cout<<" "<< liste_adjacence(liste_sommets[i])[j];

                }
            cout<<endl;
            cout<<"**********************************";
            cout<<endl;
        }
    }
    else
    {

            for(int i=0;i<nombre_sommets;i++)
            {
                cout<<"les successeurs du sommet "<< liste_sommets[i]<< " sont : "<< endl;

                    for(int j=0;j<liste_adjacence(liste_sommets[i]).size();j++)
                    {
                    
                        cout<<" "<< liste_adjacence(liste_sommets[i])[j];

                    }
                cout<<endl;
                cout<<"**********************************";
                cout<<endl;
            }

            for(int i=0;i<nombre_sommets;i++)
            {
                cout<<"les predecesseurs du sommet "<< liste_sommets[i]<< " sont : "<< endl;

                    for(int j=0;j<liste_predecesseur(liste_sommets[i]).size();j++)
                    {
                    
                        cout<<" "<< liste_predecesseur(liste_sommets[i])[j];

                    }
            cout<<endl;
            cout<<"**********************************";
            cout<<endl;
            }     

    }


    

} 

void Graphe::connexe()
{   int valeur ;
    vector<char> liste,liste1;
    vector<char>::iterator it,it1;
    if(nature_du_graphe==1)
    {
        
        for(int i=0;i<nombre_sommets;i++)
        {    
            if (liste_adjacence(liste_sommets[i]).size()==0)
            {   valeur=0;
                //return valeur;
                break;
            }
                
            else
            {
                for(int parc=0;parc<liste_adjacence(liste_sommets[i]).size();parc++)
                {
                    it=find(liste.begin(),liste.end(),liste_adjacence(liste_sommets[i])[parc]);
                    if(it!=liste.end()){}
                    else
                        {   if(liste.size()==0)
                                {
                                    liste.push_back(liste_sommets[i]);
                                    liste.push_back(liste_adjacence(liste_sommets[i])[parc]);
                                }
                            else
                            {
                                for(int parc1=0;parc1<liste.size();parc1++)
                                {
                                    it1=find(liste_adjacence(liste[parc1]).begin(),liste_adjacence(liste[parc1]).end(),liste_adjacence(liste_sommets[i])[parc]);
                                    if(it1!=liste_adjacence(liste[parc1]).end())
                                    {
                                        liste.push_back(liste_adjacence(liste_sommets[i])[parc]);
        
                                        break;
                    
                                    }

                                }
                            }

                                  
                        }
                }
            }
            
        }
        if(liste.size()==liste_sommets.size())
            {   cout<<"ce graphe est connexe"<<endl;
                valeur=1;
                //return valeur;
            }
        else
            {
                cout<<"ce graphe n'est pas connexe"<<endl;
                valeur=0;
                //return valeur;
            }

    }
    //return valeur;
}

void Graphe::oconnexe()
{
     bool valeur ;
    vector<char> liste,liste1;
    vector<char>::iterator it,it1;
    if(nature_du_graphe==0)
    {
        
        for(int i=0;i<nombre_sommets;i++)
        {    
            if (liste_adjacence(liste_sommets[i]).size()==0)
            {   
                valeur=0;
                //return valeur;
                break;
            }
                
            else
            {
                for(int parc=0;parc<liste_adjacence(liste_sommets[i]).size();parc++)
                {
                    it=find(liste.begin(),liste.end(),liste_adjacence(liste_sommets[i])[parc]);
                    if(it!=liste.end()){}
                    else
                        {   if(liste.size()==0)
                                {
                                   liste.push_back(liste_sommets[i]);
                                   liste.push_back(liste_adjacence(liste_sommets[i])[parc]);
                                }
                            else
                            {
                                for(int parc1=0;parc1<liste.size();parc1++)
                                {
                                    it1=find(liste_adjacence(liste[parc1]).begin(),liste_adjacence(liste[parc1]).end(),liste_adjacence(liste_sommets[i])[parc]);
                                    if(it1!=liste_adjacence(liste[parc1]).end())
                                    {
                                        liste.push_back(liste_adjacence(liste_sommets[i])[parc]);
                                        break;
                    
                                    }

                                }
                            }

                                  
                        }
                }
            }
            
        }
        if(liste.size()==liste_sommets.size())
        {
            for(int i=0;i<nombre_sommets;i++)
            {    
                if (liste_predecesseur(liste_sommets[i]).size()==0)
                {   
                    valeur=0;
                    //return valeur;
                    break;
                }
                    
                else
                {
                    for(int parc=0;parc<liste_predecesseur(liste_sommets[i]).size();parc++)
                    {
                        it=find(liste1.begin(),liste1.end(),liste_predecesseur(liste_sommets[i])[parc]);
                        if(it!=liste1.end()){}
                        else
                            {   if(liste1.size()==0)
                                    {
                                        liste1.push_back(liste_sommets[i]);
                                        liste1.push_back(liste_predecesseur(liste_sommets[i])[parc]);
                                    }
                                else
                                {
                                    for(int parc1=0;parc1<liste1.size();parc1++)
                                    {
                                        it1=find(liste_predecesseur(liste1[parc1]).begin(),liste_predecesseur(liste1[parc1]).end(),liste_predecesseur(liste_sommets[i])[parc]);
                                        if(it1!=liste_predecesseur(liste1[parc1]).end())
                                        {
                                            liste1.push_back(liste_predecesseur(liste_sommets[i])[parc]);
                                            break;
                        
                                        }

                                    }
                                }

                                    
                            }
                    }
                }
                
            }
            if(liste1.size()==liste_sommets.size())
                {
                    cout<<"ce graphe est fortement connexe"<<endl;
                    valeur=1;
                    //return valeur;
                }
            else
                {
                    cout<<"ce graphe n'est pas fortement connexe"<<endl;
                    valeur=0;
                    //return valeur;
                }
        }
            
        else
            {
                cout<<"ce graphe n'est pas fortement connexe"<<endl;
                valeur=0;
                //return valeur;
            }

    } 
 //return valeur;   
}
   


vector<vector<int> > Graphe::ComposantesConnexes()
{
    int V = liste_sommets.size();
    vector<bool> visité(V, false);
    vector<vector<int> > vect;
 
    int composantesConnexes = 0;
 
    for (int v = 0; v < V; v++) {
        if (visité[v] == false) {
            // Une nouvelle composante connexe a été trouvée, augmenter le compteur de composantes connexes
            composantesConnexes++;
            // Faire une parcours en largeur à partir de v pour marquer tous les sommets atteignables à partir de v comme visités.
            queue<int> q;
            vector<int>p;
            q.push(v);
            visité[v] = true;
            while (q.size()!=0) 
            {   
                p.push_back(q.front());
                int sommetCourant = q.front();
                q.pop();

                // Marquer tous les sommets adjacents à sommetCourant comme visités et les ajouter à la file d'attente.
                for (int i=0;i <liste_sommets.size();i++) 
                {
                    if ((visité[i]==false)and(matriceadjacence[sommetCourant][i]==1))
                    {
                        visité[i]=true;
                        q.push(i);
                        visité[i] = true;
                    }
                }
            }
            vect.push_back(p);
            /*for (int i=0 ; p.size() ; i++)
                { 
                    cout << p.front() << " " <<endl; p.pop() ;
                }
            cout <<"**************"<<endl;*/
        }  
    }
    return vect;
}

void Graphe::affiche_comp_con()
{
    vector<vector<int> >vect;
    vect=ComposantesConnexes();
    int compteur=0;
    for(int i=0;i<vect.size();i++)
    {
        compteur++;
        cout<<"la composante connexe numero "<<compteur<<" est :"<<endl;
        for(int j=0;j<vect[i].size();j++)
        {
             cout<<" "<<liste_sommets[vect[i][j]];

        }            
                cout<<endl;
                cout<<"**********************************";
                cout<<endl;
    }


}

