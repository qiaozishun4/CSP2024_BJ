#include<bits/stdc++.h>
using namespace std;
long long n,a[1010100],T,f[2010][2][2010];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            for(int ho=0;ho<=1;ho++)
            {
                for(int j=1;j<i;j++)
                {
                    int ll,rr;
                    if(ho==0) ll=i,rr=j;
                    else ll=j,rr=i;
                    if(ho==0)
                    {
                        if(j==i-1)
                        {
                            for(int k=1;k<j;k++)
                            {
                                f[i][0][j]=max(f[i][0][j],f[i-1][1][k]+(a[i]==a[k])*a[i]);
                            }
                        }
                        else
                        {
                            f[i][0][j]=max(f[i][0][j],f[i-1][0][j]+(a[i]==a[i-1])*a[i]);
                        }
                    }
                    else
                    {
                        if(j==i-1)
                        {
                            for(int k=1;k<j;k++)
                            {
                                f[i][1][j]=max(f[i][1][j],f[i-1][0][k]+(a[i]==a[k])*a[i]);
                            }
                        }
                        else
                        {
                            f[i][1][j]=max(f[i][1][j],f[i-1][1][j]+(a[i]==a[i-1])*a[i]);
                        }
                    }
                //    cout<<i<<" "<<ll<<" "<<rr<<" "<<f[i][ho][j]<<endl;
                }
            }
        }
        long long ans=0;
        for(int ho=0;ho<=1;ho++)
        {
            for(int j=1;j<=n;j++) ans=max(ans,f[n][ho][j]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
