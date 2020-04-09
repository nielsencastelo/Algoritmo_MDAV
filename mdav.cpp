#include "mdav.h"
#include <list>
#include <iostream>
#include <cmath>
#include "cluster.h"

using namespace std;

Mdav::Mdav()
{
}
Mdav::Mdav(const int _g, const int tipo)
{
    g = _g;
    classe_cl = 1;
    dados_soma = 0;
    centroide_inicial = 0;

    if(tipo==0){
        eia2();
    }

}

void Mdav::centroide_global(list<int> dados)
{

    list<int>::iterator it;

    for(it=dados.begin(); it!=dados.end(); ++it){

        dados_soma += *it;

    }

    centroide_inicial = dados_soma/dados.size();

    //cout << centroide_inicial << endl;

}

void Mdav::xr_xs_distance(list<int> &dados, int tipo)
{
    //int xr, xs;
    int dist_front, dist_back;
    int ele_front, ele_back;

    ele_front = dados.front();
    ele_back  = dados.back();

    dist_front = sqrt((ele_front - centroide_inicial)*(ele_front - centroide_inicial));
    dist_back  = sqrt((ele_back - centroide_inicial)*(ele_back - centroide_inicial));

    //cout << centroide_inicial << endl;
    if(tipo==0){

        if(dist_front >= dist_back){
            //xr = ele_front;
            //xs = ele_back;
            add_cluster(dados_int,0);
        }else{
            //xr = ele_back;
            //xs = ele_front;
            add_cluster(dados_int,1);
        }

    }else if(tipo==1){

        if(dist_front >= dist_back){
            add_cluster(dados_int, 2);
        }else{
            add_cluster(dados_int, 3);
        }


    }else if(tipo==2){

        if(dist_front >= dist_back){
            add_cluster(dados_int, 4);
        }else{
            add_cluster(dados_int, 5);
        }
    }




}

int Mdav::centroide(list<int> dados)
{
    int soma, ct;
    list<int>::iterator it;

    for(it=dados.begin(); it!=dados.end(); ++it){
        soma += *it;
    }

    ct = soma/dados.size();

    return ct;

}

void Mdav::centroide_xr_xs(Cluster& XR, Cluster& XS)
{
    int ct_xr = 0;
    int ct_xs = 0;

    for(int i = 0; i<XR.cl.size(); i++){
        ct_xr += XR.cl[i];
        ct_xs += XS.cl[i];
    }

    XR.centroide = ct_xr/XR.cl.size();
    XS.centroide = ct_xs/XS.cl.size();


}


void Mdav::centroide_xr(Cluster& XR)
{
    int ct_xr = 0;


    for(int i = 0; i<XR.cl.size(); i++){
        ct_xr += XR.cl[i];
    }

    XR.centroide = ct_xr/XR.cl.size();
}





