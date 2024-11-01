#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int chaosu[t+1]={0},ans[t+1]={0};
    while(t!=0)
    {
        int m,n,l,v0,s;
        cin>>n>>m>>l>>v0;
        int x[n+1],v[n+1],a[n+1],p[m+1],flag[m+1]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>x[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0 && v[i]>v0)
            {
                chaosu[t]++;
                for(int q=1;q<=m;q++) flag[q]+=1;
            }
            if(a[i]>0)
            {
                s=v0*v0-v[i]*v[i];
                int xt=s/(2*a[i])+x[i];
                for(int j=m;j>1;j--)
                {
                    if(xt<=p[j] && xt>=p[j-1])
                    {
                        chaosu[t]++;
                        for(int q=j;q<=m;q++) flag[q]+=1;
                    }
                }
            }
            if(a[i]<0)
            {
                s=v0*v0-v[i]*v[i];
                int xt=s/(2*a[i])+x[i];
                for(int j=1;j<m;j++)
                {
                    if(xt>=p[j] && xt<=p[j+1])
                    {
                        chaosu[t]++;
                        for(int q=1;q<=j;q++) flag[q]+=1;
                    }
                }
            }
            for(int i=1;i<=m;i++)
            {
                if(flag[i]==n) ans[t]++;
            }
        }
        t--;
    }
    for(int i=t;i>=1;i--)
    {
        cout<<chaosu[i]<<ans[i]<<endl;
    }

    return 0;
}
