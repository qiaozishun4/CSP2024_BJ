#include<bits/stdc++.h>
using namespace std;
int a[10007][20007];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n,kk,q;
        cin>>n>>kk>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0];
            for(int j=1;j<=a[i][0];j++)
            {
                cin>>a[i][j];
            }
        }
        int r,c;
        for(int ii=1;ii<=q;ii++)
        {
            cin>>r>>c;
            int ans=0;
            if(r==1)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=a[i][0];j++)
                    {
                        if(a[i][j]==1)
                        {
                            for(int k=j;k<=a[i][0];k++)
                            {
                                if(a[i][k]==c)
                                {
                                    if(k-j+1<=kk)
                                    {
                                        ans=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
