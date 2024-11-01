#include<bits/stdc++.h>
using namespace std;
#define N 1000100
int d[N],v[N],p[N],f[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l,_v,ans=0,ans1=0;
        cin>>n>>m>>l>>_v;
        for(int i=0;i<=l;i++) f[i]=0;
        for(int i=0,a;i<n;i++) cin>>d[i]>>v[i]>>a,f[d[i]]=1;
        for(int i=0;i<m;i++) cin>>p[i],f[p[i]]=2;
        for(int i=0;i<n;i++) if(v[i]>_v)
        {
            for(int j=d[i];j<=l;j++) if(f[i]==2)
            {
                ans++;
                f[j]=3;
            }
        }
        for(int i=0;i<=l;i++) ans1+=(f[i]==3);
        cout<<ans<<" "<<ans1<<endl;
    }
    return 0;
}
