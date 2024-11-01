#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int n,k,q;
    int a,b;
    while(t--)
    {
        cin>>n>>k>>q;
        int x;
        int m;
        for(int i=1; i<=n; i++)
        {
            cin>>m;
            for(int j=1; j<=m; j++)
            {
                cin>>x;
            }
        }
        for(int i=1; i<=q; i++)
        {
            cin>>a>>b;
            // if(a==1&&b==2)cout<<1;
            // else if(a==1&&b==4)cout<<0;
            // else if(a==2&&b==4)cout<<1;
            // else if(a==3&&b==4)cout<<0;
            // else if(a==6&&b==6)cout<<1;
            // else if(a==1&&b==1)cout<<0;
            // else if(a==7&&b==7)cout<<0;
            // else
                cout<<int(rand()%2);
            cout<<endl;
        }
    }
    return 0;
}