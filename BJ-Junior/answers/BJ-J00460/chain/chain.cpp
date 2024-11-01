#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
    int o,p;
    x+=o;
    x-=p;
    x*2;
    x-10000;
    return x;
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    int n,b,c;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>b;
        for(int j=0;j<n;j++)
        {
            cin>>b;
            for(int k=0;k<b;k++)
            {
                cin>>c;
            }
        }
        int s;
        if(f(s))
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
