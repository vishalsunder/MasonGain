#include "digraph.h"
#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include "folynomial.h"
#include "polynomial.h"
#include "transferfunction.h"
using namespace std;
//namespace one
//{
    transferfunction p;
    vector<int> x;
    vector<int> visited;
    vector<int> deptm;
    int t=0;
    //vector<int> visited;
//}
void digraph:: declare()
{
    int x,k,m;
    cout << "enter no. of nodes in the graph:" << endl;
    cin >> x;
    for(int i=0; i<x; i++)
    {

        vector<int> I;
        cout << "enter no. of neighbours of node no." << i << endl;
        cin >> k;
        for(int j=1; j<=k; j++)
        {
            cout << "enter neighbour no." << j << endl;
            cin >> m;
            I.push_back(m);
        }
        D.push_back(I);
    }
    int n,f,t;
    transferfunction w;
    cout << "enter no. of edges:" << endl;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        sparse s;
        cout << "enter source node:" << endl;
        cin >> f;
        cout << "enter destination node:" << endl;
        cin >> t;
        cout << "ENTER CORRESPONDING WEIGHT:" << endl;
        (s.weight).declare();
        s.from = f;
        s.to = t;
        W.push_back(s);
    }
}
void digraph:: Paths(int a, int b)
{

    transferfunction q;
    q.equalto(p);
    vector<int> y;
    y.assign(x.begin(),x.end());
    if(a==b)
    {
        Gp temp;
        (temp.gain).equalto(p);
        (temp.pth).assign(x.begin(),x.end());
        paths.push_back(temp);
        return;
    }
    visited[a] = 1;
    for(int i=0; i<D[a].size(); i++)
    {
        if(visited[D[a][i]] == 0)
        {
            for(vector<sparse>:: iterator j=W.begin(); j!=W.end(); j++)
            {
                if((j->from) == a && (j->to) == D[a][i])
                {
                    p.inmult(j->weight);
                    x.push_back(D[a][i]);
                    break;
                }
            }
            Paths(D[a][i],b);
            p.equalto(q);
            x.assign(y.begin(),y.end());
        }
    }
    visited[a] = 0;
}
void digraph:: getpath()
{
    visited.assign(D.size(),0);
    int a,b;
    cout << "from?" << endl;
    cin >> a;
    cout << "to?" << endl;
    cin >> b;
    x.push_back(a);
    Paths(a,b);
    /*for(vector<Gp>:: iterator i=paths.begin(); i!=paths.end(); i++)
    {
        (i->gain).display();
        cout << "    ";
        for(int j=0; j<(i->pth).size(); j++)
        {
            cout << (i->pth)[j];
        }
        cout << endl;
    }*/

}
void digraph:: Paths2(int a, int b)
{

    transferfunction q;
    q.equalto(p);
    vector<int> y;
    y.assign(x.begin(),x.end());
    if(a==b)
    {
        Gp temp;
        (temp.gain).equalto(p);
        (temp.pth).assign(x.begin(),x.end());
        loops.push_back(temp);
        return;
    }
    visited[a] = 1;
    for(int i=0; i<D[a].size(); i++)
    {
        if(visited[D[a][i]] == 0)
        {
            for(vector<sparse>:: iterator j=W.begin(); j!=W.end(); j++)
            {
                if((j->from) == a && (j->to) == D[a][i])
                {
                    p.inmult(j->weight);
                    x.push_back(D[a][i]);
                    break;
                }
            }
            Paths2(D[a][i],b);
            p.equalto(q);
            x.assign(y.begin(),y.end());
        }
    }
    visited[a] = 0;
}
void digraph:: DFS(int a)
{
    t++;
    visited[a] = 1;
    for(int i=0; i<D[a].size(); i++)
    {
        if(visited[D[a][i]] == 0)
            DFS(D[a][i]);
    }
    t++;
    deptm[a] = t;
}

