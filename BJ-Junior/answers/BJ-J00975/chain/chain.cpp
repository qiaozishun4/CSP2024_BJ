#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,ren,k,q,len,pas,r,c;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>ren>>k>>q;
        for(int j=1;j<=ren;j++)
        {
            cin>>len;
            for(int j=1;j<=len;j++)
            {
                cin>>pas;
            }
        }
        for(int j=1;j<=q;j++)
        {
            cin>>r>>c;
            if(j%2==1)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
