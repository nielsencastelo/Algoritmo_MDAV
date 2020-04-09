#include "mdav1.h"
#include <list>
#include "cluster.h"
#include <iostream>

using namespace std;

Mdav1::Mdav1()
{
}

Mdav1::Mdav1(const int _g, const int tipo)
{
    g = _g;
    classe_cl = 1;
    if(tipo==0){
        eia2();
    }else if(tipo==1){
        forest();
    }


}

void Mdav1::add_cluster(list<int>& dados, int tipo)
{
    Cluster Novo;
    Cluster Novo_2;

    if(tipo==0){


        for(int i = 0; i<g-1; i++){

            Novo.cl.push_back(dados.front());
            dados.pop_front();
            Novo_2.cl.push_back(dados.back());
            dados.pop_back();


        }

        Novo.classe = classe_cl++;
        Novo_2.classe = classe_cl++;
        centroide_cl(Novo);
        centroide_cl(Novo_2);

        Lista_Clusters.push_back(Novo);

        Lista_Clusters.push_back(Novo_2);


    }else if(tipo==1){

        for(int i = 0; i<dados.size(); i++){
            Novo.cl.push_back(dados.front());
            dados.pop_front();
        }

        Novo.classe = classe_cl++;
        centroide_cl(Novo);

        Lista_Clusters.push_back(Novo);

    }



}

void Mdav1::centroide_cl(Cluster& CL)
{
    int soma = 0;

    for(int i = 0; i<CL.cl.size(); i++){
        soma += CL.cl[i];
    }

    CL.centroide = soma/CL.cl.size();

}

void Mdav1::run()
{

    //cout << dados_int.size() << endl;

    while(dados_int.size() >= (2 * g)){
        add_cluster(dados_int, 0);
    }

    if(dados_int.size() >= g){
        add_cluster(dados_int, 1);
    }

    cout << dados_int.size() << endl;
}
