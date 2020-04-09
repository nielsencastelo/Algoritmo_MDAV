#include "quicksort.h"
#include <iostream>

Quicksort::Quicksort()
{
}

void Quicksort::swap(vector<double> &a, int i, int j)
{
    double tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int Quicksort::partition(vector<double> &a, int l, int r)
{
    double pivo;
    int top;

    pivo = a[l];
    top  = l;

    for(int i = l+1; i<=r; i++){
        if(a[i]<pivo){
            swap(a,i,top);
            swap(a,i,(top+1));
            top++;
        }
    }

    a[top] = pivo;
    return top;
}

void Quicksort::quickrec(vector<double> &a, int l, int r)
{

    if (l < r) {
        int meio = partition(a, l, r);
        quickrec(a, l, meio-1);
        quickrec(a, meio+1, r);
    }
}

vector<double> Quicksort::quicksort(vector<double> &a)
{
    quickrec(a, 0, a.size() - 1);

    cout << "saiu" << endl;

    return a;
}


void Quicksort::swap_int(vector<int> &a, int i, int j)
{
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int Quicksort::partition_int(vector<int> &a, int l, int r)
{
    int pivo, top;

    pivo = a[l];
    top  = l;

    for(int i = l+1; i<=r; i++){
        if(a[i]<pivo){
            swap_int(a,i,top);
            swap_int(a,i,(top+1));
            top++;
        }
    }

    a[top] = pivo;
    return top;
}

void Quicksort::quickrec_int(vector<int> &a, int l, int r)
{
    if (l < r) {
        int meio = partition_int(a, l, r);
        quickrec_int(a, l, meio-1);
        quickrec_int(a, meio+1, r);
    }
}

vector<int> Quicksort::quicksort_int(vector<int> &a)
{
    quickrec_int(a, 0, a.size() - 1);

    return a;
}
