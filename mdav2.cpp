#include "mdav2.h"
#include <list>
#include "cluster.h"
#include <iostream>

using namespace std;

Mdav2::Mdav2()
{
}


Mdav2::Mdav2(const int _g, const int tipo)
{
    g = _g;
    classe_cl = 1;

    if(tipo==0){
        eia2();
    }else if(tipo==1){
        forest();
    }

    tam_dados = dados_int.size();
    inicializar_clusters();
    it_front = Lista_Clusters.begin();
    it_back = --Lista_Clusters.end();
}

void Mdav2::inicializar_clusters()
{
    int flag = 0;

    while(flag!=tam_dados){
        Cluster Novo;
        Novo.centroide = 0;
        Lista_Clusters.push_back(Novo);
        flag++;
    }

}

void Mdav2::add_cluster(list<int>& dados, int tipo)
{
    Cluster A = *it_front;
    Cluster B = *it_back;

    if(tipo==0)
    {
        for(int i = 0; i<g; i++)
        {
            A.cl.push_back(dados.front());
            A.centroide += dados.front();
            dados.pop_front();

            B.cl.push_back(dados.back());
            B.centroide += dados.back();
            dados.pop_back();

        }
        A.classe = classe_cl++;
        B.classe = classe_cl++;

        int tam_A, tam_B;
        tam_A = A.cl.size();
        tam_B = B.cl.size();

        A.centroide /= tam_A;
        B.centroide /= tam_B;

        *it_front = A;
        *it_back = B;

        it_front++;
        it_back--;

        //cout << "aqui" << endl;


    }else if(tipo==1)
    {
        int tam = dados.size();
        for(int i = 0; i<tam; i++)
        {
            //cout << dados.front() << endl;
            A.cl.push_back(dados.front());
            A.centroide += dados.front();
            A.classe = classe_cl++;
            dados.pop_front();
        }

        int tam_A = A.cl.size();

        A.centroide /= tam_A;
        *it_front = A;
    }




}

void Mdav2::run()
{
    //cout << dados_int.size() << endl;
    //cout << Lista_Clusters.size() << endl;

    while(dados_int.size() >= (2*g)){
        add_cluster(dados_int, 0);
    }

    if(dados_int.size() >= g){
        add_cluster(dados_int, 1);
    }



    /*
    Cluster A = Lista_Clusters.front();
    Lista_Clusters.pop_front();

    Cluster B = Lista_Clusters.front();

    for(int i = 0; i< A.cl.size(); i++){
        cout << A.cl[i] << "  ";
    }
    cout << endl;

    for(int i = 0; i< B.cl.size(); i++){
        cout << B.cl[i] << "  ";
    }
    cout << endl;
    */

    /*
    list<Cluster>::iterator it;
    Cluster B;

    it = Lista_Clusters.begin();

    B = *it;

    cout << B.centroide << endl;

    Cluster A = Lista_Clusters.front();
    cout << A.classe << " " << A.centroide << endl;
    for(int i = 0; i< A.cl.size(); i++){
        cout << A.cl[i] << "  ";
    }
    */

}



