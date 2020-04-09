#ifndef MDAV3_H
#define MDAV3_H
#include "cluster.h"
#include "instancia.h"
#include "atributo.h"

class Mdav3 : public virtual Instancia
{
protected:
    int g;

public:

	Mdav3();
    ~Mdav3();
	Mdav3(const int _g, const int tipo);

    void Inicializar_Cluster();
    void Add_Cluster();
    void Add_Cluster_Double();


    list<Cluster*> Lista_de_Cluster;



};

#endif // MDAV3_H
