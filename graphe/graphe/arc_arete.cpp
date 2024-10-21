#include "arc_arete.h"
#include<iostream>
using namespace std;

    Arc_arete::Arc_arete(){

        initial='i';
        fnal='f';
        poids=0;
    }

    Arc_arete::Arc_arete(char init,char end, float weight){

        initial=init;
        fnal=end;
        poids=weight;
    }

    char Arc_arete::get_initial(){

        return initial;
    }
    void Arc_arete::set_initial(char init){

        initial=init;
    }

    char Arc_arete::get_final(){
        return fnal;
    }

    void Arc_arete::set_final(char end){

        fnal=end;
    }

    float Arc_arete::get_poids(){

        return poids;
    }
    void Arc_arete::set_poids( float weight){

        poids=weight;
    }

    void Arc_arete::arc_affiche(){

        cout<< "Sommet initial : "<< this->initial<<endl;
        cout<< "Sommet final : "<< this->fnal<<endl;
        cout<< "poids de l'arc (arete) : "<<this->poids<<endl;
        cout<<endl;
    }

     bool Arc_arete::operator == (Arc_arete arr){
        if ((arr.initial==this->initial)and(arr.fnal==this->fnal))
            return 1;
        else
            return 0;
     };