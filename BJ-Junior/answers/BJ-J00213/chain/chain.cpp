#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;

int n,ans,T,l;
char a[N][N];
bool b[N][N];

int main()
{
    freopen("chain.in","r",stdin);freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='1')b[i][j]=1;
                
            }
        }
        for(int i=1;i<=q;i++)
        {
            int r,c;
            cin>>r>>c;
            for(int i=1;i<=n;i++)
            {
                int flag=1;
                for(int j=1;j<=m;j++)
                {
                    if(a[i][j]==(c+'0'))
                    {
                        for(int o=j;o>=j-k;o--)
                        {
                            if(o>=1&&a[i][j]=='1')
                            {
                                cout<<1<<"\n";
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==1)break;
                }
                flag=0;
                cout<<0<<"\n";
            }
        }
    }

}
