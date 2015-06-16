#include "folynomial.h"
#include <iostream>
#include <list>
#include <cmath>
#include "polynomial.h"
using namespace std;

void folynomial:: declare()
{
    int m,n;
    cout << "enter number of factors in the polynomial:" << endl;
    cin >> m;
    for(int i=1; i<=m; i++)
    {
        foly f;
        cout << "enter factor no." << i << ":" << endl;
        (f.p).declare();
        cout << "enter power of this factor:" << endl;
        cin >> n;
        f.exp = n;
        F.push_back(f);
    }
}
void folynomial:: display()
{
  if(!isunit())
    sim();
    if(F.empty())
    {
        cout << "no polynomial entered" << endl;
        return;
    }
    list<foly>:: iterator i;
    for(i=F.begin(); i!=F.end(); i++)
    {
        if((i->p).siz() != 1)
        {
            cout << "(";
            (i->p).display();
            if(i->exp == 1)
                cout << ")";
            else
                cout << ")^" << i->exp;
        }
        else
        {
            (i->p).display();
            if(i->exp != 1 && !(i->p).isconst())
                cout << "^" << i->exp;
        }
    }
}
void folynomial:: add(folynomial f1, folynomial f2)
{
   list<foly>:: iterator i = (f1.F).begin();
   list<foly>:: iterator j;
   int flag;
   while(i!=(f1.F).end())
   {
       j = (f2.F).begin();
       flag = 0;
       while(j!=(f2.F).end())
       {
           if((i->p).isequal((j->p)))
           {
               foly f;
               if(i->exp > j->exp)
               {
                   (f.p).equalto((j->p));
                   f.exp = j->exp;
                   F.push_back(f);

                   (i->exp) = (i->exp) - (j->exp);
                   j = (f2.F).erase(j);
                   goto label;
               }
               else if(i->exp < j->exp)
               {
                   (f.p).equalto((j->p));
                   f.exp = i->exp;
                   F.push_back(f);

                   (j->exp) = (j->exp) - (i->exp);
                   flag = 1;
                   i = (f1.F).erase(i);
                   goto label;
               }
               else
               {
                   (f.p).equalto((j->p));
                   f.exp = j->exp;
                   F.push_back(f);
                   i = (f1.F).erase(i);
                   j = (f2.F).erase(j);
                   flag = 1;
                   goto label;
               }
           }
           else
            ++j;
       }
       label:
           if(flag!=1)
           {
               ++i;
           }

   }
   for(i=(f1.F).begin(); i!=(f1.F).end(); i++)
   {
       if((i->p).isconst())
       {
           for(j=(f2.F).begin(); j!=(f2.F).end(); j++)
           {
               if((j->p).isconst())
               {
                   if((i->p).value()<(j->p).value())
                   {
                       (j->p).assignconst(((j->p).value())/((i->p).value()));
                       F.push_front((*i));
                       i = (f1.F).erase(i);
                       break;
                   }
                   else if((i->p).value()>(j->p).value())
                   {
                       (i->p).assignconst(((i->p).value())/((j->p).value()));
                       F.push_front((*j));
                       j = (f2.F).erase(j);
                       break;
                   }
                   else
                   {
                       F.push_front((*i));
                       i = (f1.F).erase(i);
                       j = (f2.F).erase(j);
                   }
               }
           }
       }
   }

   polynomial p1,p2,p3;
   p1 = f1.expand();

   p2 = f2.expand();
   p3.add(p1,p2);
   foly f;
   (f.p).equalto(p3);
   f.exp = 1;
   F.push_back(f);
}
void folynomial:: sub(folynomial f1, folynomial f2)
{
   list<foly>:: iterator i = (f1.F).begin();
   list<foly>:: iterator j;
   int flag;
   while(i!=(f1.F).end())
   {
       j = (f2.F).begin();
       flag = 0;
       while(j!=(f2.F).end())
       {
           if((i->p).isequal((j->p)))
           {
               foly f;
               if(i->exp > j->exp)
               {
                   (f.p).equalto((j->p));
                   f.exp = j->exp;
                   F.push_back(f);

                   (i->exp) = (i->exp) - (j->exp);
                   j = (f2.F).erase(j);
                   goto label;
               }
               else if(i->exp < j->exp)
               {
                   (f.p).equalto((j->p));
                   f.exp = i->exp;
                   F.push_back(f);

                   (j->exp) = (j->exp) - (i->exp);
                   flag = 1;
                   i = (f1.F).erase(i);
                   goto label;
               }
               else
               {
                   (f.p).equalto((j->p));
                   f.exp = j->exp;
                   F.push_back(f);
                   i = (f1.F).erase(i);
                   j = (f2.F).erase(j);
                   flag = 1;
                   goto label;
               }
           }
           else
            ++j;
       }
       label:
           if(flag!=1)
           {
               ++i;
           }

   }
   for(i=(f1.F).begin(); i!=(f1.F).end(); i++)
   {
       if((i->p).isconst())
       {
           for(j=(f2.F).begin(); j!=(f2.F).end(); j++)
           {
               if((j->p).isconst())
               {
                   if((i->p).value()<(j->p).value())
                   {
                       (j->p).assignconst(((j->p).value())/((i->p).value()));
                       F.push_front((*i));
                       i = (f1.F).erase(i);
                       break;
                   }
                   else if((i->p).value()>(j->p).value())
                   {
                       (i->p).assignconst(((i->p).value())/((j->p).value()));
                       F.push_front((*j));
                       j = (f2.F).erase(j);
                       break;
                   }
                   else
                   {
                       F.push_front((*i));
                       i = (f1.F).erase(i);
                       j = (f2.F).erase(j);
                   }
               }
           }
       }
   }

   polynomial p1,p2,p3;
   p1 = f1.expand();

   p2 = f2.expand();
   p3.sub(p1,p2);
   foly f;
   (f.p).equalto(p3);
   f.exp = 1;
   F.push_back(f);
}

