#ifndef MDAV_H
#define MDAV_H
#include "instancia.h"
#include "cluster.h"

class Mdav : public virtual Instancia
{
protected:
    int g;

public:
    Mdav();

    Mdav(const int _g, const int tipo);

    int centroide_inicial;
    int dados_soma;
    int classe_cl;

    void centroide_global(list<int> dados);
    void xr_xs_distance(list<int> &dados, int tipo);
    int centroide(list<int> dados);

    void centroide_xr_xs(Cluster& XR, Cluster& XS);
    void centroide_xr(Cluster& XR);

    /*
        Função add_cluster:
            Se tipo = 0 -> xr = elemento front da lista; xs = elemento back da lista.
            Se tipo = 1 -> xr = elemento back da lista; xs = elemento front da lista.
    */

    void add_cluster(list<int> &dados, int tipo);

    list<Cluster> Lista_Clusters;

    void run();

};

#endif // MDAV_H
