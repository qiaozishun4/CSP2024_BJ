#include<bits/stdc++.h>
using namespace std;
long long t,n,m,mxx,mx,mn,x,v,ans1,ans2,a[100005];
struct node
{
    long long v0,a,x0,l,r;
}car[100005];
vector<long long> z[100005],y[100005],now;
bool book[100005];
void dfs(long long deep,bool flag,long long cnt)
{
    if(deep==m)
    {
        memset(book,0,sizeof(book));
        for(long long i=0;i<now.size();i++)
        {
            for(long long j=0;j<y[now[i]].size();j++)
            {
                book[y[now[i]][j]]=1;
            }
        }
        for(long long i=1;i<=n;i++)
        {
            if(!book[i]&&z[i].size())
            {
                return;
            }
        }
        ans2=min(ans2,cnt);
        return;
    }
    dfs(deep+1,0,cnt);
    now.push_back(deep+1);
    dfs(deep+1,1,cnt+1);
    now.pop_back();
    return;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        memset(car,0,sizeof(car));
        now.clear();
        for(long long i=1;i<=1e5;i++)
        {
            z[i].clear();
            y[i].clear();
        }
        ans1=mxx=mx=0,ans2=mn=1e9;
        cin>>n>>m>>x>>v;
        for(long long i=1;i<=n;i++)
        {
            cin>>car[i].x0>>car[i].v0>>car[i].a;
            mx=max(mx,car[i].a),mn=min(mn,car[i].a);
            if(car[i].a==0)
            {
                if(car[i].v0>v)
                {
                    car[i].l=car[i].x0;
                    car[i].r=x;
                }
            }
            else if(car[i].a<0)
            {
                if(car[i].v0>v)
                {
                    car[i].l=car[i].x0;
                    car[i].r=car[i].x0+floor((v*v-car[i].v0*car[i].v0)/2ll/car[i].a);
                    if((long double)(v*v-car[i].v0*car[i].v0)/2*1.0/car[i].a==(long double)floor((v*v-car[i].v0*car[i].v0)/2*1.0/car[i].a))
                    {
                        car[i].r--;
                    }
                }
            }
            else
            {

                if(ceil(sqrt(2ll*car[i].a*(x-car[i].x0)+car[i].v0*car[i].v0))>v)
                {
                    if(car[i].v0>v)
                    {
                        car[i].l=car[i].x0;
                    }
                    else
                    {
                        car[i].l=car[i].x0+ceil((v*v-car[i].v0*car[i].v0)/2ll/car[i].a);
                        if((long double)(v*v-car[i].v0*car[i].v0)/2*1.0/car[i].a==(long double)ceil((v*v-car[i].v0*car[i].v0)/2*1.0/car[i].a))
                        {
                            car[i].l++;
                        }
                    }
                    car[i].r=x;
                }
            }
        }
        for(long long i=1;i<=m;i++)
        {
            cin>>a[i];
            mxx=max(mxx,a[i]);
        }
        if(!mx&&!mn)
        {
            for(long long i=1;i<=n;i++)
            {
                if(car[i].x0<=mxx&&car[i].v0>v)
                {
                    ans1++;
                }
            }
            ans2=1;
            if(!ans1)
            {
                ans2=0;
            }
        }
        else
        {
            for(long long i=1;i<=n;i++)
            {
                for(long long j=1;j<=m;j++)
                {
                    if(car[i].l<=a[j]&&a[j]<=car[i].r)
                    {
                        z[i].push_back(j);
                        y[j].push_back(i);
                    }
                }
            }
            for(long long i=1;i<=n;i++)
            {
                if(z[i].size())
                {
                    ans1++;
                }
            }
            dfs(1,0,0);
            now.push_back(1);
            dfs(1,1,1);
            now.pop_back();
        }
        cout<<ans1<<" "<<m-ans2<<"\n";
    }
    return 0;
}
