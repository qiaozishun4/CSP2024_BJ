#include<bits/stdc++.h>
using namespace std;
int l=1;
int n,a[100005]={};
int vis[100005]={},maxn=0;
int sl(int yuan,int r)
{
    for(int i=yuan;i<r;i++)
    {
        if(a[i]!=0)return i;
    }
}
int main()
{
     freopen("duel.in","r",stdin);
     freopen("duel.out","w",stdout);

     cin>>n;
     for(int i=1,s;i<=n;i++)
     {
         cin>>s;
         a[s]++;
         vis[s]++;
         maxn=max(maxn,s);
     }
     for(int i=1;i<=maxn;i++)
     {
         int l=sl(l,i);
         for(int j=l;j<i;j++)
         {
             if(vis[i]!=0&&a[j]!=0)
             {
                 int zc=min(a[j],vis[i]);
                 a[j]-=zc;
                 vis[i]-=zc;
             }
         }
     }
     int ans=0;
     for(int i=1;i<=maxn;i++)
     {
         ans+=a[i];
     }
     cout<<ans;
     fclose(stdin);
     fclose(stdout);
    return 0;
}
