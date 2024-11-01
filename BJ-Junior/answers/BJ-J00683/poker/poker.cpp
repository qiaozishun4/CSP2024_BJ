#include <iostream>
using namespace std;
char p[3];
int an,n,x,y;
int is[5][15];
int f()
{
    int x;
    if(p[0]=='D')
        {
            x=1;
        }
        else if(p[0]=='c')
        {
            x=2;
        }
        else if(p[0]=='H')
        {
            x=3;
        }
        else
        {
            x=4;
        }

    return x;
}
int g()
{
    int y;
    if(p[1]=='A')
    {
        y=1;
    }
    else if(p[1]=='T')
    {
        y=10;
    }
    else if(p[1]=='J')
    {
        y=11;
    }
    else if(p[1]=='Q')
    {
        y=12;
    }
    else if(p[1]=='K')
    {
        y=13;
    }
    else
    {
        y=p[1]-'0';
    }
    return y;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int a;
    a=52;
    cin>>n;
    if(n==52)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[0]>>p[1];
        x=f();
        y=g();
        if(is[x][y]==0)
        {
            is[x][y]=1;
            an++;
        }
    }
    a=a-an;
    cout<<a<< endl;
    return 0;
}