#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,l,V,d[100005],v[100005],a[100005],p[100005];
int b[100005],c[100005];
struct node
{
    int l,r;
}k[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>V;
        int f=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if((a[i]==0&&p[j]>d[i])||p[j]==d[i])
                {
                    if(v[i]>V)
                    {
                        //if(i==2) cout<<j<<endl;
                        if(!k[i].l) ans++,k[i].l=j;
                        k[i].r=j;
                    }
                }
                if(p[j]>d[i]&&V*V-v[i]*v[i]<(p[j]-d[i])*2*a[i])
                {

                    if(!k[i].l) ans++,k[i].l=j;
                    k[i].r=j;
                }
            }
        }
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(k[i].l!=0)
            {
                b[1]=k[i].l,c[1]=k[i].r;
                break;
            }
        }
            //cout<<k[2].l<<endl;
        for(int i=1;i<=n;i++)
        {
            int flag=0;
            if(k[i].l==0) continue;
            int l=k[i].l,r=k[i].r;
            for(int j=1;j<=cnt;j++)
            {

                int d=max(l,b[j]),e=min(r,c[j]);
                if(d<=e)
                {
                    b[i]=d;
                    c[i]=e;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                b[++cnt]=l;
                c[cnt]=r;
            }
        }
        cout<<ans<<" "<<n-cnt<<'\n';
        continue;
    }
    return 0;
}
