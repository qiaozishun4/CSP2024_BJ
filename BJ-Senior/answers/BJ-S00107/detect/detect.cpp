#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+3,M=N,L=1e6+3,V=1e3+3;
struct range
{
    double l,r;
    bool inc_l,inc_r;

};
vector<range> c;
double p[M];
vector<int> guan[M];
int n,m,l,v,cnt;
bool vis[N];
bool check(int mid)
{
    memset(vis,0,sizeof vis);
    int co=0;
    //cout<<mid<<endl;
    for (int i=mid+1;i<=m;i++)
    {
        for (auto x:guan[i])
        {
            if (!vis[x])
            {
                co++;
                //cout<<i<<" "<<x<<" co++"<<endl;
                vis[x]=true;
            }
        }
    }
    //cout<<mid<<" "<<co<<endl;
    return co==cnt;
}
bool cmp(vector<int> &a,vector<int> &b)
{
    return a.size()<b.size();
}
bool checkava(int which,range car)
{
    bool ava=true;
    if (car.inc_l)
    {
        if (p[which]<car.l)
        {
            ava=false;
        }
    }
    else
    {
        if (p[which]<=car.l)
        {
            ava=false;
        }
    }
    if (car.inc_r)
    {
        if (p[which]>car.r)
        {
            ava=false;
        }
    }
    else
    {
        if (p[which]>=car.r)
        {
            ava=false;
        }
    }
    return ava;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        c.clear();
        cin>>n>>m>>l>>v;
        for (int i=1;i<=m;i++) guan[i].clear();
        c.reserve(n+2);
        for (int i=1;i<=n;i++)
        {
            int d,v0,a;
            cin>>d>>v0>>a;
            if (a==0&&v0>v)
            {
                c.push_back({d,l,true,true});
            }
            else
            {
                double s_chao=((double)v*v-v0*v0)/(2*a);
                if (s_chao>0)
                {
                    if (a<0)
                    {
                        c.push_back({d,d+s_chao,true,false});
                    }
                    else
                    {
                        c.push_back({d+s_chao,l,false,true});
                    }
                }

            }
        }
        for (int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        cnt=0;
        for (auto it=c.begin();it!=c.end();it++)
        {
                        range car=*it;
            //cout<<car.l<<" "<<car.r<<endl;

            int which;
            if (car.inc_l)
            {
                which=lower_bound(p+1,p+1+m,car.l)-p;
            }
            else
            {
                which=upper_bound(p+1,p+1+m,car.l)-p;
            }
            if (which==m+1) continue;

            if (checkava(which,car))
            {
                cnt++;

                int i=distance(c.begin(),it);
                while (checkava(which,car))
                {
                    //cout<<"push "<<which<<" "<<i<<endl;
                    guan[which].push_back(i);
                    which++;
                }

            }
        }
        //cout<<cnt<<endl;

        sort(guan+1,guan+1+m,cmp);
        int l=0,r=m;
        while (l<r)
        {
            int mid=(l+r+1)>>1;
            if (check(mid))
            {
                l=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<cnt<<" "<<l<<endl;
        /*
        vector<int> erased;
        while (erased.s)
        for (int i=1;i<=m;i++)
        {
            for (auto x:erased)
            {
                auto it=lower_bound(guan[i].begin(),guan[i].end(),x);
                if (it!=guan[i].end())
                {
                    guan[i].erase(it);
                }
            }


        }*/
    }
    return 0;
}
