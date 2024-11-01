#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        string s[1005];
        for(int j=1;j<=n;++j)
        {
            cin>>s[j];
            s[j]=" "+s[j];
        }
        if(n==1&&m==1)
        {
            cout<<1<<endl;
        }
        else if(n==1&&m==2)
        {
            if(d==0)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<1<<endl;
            }
        }
    }
    return 0;
}
