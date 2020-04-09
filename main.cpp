#include <iostream>
#include <ctime>
#include "instancia.h"
#include "mdav.h"
#include "mdav1.h"
#include "mdav2.h"
#include "mdav3.h"

#define g 4
#define database 1

using namespace std;

int main()
{

    Instancia test;
    //Mdav *mdav = new Mdav(g, database);
    //Mdav1 *mdav1 = new Mdav1(g, database);
    //Mdav2 *mdav2 = new Mdav2(g, database);
    Mdav3 *mdav3 = new Mdav3(g, database);
    clock_t t0, tf; // Parametro do cronometro
    double tempo;

    t0 = clock(); // Comeca a contar o tempo

    mdav3 -> Add_Cluster_Double(); // Base Forest
    //mdav3 -> Add_Cluster(); // Base eia2

    tf = clock(); // Finaliza contagem de tempo

    tempo = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
    cout << "Tempo serial: "  << tempo  << " seg. " << endl;


    return 0;
}

