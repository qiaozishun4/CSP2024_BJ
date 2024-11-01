#include<bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int maxn=1e5,maxm=1e5;
int t,p[maxm];
struct car
{
    int d,v,a;
}c[maxn];
vector<int> she[maxm];
int che[maxn];

bool cmp(vector<int> x,vector<int> y)
{
    return x.size()<y.size();
}

void work()
{
    int n,m,L,V,ans1=0,ans2=0;
    scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&(c[i].d),&(c[i].v),&(c[i].a));
    }
    for(int i=0;i<m;i++)
    {
        scanf("%lld",&(p[i]));
    }
    for(int i=0;i<n;i++)
    {
        che[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        she[i].clear();
        she[i].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        bool ff=false;
        double dend;
        if(c[i].a>=0)
        {
            dend=L;
        }
        else
        {
            dend=min((double)(L),c[i].d-pow((double)(c[i].v),2)/2/c[i].a);
        }
        for(int j=0;j<m;j++)
        {
            if(p[j]<c[i].d||p[j]>dend)
            {
                continue;
            }
            double vnow=sqrt((double)(pow(c[i].v,2)+2*c[i].a*(p[j]-c[i].d)));
            if(vnow>V)
            {
                ff=true;
                che[i]++;
                she[j].push_back(i);
            }
        }
        if(ff)
        {
            ans1++;
        }
    }
    sort(she,she+m,cmp);
    for(int i=0;i<m;i++)
    {
        bool canc=true;
        for(int j=1;j<she[i].size();j++)
        {
            if(che[she[i][j]]<=1)
            {
                canc=false;
                break;
            }
        }
        if(canc)
        {
            ans2++;
            for(int j=1;j<she[i].size();j++)
            {
                che[she[i][j]]--;
            }
        }
    }
    printf("%lld %lld\n",ans1,ans2);
}

signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        work();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
