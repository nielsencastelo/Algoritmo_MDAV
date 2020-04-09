#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

using namespace std;

class Quicksort
{
public:
    Quicksort();

    //double
    void swap(vector<double> &a, int i, int j);
    int partition(vector<double> &a, int l, int r);
    void quickrec(vector<double> &a, int l, int r);
    vector<double> quicksort(vector<double> &a);


    //int

    void swap_int(vector<int> &a, int i, int j);
    int partition_int(vector<int> &a, int l, int r);
    void quickrec_int(vector<int> &a, int l, int r);
    vector<int> quicksort_int(vector<int> &a);


};

#endif // QUICKSORT_H