void Mdav::add_cluster(list<int> &dados, int tipo)
{
    /*
        Função add_cluster:
            Se tipo = 0 -> xr = elemento front da lista; xs = elemento back da lista.
            Se tipo = 1 -> xr = elemento back da lista; xs = elemento front da lista.
            Se tipo = 2 -> Passo if(|x| >= 2*g xr = front.
            Se tipo = 3 -> Passo if(|x| >= 2*g xr = back.
            Se tipo = 4 -> Pontos restantes, xr = front.
            Se tipo = 5 -> Pontos restantes, xr = back.
    */

    Cluster CL_XR;
    Cluster CL_XS;
    int tam = dados.size();

    if(tipo==0){

        CL_XR.cl.push_back(dados.front());
        dados_soma -= dados.front();
        dados.pop_front();


        CL_XS.cl.push_back(dados.back());
        dados_soma -= dados.back();
        dados.pop_back();



        for(int i = 0; i<g; i++){

            CL_XR.cl.push_back(dados.front());
            dados_soma -= dados.front();

            CL_XS.cl.push_back(dados.back());
            dados_soma -= dados.back();

            dados.pop_front();
            dados.pop_back();

        }

        CL_XR.classe = classe_cl++;
        CL_XS.classe = classe_cl++;


        centroide_xr_xs(CL_XR, CL_XS);

        //CL_XR.centroide = centroide(CL_XR.cl);
        //CL_XS.centroide = centroide(CL_XS.cl);

        Lista_Clusters.push_back(CL_XR);
        Lista_Clusters.push_back(CL_XS);

        centroide_inicial = dados_soma/dados.size();

    }else if(tipo==1){

        CL_XR.cl.push_back(dados.back());
        dados_soma -= dados.back();
        dados.pop_back();

        CL_XS.cl.push_back(dados.front());
        dados_soma -= dados.front();
        dados.pop_front();

        for(int i = 0; i<g; i++){

            CL_XR.cl.push_back(dados.back());
            dados_soma -= dados.back();

            CL_XS.cl.push_back(dados.front());
            dados_soma -= dados.front();

            dados.pop_back();
            dados.pop_front();

        }

        CL_XR.classe = classe_cl++;
        CL_XS.classe = classe_cl++;


        //CL_XR.centroide = centroide(CL_XR.cl);
        //CL_XS.centroide = centroide(CL_XS.cl);

        centroide_xr_xs(CL_XR, CL_XS);

        Lista_Clusters.push_back(CL_XR);
        Lista_Clusters.push_back(CL_XS);

        centroide_inicial = dados_soma/dados.size();

    }else if(tipo==2){

        CL_XR.cl.push_back(dados.front());
        dados_soma -= dados.front();
        dados.pop_front();

        for(int i = 0; i<tam; i++){

            CL_XR.cl.push_back(dados.front());
            dados_soma -= dados.front();

            dados.pop_front();
        }

        CL_XR.classe = classe_cl++;

        centroide_xr(CL_XR);

        //CL_XR.centroide = centroide(CL_XR.cl);

        Lista_Clusters.push_back(CL_XR);

    }else if(tipo==3){

        CL_XR.cl.push_back(dados.back());
        dados_soma -= dados.back();
        dados.pop_back();

        for(unsigned int i = 0; i<tam; i++){

            CL_XR.cl.push_back(dados.back());
            dados_soma -= dados.back();
            dados.pop_back();
        }

        CL_XR.classe = classe_cl++;
        //CL_XR.centroide = centroide(CL_XR.cl);

        centroide_xr(CL_XR);

        Lista_Clusters.push_back(CL_XR);

    }else if(tipo==4){



        CL_XR.cl.push_back(dados.front());
        dados_soma -= dados.front();
        dados.pop_front();



        for(unsigned int i = 0; i<=dados.size()+1; i++){

            CL_XR.cl.push_back(dados.front());
            dados_soma -= dados.front();

            dados.pop_front();

        }

        CL_XR.classe = classe_cl++;
        //CL_XR.centroide = centroide(CL_XR.cl);

        centroide_xr(CL_XR);

        Lista_Clusters.push_back(CL_XR);

    }else if(tipo==5){

        CL_XR.cl.push_back(dados.back());
        dados_soma -= dados.back();
        dados.pop_back();

        for(unsigned int i = 0; i<=dados.size(); i++){

            CL_XR.cl.push_back(dados.back());
            dados_soma -= dados.back();
            dados.pop_back();
        }

        CL_XR.classe = classe_cl++;
        //CL_XR.centroide = centroide(CL_XR.cl);

        centroide_xr(CL_XR);

        Lista_Clusters.push_back(CL_XR);

    }

}



void Mdav::run()
{
    centroide_global(dados_int); // calcula centroide global

    while(dados_int.size() >= (2 * g)){

        xr_xs_distance(dados_int, 0);

    }

    if(dados_int.size() >= g ){

        xr_xs_distance(dados_int, 1);
        //cout << "entrei" << endl;

    }

    //xr_xs_distance(dados_int, 2);


    cout << dados_int.size() << endl;




}



