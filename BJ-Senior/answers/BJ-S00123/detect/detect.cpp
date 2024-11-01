#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
int p[MAXN];
int upeqsearch(int d,int rm)
{
    int l=1,r=rm;
    int mid;
    int cnt=0;
    while(l<=r&&(++cnt)<20)
    {
        mid=(l+r)/2;
        if(p[mid]<d) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int upsearch(int d,int rm)
{
    int l=1,r=rm;
    int mid;
    int cnt=0;
    while(l<=r&&(++cnt)<20)
    {
        mid=(l+r)/2;
        if(p[mid]<=d) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int loweqsearch(int d,int rm)
{
    int l=1,r=rm;
    int mid;
    int cnt=0;
    while(l<=r&&(++cnt<20))
    {
        //cout<<l<<' '<<r<<endl;
        mid=(l+r)/2;
        if(p[mid]>d) r=mid-1;
        else l=mid+1;
    }
    return r;
}
int lowsearch(int d,int rm)
{
    int l=1,r=rm;
    int mid;
    int cnt=0;
    while(l<=r&&(++cnt<20))
    {
        //cout<<l<<' '<<r<<endl;
        mid=(l+r)/2;
        if(p[mid]>=d) r=mid-1;
        else l=mid+1;
    }
    return r;
}
int cdevide(long long a,long long b,bool &flag)
{
    if(a%b==0)
    {
        flag=true;
        return a/b;
    }
    return a/b+1;
}
int fdevide(long long a,long long b,bool &flag)
{
    if(a%b==0) flag=true;
    return a/b;
}
struct Car
{
    int d,v,a;
    bool beyond;
    int l,r;
    void update(int m,int vm)
    {
        if(a==0)
        {
            if(v>vm)
            {
                beyond=true;
                l=upeqsearch(d,m);
                r=m;
            }
        }
        else if(a>0)
        {
            bool flag=false;
            int nd=d+cdevide(1ll*vm*vm-1ll*v*v,1ll*2*a,flag);
            if((flag&&nd<p[m])||(!flag&&nd<=p[m]))
            {
                beyond=true;
                l=flag?upsearch(nd,m):upeqsearch(nd,m);
                r=m;
            }
        }
        else if(v>vm)
        {
            bool flag=false;
            int nd=d+fdevide(1ll*v*v-1ll*vm*vm,1ll*(-2)*a,flag);
            if(d<=p[m]&&((flag&&nd>p[1])||(!flag&&nd>=p[1])))
            {
                //cout<<nd<<endl;
                int nl=upeqsearch(d,m);
                //cout<<nl<<endl;
                int nr=flag?lowsearch(nd,m):loweqsearch(nd,m);
                //cout<<nr<<endl;
                if(nl<=nr)
                {
                    beyond=true;
                    l=nl;
                    r=nr;
                }
            }
        }
    }
}car[MAXN];
struct Line
{
    int l,r;
    bool operator<(const Line nl)const
    {
        return (l==nl.l)?(r>nl.r):(l<nl.l);
    }
}line[MAXN];
vector<int>to[MAXN];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,len,vm;
        cin>>n>>m>>len>>vm;
        for(int i=1;i<=n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
        for(int i=1;i<=m;i++) cin>>p[i];
        int cnt=0;
        line[0]=Line{1,m};
        for(int i=1;i<=n;i++)
        {
            car[i].update(m,vm);
            if(car[i].beyond)
            {
                line[++cnt]=Line{car[i].l,car[i].r};
            }
            if(car[i].beyond) cout<<car[i].l<<' '<<car[i].r<<endl;
            else cout<<-1<<endl;
        }
        cout<<endl;
        cout<<cnt<<' ';
        sort(line,line+cnt+1);
        for(int i=1;i<=cnt;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(line[j].r>=line[i].r) to[j].push_back(i);
            }
        }
        int res=0;
        for(int i=1;i<=cnt;i++) res+=(to[i].size()==0);
        cout<<m-res<<endl;
        cout<<endl;
    }
    return 0;
}
