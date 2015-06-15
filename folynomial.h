#ifndef FOLYNOMIAL_H
#define FOLYNOMIAL_H
#include <iostream>
#include <list>
#include <cmath>
#include "polynomial.h"
//#include "transferfunction.h"
using namespace std;
struct foly
{
    polynomial p;
    int exp;
};
class folynomial
{
private:
    list<foly> F;
    void sim(void);
public:
    void declare(void);
    void display(void);
    void add(folynomial,folynomial);
    void sub(folynomial,folynomial);
    polynomial expand(void);
    void equalto(folynomial);
    void mult(folynomial,folynomial);
    void inmult(folynomial);
    void num(folynomial,folynomial);
    void den(folynomial,folynomial);
    void clean(void);
    void unit(void);
    bool isunit(void);
};

#endif // FOLYNOMIAL_H
