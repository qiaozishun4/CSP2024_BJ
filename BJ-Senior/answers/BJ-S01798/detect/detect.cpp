#include<bits/stdc++.h>
using namespace std;
#define ll long long;
const int N=1e4+10;
const int INF=0x3f3f3f3f;
int a[N];
int T;
int p[N];
int sp[N][N];
int n,m,l,v;
int cnt=0;
int del=0;
struct nod
{
    int d,v,a;
} ca[N];
void init()
{
    memset(a,0,sizeof a);
    memset(ca,0,sizeof ca);
    memset(p,0,sizeof p);
    n=m=l=v=0;
    return;
}
int sped(int v,int a,int s)
{
    int res=ceil(sqrt(pow(v,2)+(2*a*s)));
    return res;
}
bool ok(int k)
{
    int fs=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(sp[i][j]>v&&j!=k)
            {
                fs++;
            }
        }
    }
    return (fs==cnt)?1:0;
}
void work()
{
    cin>>n>>m>>l>>v;
    for(int i=1; i<=n; i++)
    {
        cin>>ca[i].d>>ca[i].v>>ca[i].a;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>p[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(p[j]<ca[i].d)
            {
                continue;
            }
            int s=p[j]-ca[i].d;
            sp[i][j]=sped(ca[i].v,ca[i].a,s);
            if(sp[i][j]>v)
            {
                    cnt++;

            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        if(ok(i))
        {
            del++;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        init();
        work();
        cout<<cnt<<" "<<del<<'\n';

    }
    return 0;
}
