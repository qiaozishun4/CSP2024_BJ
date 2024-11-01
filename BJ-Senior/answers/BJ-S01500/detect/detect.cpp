#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+7;
int n,m,l,v;
int ll[1000060];
double p[maxn],d[maxn],v0[maxn],dd[maxn],a[maxn],vp[maxn];
double fing(int x){
    return (v+v0[x])*(v-v0[x])/(2*a[x]);
}
void solve1()//jia
{
    int cnt=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v0[i]>=v&&d[i]<=p[m])
        {
            ll[(int)d[i]]=1;
        }
        else{
            dd[i]=d[i]+fing(i);
            ll[((int)dd[i])+1]=1;
            if(p[m]<=((int)dd[i])+1)
            {
                cnt++;
            }
        }
    }
    int fg;
    for(int i=0;i<=p[m];i++)
    {
        if(ll[i])
        {
            fg=i;
            break;
        }
    }
    for(int i=0;i<=m;i++){
        if((int)p[i]<=fg){
            ans++;
        }
    }
    cout<<cnt<<" "<<ans<<endl;
}
void solve2()//jian
{
    int cnt=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v0[i]<=v&&d[i]<=p[m])
        {
            continue;
        }
        else{
            dd[i]=d[i]+fing(i);
            ll[((int)dd[i])+1]=1;
            if(p[m]<=((int)dd[i])+1)
            {
                cnt++;
            }
        }
    }
    int fg;
    for(int i=p[m];i>=0;i--)
    {
        if(ll[i])
        {
            fg=i;
            break;
        }
    }
    for(int i=0;i<=m;i++){
        if((int)p[i]>=fg){
            ans++;
        }
    }
    cout<<cnt<<" "<<ans<<endl;
}
void solve3(){
    int cnt=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(v0[i]>=v&&d[i]<=p[m])
        {
            ll[(int)d[i]]=1;
            for(int j=1;j<=m;j++)
            {
                if(p[i])break;
                if(p[i]>=d[i])
                {
                    vp[i]=1;
                    break;
                }
            }
            cnt++;
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(!vp[i])
        {
            ans++;
        }
    }
    cout<<cnt<<" "<<ans-1<<endl;
}
int t;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
while(t--)
{
    memset(d,0,sizeof(d));
    memset(v0,0,sizeof(v0));
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(dd,0,sizeof(dd));
    memset(ll,0,sizeof(ll));
    memset(vp,0,sizeof(vp));
    cin>>n>>m>>l>>v;
    bool f1,f2;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&d[i],&v0[i],&a[i]);
        if(a[i]>0)f1=1;
        if(a[i]<0)f2=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
    }

  //  if(f1&&!f2)solve1();
   // if(f2&&!f1)solve2();
    //if(!f1&&!f2)
        solve3();
}


    return 0;
}
