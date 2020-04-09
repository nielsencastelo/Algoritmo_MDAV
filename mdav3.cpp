#include "mdav3.h"
#include <list>
#include "cluster.h"
#include <iostream>

using namespace std;

Mdav3::Mdav3()
{
}

Mdav3::~Mdav3()
{
    list<Cluster*>::iterator it;
    for(it=Lista_de_Cluster.begin(); it!=Lista_de_Cluster.end(); it++){
        delete *it;
    }
}


Mdav3::Mdav3(const int _g, const int tipo)
{
    g = _g;

    switch(tipo)
    {
        case 0:
            eia2();
            break;
        case 1:
            forest();
            break;
    }

    //Funcao que inicializa os clusters
    Inicializar_Cluster();
}


void Mdav3::Inicializar_Cluster()
{
    //Inicializa cada cluster e seu centroide definindo como 0
    for(int i = 0; i<linha*coluna/g; i++){
        Cluster * Novo = new Cluster();
        Novo->centroide = 0;
        Lista_de_Cluster.push_back(Novo);
    }
    //cout << Lista_de_Cluster.size() << endl;
}

void Mdav3::Add_Cluster()
{

    list<Cluster*>::iterator it_cluster;
    list<Atributo*>::iterator it_atrib;
    list<int>::iterator it_int;

    int cont_g = 0;

    it_cluster = Lista_de_Cluster.begin();
    Cluster * CL = new Cluster();
    CL = *it_cluster;
    Atributo * AT = new Atributo();
    int tam;


    //Adicionando os elementos de cada atributo em clusters e calculando seu centroide.

    for(it_atrib=Lista_Atributos.begin(); it_atrib!=Lista_Atributos.end(); it_atrib++){
        AT = *it_atrib;

        for(it_int=AT->atrib.begin(); it_int!=AT->atrib.end(); it_int++){

            CL->cl.push_back(*it_int);
            CL->centroide += *it_int;
            cont_g++;

            if(cont_g == g){
                //cout << CL->cl.size() << endl;
                //cout << cont_g << endl;
                tam = CL->cl.size();
                CL->centroide /= tam;
                it_cluster++;
                CL = *it_cluster;
                cont_g = 0;
            }
        }

    }




    /*
    Atributo * Test_AT = new Atributo();
    Test_AT = Lista_Atributos.back();



    for(it_int=Test_AT->atrib.begin(); it_int!=Test_AT->atrib.end(); it_int++){
        cout << *it_int << endl;
    }

    */

    /*
    Cluster * Test = new Cluster();

    //Testes de Funcionalidade

    for(it_atrib=Lista_Atributos.begin(); it_atrib!=Lista_Atributos.end(); it_atrib++){
        AT = *it_atrib;
        cout << "Atri " << endl;
        for(it_int=AT->atrib.begin(); it_int!=AT->atrib.end(); it_int++){
            cout << *it_int << " ";


        }
        cout << endl;
    }



    //cout << Lista_de_Cluster.size() << endl;
    //Cluster * Test = new Cluster();

   // cout << Test->cl.size() << endl;

   for(it_cluster=Lista_de_Cluster.begin(); it_cluster!=Lista_de_Cluster.end(); it_cluster++){
        Test = *it_cluster;
        for(int i = 0; i<Test->cl.size(); i++){
            cout << Test->cl[i] << endl;
        }
        cout << "Centroide: " << Test->centroide << endl;
   }





    */

}



void Mdav3::Add_Cluster_Double()
{
    list<Cluster*>::iterator it_cluster;
    list<Atributo*>::iterator it_atrib;
    list<double>::iterator it_double;

    int cont_g = 0;

    it_cluster = Lista_de_Cluster.begin();
    Cluster * CL = new Cluster();
    CL = *it_cluster;
    Atributo * AT = new Atributo();
    int tam;

    //Adicionando os elementos de cada atributo em clusters e calculando seu centroide.
    for(it_atrib=Lista_Atributos.begin(); it_atrib!=Lista_Atributos.end(); it_atrib++){
        AT = *it_atrib;

        for(it_double=AT->atrib_double.begin(); it_double!=AT->atrib_double.end(); it_double++){

            CL->cl_double.push_back(*it_double);
            CL->centroide += *it_double;
            cont_g++;

            if(cont_g == g){
                //cout << CL->cl.size() << endl;
                //cout << cont_g << endl;
                tam = CL->cl_double.size();
                CL->centroide /= tam;
                it_cluster++;
                CL = *it_cluster;
                cont_g = 0;
            }
        }
        if(cont_g!=0){
            tam = CL->cl_double.size();
            CL->centroide /= tam;
            it_cluster++;
            CL = *it_cluster;
            cont_g = 0;
            //cout << "ok" << endl;
        }

    }


    /*
    Cluster * Test = new Cluster();

    Test = Lista_de_Cluster.back();

    for(int i = 0; i<Test->cl_double.size(); i++){
        cout << Test->cl_double[i] << endl;
    }
    cout << Test->centroide << endl;
    */




}




