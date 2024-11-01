#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[100005],l[100005],u[100005];
int ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    m=0;
    memset(l,0,sizeof(l));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        l[r[i]]++;
        u[r[i]]++;
        m=max(m,r[i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(u[i]!=0)
        {
            for(int j=i-1;j>0&&u[i]>0;j--)
            {
                if(l[j]!=0)
                {
                    if(u[i]>=l[j])
                    {
                        u[i]-=l[j];
                        l[j]=0;
                    }
                    else
                    {
                        l[j]-=u[i];
                        u[i]=0;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        ans+=l[i];
    }
    cout<<ans<<endl;
    return 0;
}