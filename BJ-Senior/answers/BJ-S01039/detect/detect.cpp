#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
struct node
{
    ll d,v,a;
    double s=0;
    //当a>0时，在第s位置开始超速
    //当a<0时，在第s位置停止超速
    //当a=0时，s无效
}car[100001];
ll p[100001],n,m,l,v;
bool vis[100001];
bool check(ll i,ll j)
{
    if(i==0 || i==m+1) return 0;
    if(p[i]<car[j].d) return 0;
    if(car[j].a>0)
    {
        if(p[i]>car[j].s)
        {
            return 1;
        }
    }
    else if(car[j].a<0)
    {
        if(p[i]<car[j].s)
        {
            return 1;
        }
    }
    else if(car[j].a==0)
    {
        if(car[j].v>v)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T,ans,ans2;
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        ans2=0;
        cin>>n>>m>>l>>v;
        for(ll i=1;i<=n;i++)
        {
            cin>>car[i].d>>car[i].v>>car[i].a;
            if(car[i].a!=0) car[i].s=car[i].d+(v*v-car[i].v*car[i].v)/(2.0*car[i].a);
            else car[i].s=l;
        }

        //(1)
        for(ll i=1;i<=m;i++)
        {
            cin>>p[i];
            for(ll j=1;j<=n;j++)
            {
                if(vis[j]==0 && check(i,j))
                {
                    ans++;
                    vis[j]=1;
                }
            }
        }
        cout<<ans<<' ';

        //(2)
        for(ll i=1;i<=m;i++)
        {
            bool flag=0;
            for(ll j=1;j<=n;j++)
            {
                //只要当前车能被左边一个或右边一个检测到即可
                if(check(i,j)==1 && check(i-1,j)==0 && check(i+1,j)==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                ans2++;
                for(ll j=i;j<m;j++)
                {
                    p[j]=p[j+1];
                }
                m--;
                i--;
            }
        }
        cout<<ans2<<endl;
    }
    cout<<flush;
    return 0;
}
