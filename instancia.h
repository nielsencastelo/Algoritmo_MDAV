#ifndef INSTANCIA_H
#define INSTANCIA_H
#include <list>
#include <vector>
#include "atributo.h"

using namespace std;

class Instancia
{
public:
    Instancia();
    ~Instancia();

    int linha, coluna;
    list<int> dados_int;
    list<double> dados_double;

    void ordenar();
    void ordenar_double();
    void eia2();

    void forest();
    void ord_qsort();

    list<Atributo*> Lista_Atributos;

};

#endif // INSTANCIA_H
