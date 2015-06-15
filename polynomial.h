#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <list>
#include <cmath>
//#include "transferfunction.h"
using namespace std;
struct poly
{
    float coeff;
    float exp;
};
class polynomial
{
private:
    list<poly> P;
public:
    void declare(void);
    void display(void);
    void add(polynomial,polynomial);
    void sub(polynomial,polynomial);
    void mult(polynomial,polynomial);
    int siz(void);
    bool isequal(polynomial);
    void equalto(polynomial);
    void inmult(polynomial);
    void unit(void);
    bool isconst();
    bool isunit();
    float value(void);
    void assignconst(float);
        //bool one(void);
};
#endif // POLYNOMIAL_H
