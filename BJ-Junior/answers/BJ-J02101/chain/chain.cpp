#include<bits/stdc++.h>
using namespace std;
int a[5005][5005],l[5005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    int n,k,q,r,c;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(l,0,sizeof(l));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>a[i][j];
            }
        }
        while(q--)
        {
            cin>>r>>c;
            if(c<2)
            {
                cout<<0;
            }
            else if(r==1)
            {
                bool f=0;
                int cur;
                for(int i=2;i<=l[2];i++)
                {
                    if(a[2][i]==c) f=1,cur=i;
                }
                if(!f) cout<<0;
                else
                {
                    f=0;
                    for(int i=2;i<=l[1];i++)
                    {
                        if(a[2][cur-1]==a[1][i]) f=1;
                    }
                    if(f) cout<<1;
                    else cout<<0;
                }
            }
            cout<<endl;
        }
    }


}
