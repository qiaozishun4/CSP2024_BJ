#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,n,k,q,r,c,i,l,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)cin>>x;
        }
        while(q--)
        {
            bool f;
            cin>>r>>c;
            if(r==c)f=r%2==0;
            else
            {
                if(r%2==0&&c%2==0)f=1;
                else
                {
                    if(r==1)f=(c==2);
                    else if(c==1)f=(r==2);
                    else f=0;
                }
            }
            cout<<f<<endl;
        }
    }
    return 0;
}
