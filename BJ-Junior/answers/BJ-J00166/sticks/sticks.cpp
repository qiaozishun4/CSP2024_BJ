#include<bits/stdc++.h>
using namespace std;
int l(int n)
{
    int s=0;
    while(n>0)
    {
        n=n/10;
        s++;
    }
}
int fun(int n)
{
    if(n==1)
        return -1;
    if(n==2)
        return 1;
    if(n==3)
        return 7;
    if(n==4)
        return 4;
    if(n==5)
        return 2;
    if(n==6)
        return 6;
    if(n==7)
        return 8;
    int m=100000000,flag=0,b,i;
    if(fun(n-2)+1*10*l(fun(n-2))<m and fun(n-3)!=-1)
    {
        m=fun(n-2)+1;
        flag=1;
    }
    if(fun(n-3)+7*10*l(fun(n-2))<m and fun(n-3)!=-1)
    {
        m=fun(n-3)+7;
        flag=1;
    }
    if(fun(n-4)+4*10*l(fun(n-2))<m and fun(n-3)!=-1)
    {
        m=fun(n-4)+4;
        flag=1;
    }
    if(fun(n-5)+2*10*l(fun(n-2))<m and fun(n-3)!=-1)
    {
        m=fun(n-5)+2;
        flag=1;
    }
    if(fun(n-6)+0<m and fun(n-3)!=-1)
    {
        m=fun(n-6)+0;
        flag=1;
    }
    if(fun(n-7)+8*10*l(fun(n-2))<m and fun(n-3)!=-1)
    {
        m=fun(n-7)+8;
        flag=1;
    }
    b=m;
    for(i=1;i<l(m);i++)
               b=b/10;
    if(flag==0 or b==m)
        return -1;
    else if(flag)
        return m;
}
int main()
{
    freopen("sticks1.in","r",stdin);
    freopen("sticks1.out","w",stdout);
    int t,n,i,ans[10000];
    cin>>t;
   for(i=1;i<=t;i++)
   {
        cin>>n;
        if(n<2)
            ans[i]=-1;
        ans[i]=fun(n);
   }
   for(i=1;i<=t;i++)
   {
        cout<<ans[i];
   }
    return 0;
}