polynomial folynomial:: expand()
{
    polynomial q;
    q.unit();
    for(list<foly>:: iterator i = F.begin(); i!=F.end(); ++i)
    {
        for(int j=1; j<=(i->exp); j++)
            q.inmult((i->p));
    }
    return q;
}
void folynomial:: equalto(folynomial f)
{
    F.clear();
    F.assign((f.F).begin(),(f.F).end());
}
void folynomial:: mult(folynomial f1, folynomial f2)
{
    if((f1.F).size()==1 && (f2.F).size()==1){
        if((((f1.F).begin())->p).isunit() && (((f2.F).begin())->p).isunit()){
            foly f;
            (f.p).unit();
            f.exp = 1;
            F.push_back(f);
            return;
        }
    }
    list<foly>:: iterator i = (f1.F).begin();
    list<foly>:: iterator j;
    int flag;
    while(i!=(f1.F).end())
    {
        flag = 0;
        j = (f2.F).begin();
        while(j!=(f2.F).end())
        {
            if((i->p).isequal(j->p))
            {
                foly f;
                (f.p).equalto(i->p);
                f.exp = (i->exp) + (j->exp);
                F.push_back(f);
                i = (f1.F).erase(i);
                j = (f2.F).erase(j);
                flag = 1;
                break;
            }
            else
                ++j;
        }
        if(flag == 0)
            ++i;
    }
    for(i=(f1.F).begin(); i!=(f1.F).end(); ++i)
        F.push_back((*i));
    for(j=(f2.F).begin(); j!=(f2.F).end(); ++j)
        F.push_back((*j));
}
void folynomial:: inmult(folynomial f)
{
    folynomial f1,f2;
    (f2.F).assign(F.begin(),F.end());
    f1.mult(f2,f);
    F.assign((f1.F).begin(),(f1.F).end());
}
void folynomial:: num(folynomial f1,folynomial f2)
{
   list<foly>:: iterator i = (f1.F).begin();
   list<foly>:: iterator j;
   int flag;
   while(i!=(f1.F).end())
   {
       j = (f2.F).begin();
       flag = 0;
       while(j!=(f2.F).end())
       {
           if((i->p).isequal((j->p)))
           {
               if(i->exp > j->exp)
               {
                   (i->exp) = (i->exp) - (j->exp);
                   j = (f2.F).erase(j);
                   goto label;
               }
               else if(i->exp < j->exp)
               {
                   (j->exp) = (j->exp) - (i->exp);
                   flag = 1;
                   i = (f1.F).erase(i);
                   goto label;
               }
               else
               {
                   i = (f1.F).erase(i);
                   j = (f2.F).erase(j);
                   flag = 1;
                   goto label;
               }
           }
           else
            ++j;
       }
       label:
           if(flag!=1)
           {
               ++i;
           }

   }
   for(i=(f1.F).begin(); i!=(f1.F).end(); i++)
   {
       if((i->p).isconst())
       {
           for(j=(f2.F).begin(); j!=(f2.F).end(); j++)
           {
               if((j->p).isconst())
               {
                   if((i->p).value()<(j->p).value())
                   {
                       (j->p).assignconst(((j->p).value())/((i->p).value()));
                       i = (f1.F).erase(i);
                       break;
                   }
                   else if((i->p).value()>(j->p).value())
                   {
                       (i->p).assignconst(((i->p).value())/((j->p).value()));
                       j = (f2.F).erase(j);
                       break;
                   }
                   else
                   {
                       i = (f1.F).erase(i);
                       j = (f2.F).erase(j);
                   }
               }
           }
       }
   }
   if((f1.F).empty())
   {
       foly f;
       (f.p).unit();
       f.exp = 0;
       (f1.F).push_back(f);
   }
   if((f2.F).empty())
   {
       foly f;
       (f.p).unit();
       f.exp = 0;
       (f2.F).push_back(f);
   }

   F.assign((f1.F).begin(),(f1.F).end());
}
void folynomial:: den(folynomial f1, folynomial f2)
{
       list<foly>:: iterator i = (f1.F).begin();
   list<foly>:: iterator j;
   int flag;
   while(i!=(f1.F).end())
   {
       j = (f2.F).begin();
       flag = 0;
       while(j!=(f2.F).end())
       {
           if((i->p).isequal((j->p)))
           {
               if(i->exp > j->exp)
               {
                   (i->exp) = (i->exp) - (j->exp);
                   j = (f2.F).erase(j);
                   goto label;
               }
               else if(i->exp < j->exp)
               {
                   (j->exp) = (j->exp) - (i->exp);
                   flag = 1;
                   i = (f1.F).erase(i);
                   goto label;
               }
               else
               {
                   i = (f1.F).erase(i);
                   j = (f2.F).erase(j);
                   flag = 1;
                   goto label;
               }
           }
           else
            ++j;
       }
       label:
           if(flag!=1)
           {
               ++i;
           }

   }
   for(i=(f1.F).begin(); i!=(f1.F).end(); i++)
   {
       if((i->p).isconst())
       {
           for(j=(f2.F).begin(); j!=(f2.F).end(); j++)
           {
               if((j->p).isconst())
               {
                   if((i->p).value()<(j->p).value())
                   {
                       (j->p).assignconst(((j->p).value())/((i->p).value()));
                       i = (f1.F).erase(i);
                       break;
                   }
                   else if((i->p).value()>(j->p).value())
                   {
                       (i->p).assignconst(((i->p).value())/((j->p).value()));
                       j = (f2.F).erase(j);
                       break;
                   }
                   else
                   {
                       i = (f1.F).erase(i);
                       j = (f2.F).erase(j);
                   }
               }
           }
       }
   }
   if((f1.F).empty())
   {
       foly f;
       (f.p).unit();
       f.exp = 0;
       (f1.F).push_back(f);
   }
   if((f2.F).empty())
   {
       foly f;
       (f.p).unit();
       f.exp = 0;
       (f2.F).push_back(f);
   }

   F.assign((f2.F).begin(),(f2.F).end());
}
void folynomial:: clean()
{
    F.clear();
}
void folynomial:: sim()
{
    int flag = 0;
    polynomial p1,p2;
    p1.unit();
    p2.unit();
    list<foly>:: iterator i = F.begin();
    while(i!=F.end())
    {
        flag = 0;
        if((i->p).isconst())
        {
            p1.inmult(i->p);
            i = F.erase(i);
            flag = 1;
        }
        if(flag != 1)
            ++i;
    }
        if(!p1.isequal(p2))
        {
            foly f;
            (f.p).equalto(p1);
            f.exp = 0;
            F.push_front(f);
        }
        i = F.begin();
        list<foly>:: iterator j;
        while(i!=F.end())
        {
            j = ++i;
            --i;
            while(j!=F.end())
            {
                flag = 0;
                if((i->p).isequal(j->p))
                {
                    (i->exp)++;
                    j = F.erase(j);
                    flag = 1;
                }
                if(flag==0)
                    ++j;
            }
            ++i;
        }
    }
    void folynomial:: unit()
    {
        foly f;
        (f.p).unit();
        f.exp = 1;
        F.push_back(f);
    }
    bool folynomial:: isunit()
    {
        if(F.size()==1)
        {
            if(((F.begin())->p).isunit())
                return true;
        }
        return false;
    }


