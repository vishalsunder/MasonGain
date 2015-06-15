#include "transferfunction.h"
#include <iostream>
#include <list>
#include <cmath>
#include "folynomial.h"
#include "polynomial.h"
using namespace std;

void transferfunction:: declare()
{
    cout << "enter numerator:" << endl;
    N.declare();
    cout << "enter denominator:" << endl;
    D.declare();
}
void transferfunction:: display()
{
    N.display();
    cout << "/";
    D.display();
}
void transferfunction:: add(transferfunction t1, transferfunction t2)
{
    folynomial n,n1,n2;
    folynomial d;
    d.mult(t1.D,t2.D);
    //d.display();
    //cout << endl;
    n1.mult(t1.N,t2.D);
    //n1.display();
    //cout << endl;
    n2.mult(t1.D,t2.N);
    //n2.display();
    //cout << endl;
    n.add(n1,n2);
    //n.display();
    N.num(n,d);
    D.den(n,d);
}
void transferfunction:: sub(transferfunction t1, transferfunction t2)
{
    folynomial n,n1,n2;
    folynomial d;
    d.mult(t1.D,t2.D);
    n1.mult(t1.N,t2.D);
    n2.mult(t1.D,t2.N);
    n.sub(n1,n2);
    N.num(n,d);
    D.den(n,d);
}
void transferfunction:: mult(transferfunction t1, transferfunction t2)
{
    folynomial n,d;
    n.mult((t1.N),(t2.N));
    d.mult((t1.D),(t2.D));
    N.num(n,d);
    D.den(n,d);
}
void transferfunction:: div(transferfunction t1, transferfunction t2)
{
    folynomial n,d;
    n.mult((t1.N),(t2.D));
    d.mult((t1.D),(t2.N));
    N.num(n,d);
    D.den(n,d);
}
void transferfunction:: inmult(transferfunction t)
{
    transferfunction t1,t2;
    (t1.N).equalto(N);
    (t1.D).equalto(D);
    t2.mult(t,t1);
    N.equalto(t2.N);
    D.equalto(t2.D);
}
void transferfunction:: inadd(transferfunction t)
{
    transferfunction t1,t2;
    (t1.N).equalto(N);
    (t1.D).equalto(D);
    t2.add(t,t1);
    N.equalto(t2.N);
    D.equalto(t2.D);
}
void transferfunction:: insub(transferfunction t)
{
    transferfunction t1,t2;
    (t1.N).equalto(N);
    (t1.D).equalto(D);
    t2.sub(t1,t);
    N.equalto(t2.N);
    D.equalto(t2.D);
}
void transferfunction:: equalto(transferfunction t)
{
    N.equalto(t.N);
    D.equalto(t.D);
}
void transferfunction:: cleanup()
{
    N.clean();
    D.clean();
}
void transferfunction:: unit()
{
    N.unit();
    D.unit();
}
