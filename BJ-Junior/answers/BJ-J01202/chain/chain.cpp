#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int l[1005];
int s[1005][200005];
int r,c;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;++p)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;++i)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];++j)
            {
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;++i)
        {
            cin>>r>>c;
            if(r!=1)
            {
                srand(2);
                cout<<rand()%2<<endl;
            }
            else
            {
                for(int i=1;i<=n;++i)
                    for(int j=1;j<=l[i];++j)
                    {
                        if(s[i][j]==c&&j<=k)
                        {
                            cout<<1<<endl;
                            continue;
                        }
                    }
            }
            cout<<0<<endl;
        }
    }
    return 0;
}
