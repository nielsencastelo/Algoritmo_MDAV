#ifndef MDAV2_H
#define MDAV2_H
#include "cluster.h"
#include "instancia.h"

class Mdav2 : public virtual Instancia
{
protected:
    int g;

public:
    Mdav2();

    Mdav2(const int _g, const int tipo);
    int classe_cl;
    int tam_dados;


    void inicializar_clusters();

    void add_cluster(list<int> &dados, int tipo);

    list<Cluster> Lista_Clusters;
    list<Cluster>::iterator it_front;
    list<Cluster>::iterator it_back;

    void run();


};

#endif // MDAV2_H
