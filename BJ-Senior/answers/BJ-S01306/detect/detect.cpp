#include<bits/stdc++.h>
using namespace std;
int t,a[100005],v[100005],d[100005],n,m,L,V,cs[3005][3005],s,cc[3005][3005],mx[100005],mxx,ans,c[100005];
int main()
{
    freopen("detect.in","r",stdin); 
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>L>>V;
        for(int j=1;j<=n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++)
        {
            cin>>s;
            c[s]=1;
        }
        ans=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=L;k++)
            {
                cs[j][k]=0;
                if(v[k]>V&&c[k]==1&&d[j]<=k)
                {
                    cs[j][k]=1;
                    ans++;
                }
            }
        }
        for(int j=1;j<=L;j++)
        {
            if(c[j]!=1)
            {
                continue;
            }
            for(int k=1;k<=n;k++)
            {
                cc[j][k]=0;
                if(cs[j][k]==1)
                {
                    cc[j][k]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
