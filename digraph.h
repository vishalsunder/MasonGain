#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include "polynomial.h"
#include "folynomial.h"
#include "transferfunction.h"
using namespace std;
/*struct node
{
    int nodeno;
    vector<int> neighbour;
};*/
struct sparse
{
    int from;
    int to;
    transferfunction weight;
};
struct Gp
{
    transferfunction gain;
    vector<int> pth;
};
class digraph
{
   private:
       vector< vector<int> > D;
       vector<sparse> W;
       vector<Gp> paths;
       vector<Gp> loops;
       transferfunction delta;

   public:
    void declare(void);
    void Paths(int,int);
    void getpath(void);
    void DFS(int);
    void Paths2(int,int);
    void getloops(void);
    bool disjoint(vector<int>, vector<int>);
    void del(int,vector<Gp>);
    void getdelta(void);
    void gettf(void);
    vector< vector<int> > update_D(vector<int>);
    vector<sparse> update_W(vector<int>);
    bool isperm(vector<int>, vector<int>);
};

#endif // DIGRAPH_H
