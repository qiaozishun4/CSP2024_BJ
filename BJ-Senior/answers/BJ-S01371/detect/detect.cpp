#include<bits/stdc++.h>
using namespace std;

const int maxp=1e5+10;
int z,t,m,l,v;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int d[maxp],u[maxp],a[maxp],p[maxp],k[maxp],tnt=1;
        cin>>z>>m>>l>>v;
        for(int i=1;i<=z;i++)
        {
            cin>>d[i]>>u[i]>>a[i];
            if(u[i]>v) k[tnt++]=d[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+1+m);
        sort(k+1,k+tnt);
        int l=1,y=1,num=0,ans=0;
        int o[z+10];
        for(int i=1;i<tnt;i++)
        {
            if(p[m]>=k[i]) ans++;
        }
        cout<<ans<<' '<<m-1<<endl;
    }
    return 0;
}
