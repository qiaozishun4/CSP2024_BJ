#include<bits/stdc++.h>
using namespace std;
long long n,t,d;
string zz;
string mi(string q,string w)
{
    if(q.size()<w.size())return q;
    if(q.size()>w.size())return w;
    for(int i=0;i<w.size();i++)
    {
        if(q[i]>w[i])return w;
        if(q[i]<w[i])return q;
    }
    return q;
}
int f(int ii,string z,int iii)
{
    if(ii<=0||iii==d)
    {
        if(ii==0)
        {
            if(zz=="-1")zz=z;
            zz=mi(z,zz);
            d=iii;
        }
        return 0;
    }
    f(ii-2,z+'1',iii+1);
    f(ii-3,z+'7',iii+1);
    f(ii-4,z+'4',iii+1);
    f(ii-5,z+'2',iii+1);
    f(ii-6,z+'0',iii+1);
    f(ii-7,z+'8',iii+1);
    return 0;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        d=100001;
        zz="-1";
        cin>>n;
        f(n-2,"1",1);
        f(n-3,"7",1);
        f(n-4,"4",1);
        f(n-5,"2",1);
        f(n-6,"6",1);
        f(n-7,"8",1);
        cout<<zz<<endl;
    }
    return 0;
}
