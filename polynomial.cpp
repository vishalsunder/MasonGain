#include "polynomial.h"
#include <iostream>
#include <list>
#include <cmath>
//#include "transferfunction.h"
using namespace std;

void polynomial:: declare()
{
   float c,e;
   poly f;
   int n;
   cout << "enter no. of terms in the polynomial" << endl;
   cin >> n;
   cout << "enter successive coefficients and exponents" << endl;
   for(int i=0; i<n; i++)
    {

            cin >> c;
            cin >> e;
            f.coeff = c;
            f.exp = e;
            P.push_back(f);

    }
}
void polynomial:: display()
{
    if(P.empty())
    {
        cout << "no polynomial entered." << endl;
        return;
    }
    list<poly>::iterator i;
    for(i=P.begin(); i!=P.end(); i++)
   {
       if(i->exp == 0)
       {
           if(i == P.begin())
           {
               //if(i->coeff < 0)
                cout <<  i->coeff;
           }
           else
           {
               if(i->coeff < 0)
                cout <<  i->coeff;
               else
                cout << "+" << i->coeff;
           }
       }
       else if(i->exp == 1)
       {
           if(i->coeff != 1)
           {
           if(i == P.begin())
           {

           if(i->coeff!=-1)
            cout << i->coeff << "s";
            else
                cout << "-s";
           }
           else
           {
               if(i->coeff > 0)
                cout << "+" << i->coeff << "s";
               else if(i->coeff != -1)
                cout << i->coeff << "s";
                else
                    cout << "-s";
           }
       }
       else
       {
           if(i == P.begin())
            cout << "s";
           else
           {
               if(i->coeff > 0)
                cout << "+" << "s";
               else
                cout << "s";
           }
       }
       }
       else
       {
           if(i->coeff != 1)
           {
           if(i == P.begin())
           {
               if(i->coeff!=-1)
                cout << i->coeff << "s^" << i->exp;
                else
                    cout << "-s^" << i->exp;
           }
           else
           {
               if(i->coeff < 0)
               {

               if(i->coeff != -1)
                cout << i->coeff << "s^" << i->exp;
                else
                    cout << "-s^" << i->exp;
               }
               else
                cout << "+" << i->coeff << "s^" << i->exp;
           }
       }
       else
       {
           if(i == P.begin())
           {
                cout << "s^" << i->exp;
           }
           else
           {
               if(i->coeff < 0)
                cout << "s^" << i->exp;
               else
                cout << "+" << "s^" << i->exp;
           }
       }
   }

}
//cout << endl;
}
void polynomial:: add(polynomial p1, polynomial p2)
{
    if((p1.P).empty() && (p2.P).empty())
    {
        cout << "both polynomials empty" << endl;
        return;
    }
    else if((p1.P).empty())
    {
        P.assign((p2.P).begin(),(p2.P).end());
        return;
    }
    else if((p2.P).empty())
    {
        P.assign((p1.P).begin(),(p1.P).end());
        return;
    }
    list<poly>:: iterator i = (p1.P).begin();
    list<poly>:: iterator j = (p2.P).begin();
    while(i!=(p1.P).end() && j!=(p2.P).end())
    {
        if(i->exp > j->exp)
        {
            P.push_back((*i));
            ++i;
        }
        else if(j->exp > i->exp)
        {
            P.push_back((*j));
            ++j;
        }
        else
        {
            poly f;
            f.coeff = i->coeff + j->coeff;
            f.exp = i->exp;
            P.push_back(f);
            ++i;
            ++j;
        }
    }
    if(i!=(p1.P).end())
    {
        P.insert(P.end(),i,(p1.P).end());
    }
    else if(j!=(p2.P).end())
    {
      P.insert(P.end(),j,(p2.P).end());
    }
}
void polynomial:: sub(polynomial p1, polynomial p2)
{
    for(list<poly>:: iterator i=(p2.P).begin(); i!=(p2.P).end(); ++i)
    {
        i->coeff = (-1)*(i->coeff);
    }
    polynomial p3;
    p3.add(p1,p2);
    list<poly>:: iterator j=(p3.P).begin();
    int flag;
    while(j!=(p3.P).end())
    {
        flag = 0;
        if(j->coeff == 0)
        {
            j = (p3.P).erase(j);
            flag = 1;
        }
        if(flag!=1)
            j++;
    }
    P.assign((p3.P).begin(),(p3.P).end());
}
void polynomial:: mult(polynomial p1, polynomial p2)
{
    for(list<poly>:: iterator i=(p1.P).begin(); i!=(p1.P).end(); ++i)
    {
        for(list<poly>:: iterator j=(p2.P).begin(); j!=(p2.P).end(); ++j)
        {
            poly f;
            f.coeff = (i->coeff)*(j->coeff);
            f.exp = (i->exp) + (j->exp);
            int flag = 0;
            for(list<poly>:: iterator k=P.begin(); k!=P.end(); ++k)
            {
                if(k->exp == f.exp)
                {
                    k->coeff += f.coeff;
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
                P.push_back(f);
            }
    }
    list<poly>:: iterator k=P.begin();
            while(k!=P.end())
            {
                if(k->coeff == 0)
                    k = P.erase(k);
                else
                    ++k;
            }
}
int polynomial:: siz()
{
    return (P.size());
}
bool polynomial:: isequal(polynomial p2)
{
   list<poly>:: iterator i = P.begin();
   list<poly>:: iterator j = (p2.P).begin();
   int flag = 0;
   while(i!=P.end() || j!=(p2.P).end())
   {
       if(((i)->coeff) != ((j)->coeff) || ((i)->exp) != ((j)->exp))
       {
           flag = 1;
           break;
       }
       i++;
       j++;
   }
   if(i!=P.end() || j!=(p2.P).end())
    return false;
   else if(flag == 1)
    return false;
   else
    return true;
}
void polynomial:: equalto(polynomial p)
{
    for(list<poly>:: iterator i = (p.P).begin(); i!=(p.P).end(); i++)
        P.push_back((*i));
}
void polynomial:: inmult(polynomial p)
{
    polynomial p1,p2;
    (p2.P).assign(P.begin(),P.end());
    p1.mult(p2,p);
    P.assign((p1.P).begin(),(p1.P).end());
}
void polynomial:: unit()
{
    poly p;
    p.coeff = 1;
    p.exp = 0;
    P.push_back(p);
}
bool polynomial:: isconst()
{
    if(P.size() == 1)
    {
        if((P.begin())->exp == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}
bool polynomial:: isunit()
{
    if(P.size() == 1)
    {
        if((P.begin())->exp == 0 && (P.begin())->coeff == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}
float polynomial:: value()
{
    return ((P.begin())->coeff);
}
void polynomial:: assignconst(float n)
{
    P.clear();
    poly p;
    p.coeff = n;
    p.exp = 0;
    P.push_back(p);
}
/*bool polynomial:: one()
{
    list<poly>:: iterator k = P.begin();
    if(k->coeff == 1 && k->exp == 0)
        return true;
    else
        return false;
}*/

