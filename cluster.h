#ifndef CLUSTER_H
#define CLUSTER_H
#include <list>
#include <vector>

using namespace std;

class Cluster
{
public:
    Cluster();

    int classe;
    vector<int> cl;
    vector<double> cl_double;
    int centroide;

};

#endif // CLUSTER_H
