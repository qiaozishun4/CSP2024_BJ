#include <bits/stdc++.h>

using namespace std;
int t,e;
int n;
int q[10]={6,2,5,5,4,5,6,3,7,6};
int a=10e+20;
int dfs(int x,int z,int sfdy)
{
    if(!x)
    {
        if(z<a)
        {
            a=z;
            return 0;
        }
    }
    for(int i=0;i<=9;i++)
    {
        if(sfdy&&i==0)
        {
            continue;
        }
        if(x-q[i]>=0)
        {
            x-=q[i];
            z*=10;
            z=z+i;
            dfs(x,z,0);
            z-=i;
            z=z/10;
            x+=q[i];
        }
    }
    return 0;
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        a=10e+20;
        dfs(n,0,1);
        if(a==10e+20)
        {
            cout<<-1<<endl;
        }
        else{
            cout<<a<<endl;
        }
    }
    return 0;
}
