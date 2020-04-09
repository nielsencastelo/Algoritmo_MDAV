#ifndef MDAV1_H
#define MDAV1_H
#include "cluster.h"
#include "instancia.h"

class Mdav1 : public virtual Instancia
{
protected:
    int g;

public:
    Mdav1();

    Mdav1(const int _g, const int tipo);

    void inicializar_clusters();

    int classe_cl;

    list<Cluster> Lista_Clusters;

    void add_cluster(list<int>& dados, int tipo);
    void centroide_cl(Cluster& CL);


    void run();

};

#endif // MDAV1_H