void digraph:: getloops()
{
    visited.clear();
    visited.assign(D.size(),0);
    deptm.assign(D.size(),0);
    for(int i=0; i<D.size(); i++)
    {
        if(visited[i] == 0)
            DFS(i);
    }
    int n=0;
   for(int j=0; j<W.size(); j++)
   {
       if(deptm[W[j].to]>=deptm[W[j].from])
       {
           visited.clear();
           visited.assign(D.size(),0);
           p.cleanup();
           x.clear();
           x.push_back(W[j].to);
           Paths2(W[j].to,W[j].from);
           for(int k=n; k<loops.size(); k++)
           {
               (loops[k].gain).inmult(W[j].weight);
               (loops[k].pth).push_back(W[j].to);
           }
       }
       n=loops.size();
   }
   vector<Gp>:: iterator i=loops.begin();
   vector<Gp>:: iterator j;
   while(i!=loops.end()){
    j=i+1;
    //i--;
    int flag=0;
    while(j!=loops.end()){

        if((i->pth).size()==(j->pth).size()){
            vector<int> a,b;
            a.assign((i->pth).begin(),(i->pth).end()-1);
            b.assign((j->pth).begin(),(j->pth).end()-1);
            if(isperm(a,b)){
                loops.erase(i);
                flag=1;
                break;
            }
    }
    //if(flag!=1)
        j++;
   }
   if(flag!=1)
   i++;
   }
   /*if(!loops.empty())
   {
   for(vector<Gp>:: iterator i=loops.begin(); i!=loops.end(); i++)
    {
        (i->gain).display();
        cout << "    ";
        for(int j=0; j<(i->pth).size(); j++)
        {
            cout << (i->pth)[j];
        }
        cout << endl;
    }
   }
   else
    cout << "no loops" << endl;*/


}
bool digraph:: disjoint(vector<int> L1, vector<int> L2)
{
    for(int i=0; i<L1.size(); i++)
    {
        for(int j=0; j<L2.size(); j++)
        {
            if(L1[i]==L2[j])
                return false;
        }
    }
    return true;
}
void digraph:: del(int v, vector<Gp> loops1)
{
    t=t+1;
    vector<Gp> loops2;
    loops2.assign(loops1.begin(),loops1.end());
    for(int i=v+1; i<loops1.size(); i++)
    {
        if(disjoint(loops1[v].pth, loops1[i].pth))
        {
            if(t%2==0){
                transferfunction r;
                r.mult(loops1[v].gain,loops1[i].gain);
                delta.inadd(r);
            }
            else{
                transferfunction r;
                r.mult(loops1[v].gain,loops1[i].gain);
                delta.insub(r);
            }
            int q=t;
            for(int j=0; j<(loops2[v].pth).size(); j++)
                (loops2[i].pth).push_back((loops2[v].pth)[j]);
            (loops2[i].gain).inmult(loops2[v].gain);
            del(i,loops2);
            t=q;
        }
    }
}
void digraph:: getdelta()
{
    //t=1;
delta.unit();
transferfunction x;
for(int i=0; i<loops.size(); i++)
{
    x.inadd(loops[i].gain);
}
//delta.display();
//cout << endl;
delta.insub(x);
//delta.display();
//cout << endl;
for(int i=0; i<loops.size(); i++){
        t=1;
    del(i,loops);
}
transferfunction y;
y.unit();
delta.inadd(y);
/*cout << "delta is: ";
delta.display();*/
}
vector< vector<int> > digraph:: update_D(vector<int> x)
{
    vector< vector<int> > D_temp;
    D_temp.assign(D.begin(),D.end());
    for(int i=0; i<x.size(); i++)
    {
        D_temp[x[i]].clear();
        for(int j=0; j<D_temp.size(); j++)
        {
            vector<int>:: iterator k=D_temp[j].begin();
            while(k!=D_temp[j].end())
            {
                if(*k==x[i])
                {
                    D_temp[j].erase(k);
                    break;
                }
                k++;
            }
        }
    }
    return D_temp;
}
vector<sparse> digraph:: update_W(vector<int> x)
{
    vector<sparse> W_temp;
    W_temp.assign(W.begin(),W.end());
    for(int i=0; i<x.size(); i++)
    {
        vector<sparse>:: iterator j=W_temp.begin();
        while(j!=W_temp.end())
        {
            int flag=0;
            if(j->from==x[i]||j->to==x[i])
            {
                W_temp.erase(j);
                flag=1;
            }
            if(flag==0)
                ++j;
        }
    }
    return W_temp;
}
void digraph:: gettf()
{
    getpath();
    getloops();
    getdelta();
    transferfunction tf1,tf3,tf4;
    for(int i=0; i<paths.size(); i++)
    {
        digraph d_temp;
        vector< vector<int> > D_temp=update_D(paths[i].pth);
        vector<sparse> W_temp=update_W(paths[i].pth);
        (d_temp.D).assign(D_temp.begin(),D_temp.end());
        (d_temp.W).assign(W_temp.begin(),W_temp.end());
        d_temp.getloops();
        d_temp.getdelta();
        transferfunction tf2;
        tf2.mult(paths[i].gain,d_temp.delta);
        tf1.inadd(tf2);
    }
    tf1.insub(tf4);
    tf3.div(tf1,delta);
    tf3.display();
}
bool digraph:: isperm(vector<int> A, vector<int> B)
{
    vector<int>:: iterator it1=A.begin();
    vector<int>:: iterator it2=B.begin();
    while(it2!=B.end()){
        if(*it1!=*it2)
            it2++;
        else{
            A.erase(it1);
            B.erase(it2);
            it2=B.begin();
        }
    }
    if(A.empty()&&B.empty())
        return true;
    else
        return false;
}
