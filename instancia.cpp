#include "instancia.h"
#include <fstream>
#include "quicksort.h"
#include <iostream>
#include <algorithm>

using namespace std;

Instancia::Instancia()
{
}

Instancia::~Instancia()
{
    list<Atributo*>::iterator it;

    for(it=Lista_Atributos.begin(); it!=Lista_Atributos.end(); it++){
        delete *it;
    }
}


void Instancia::eia2()
{
    ifstream txtFile;
    // Abrindo o arquivo
    txtFile.open("eia2.txt");
    txtFile >> linha >> coluna;

    vector<int> aux;

    aux.resize(linha * coluna);

    cout << "Lendo os dados da base..." << endl;

    for(int i = 0; i < linha;i++)
    {
        for(int j = 0; j < coluna;j++ )
        {
            txtFile >> aux[i * coluna + j];
        }
    }
    cout << "done.." << endl;

    //Criando novos objetos do tipo Atributo
    for(int i = 0; i<coluna; i++)
    {
        Atributo * A = new Atributo();
        Lista_Atributos.push_back(A);
    }

    //cout << aux[0] << "  " << aux[11] << endl;

    list<Atributo*>::iterator it;
    Atributo * B = new Atributo();

    int tam_aux = aux.size();
    int flag = 0;

    //Adiciona cada elemento a lista dos seus respectivos atributos
    while(flag!=tam_aux)
    {
        it = Lista_Atributos.begin();

        for(int i = 0; i<coluna; i++)
        {
            B = *it;
            B->atrib.push_back(aux[flag++]);
            it++;
        }

    }

    cout << "Ordenando os dados de cada atributo.." << endl;

    for(it=Lista_Atributos.begin(); it!=Lista_Atributos.end(); it++)
    {
        B = *it;
        B->atrib.sort();
    }

    cout << "done.." << endl;


    /*

    it = Lista_Atributos.begin();
    B = *it;

    //B->atrib.sort();

    list<int>::iterator it_int = B->atrib.begin();

    for(int i = 0; i<linha; i++)
    {
        cout << *it_int << endl;
        it_int++;
    }
    */

    /*
    for(unsigned int i = 0; i<aux.size(); i++){

        dados_int.push_back(aux[i]);

    }

    */

}



void Instancia::forest()
{
    ifstream txtFile;
    // Abrindo o arquivo
    txtFile.open("Forest.txt");
    txtFile >> linha >> coluna;

    vector<double> aux;

    aux.resize(linha * coluna);

    cout << "Lendo os dados da base..." << endl;

    for(int i = 0; i < linha;i++)
    {
        for(int j = 0; j < coluna;j++ )
        {
            txtFile >> aux[i * coluna + j];
        }
    }

    cout << "done.." << endl;


    //Criando novos objetos do tipo Atributo
    for(int i = 0; i<coluna; i++)
    {
        Atributo * A = new Atributo();
        Lista_Atributos.push_back(A);
    }

    //cout << aux[0] << "  " << aux[11] << endl;

    list<Atributo*>::iterator it;
    Atributo * B = new Atributo();

    int tam_aux = aux.size();
    int flag = 0;


    //Adiciona cada elemento a lista dos seus respectivos atributos
    while(flag!=tam_aux)
    {
        it = Lista_Atributos.begin();

        for(int i = 0; i<coluna; i++)
        {
            B = *it;
            B->atrib_double.push_back(aux[flag++]);
            it++;
        }

    }

    cout << "Ordenando os dados de cada atributo.." << endl;

    for(it=Lista_Atributos.begin(); it!=Lista_Atributos.end(); it++)
    {
        B = *it;
        B->atrib_double.sort();
    }

    cout << "done.." << endl;

}



