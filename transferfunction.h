#ifndef TRANSFERFUNCTION_H
#define TRANSFERFUNCTION_H
#include <iostream>
#include <list>
#include <cmath>
#include "polynomial.h"
#include "folynomial.h"
using namespace std;
class transferfunction
{
private:
    folynomial N;
    folynomial D;
public:
    void declare(void);
    void display(void);
    void add(transferfunction,transferfunction);
    void sub(transferfunction,transferfunction);
    void mult(transferfunction,transferfunction);
    void div(transferfunction,transferfunction);
    void inmult(transferfunction);
    void inadd(transferfunction);
    void insub(transferfunction);
    void equalto(transferfunction);
    void cleanup(void);
    void unit(void);
};

#endif // TRANSFERFUNCTION_H
