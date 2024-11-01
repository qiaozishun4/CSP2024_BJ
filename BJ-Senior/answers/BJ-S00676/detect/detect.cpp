#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double epss=0.000001;
struct one_car
{
    double d,sv,a;
}cars[100009];
ll n,m,L,V,tmpp1,tmpp2,tmpp3,cnt_ans1;
struct ppppp{double frt,scd;ll bh;}over_p[100009];
double over_time,over_dis;
bool isover[100009];
set<double>st,usin;
void init()
{
    n=0,m=0,L=0,V=0,tmpp1=0,tmpp2=0,tmpp3=0,cnt_ans1=0;
    for(int i = 0;i <100009;i++)
    {
        cars[i].d=0;
        cars[i].sv=0;
        cars[i].a=0;
        over_p[i].frt=0;
        over_p[i].scd=0;
        over_p[i].bh=0;
        isover[i]=0;
    }
    st.clear();
    usin.clear();
    return;
}
void indata()
{
    scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
    for(ll i = 1;i <=n;i++)
    {
        scanf("%lld %lld %lld",&tmpp1,&tmpp2,&tmpp3);
        cars[i].d=tmpp1;
        cars[i].sv=tmpp2;
        cars[i].a=tmpp3;
    }
    for(ll i = 1;i <=m;i++)scanf("%lld",&tmpp1),st.insert(double(tmpp1));
    return;
}
double get_gting(double l)
{
    set<double>::iterator it=lower_bound(st.begin(),st.end(),l);
    if(it==st.end())return 2e9;
    return (*it);
}
void getover()
{
    for(ll i = 1;i <=n;i++)
    {
        over_p[i].bh=i;
        if(cars[i].a<0)
        {
            if(cars[i].sv>V)
            {
                over_time=-(cars[i].sv-V)/cars[i].a;
                over_dis=over_time*(cars[i].sv+V)/2;
                over_p[i].frt=cars[i].d;
                over_p[i].scd=cars[i].d+over_dis-epss;
            }
            else
            {
                over_p[i].frt=L+5;
                over_p[i].scd=L+4;
            }
        }
        else if(cars[i].a==0)
        {
            if(cars[i].sv>V)
            {
                over_p[i].frt=cars[i].d;
                over_p[i].scd=L;
            }
            else
            {
                over_p[i].frt=L+5;
                over_p[i].scd=L+4;
            }
        }
        else
        {
            if(cars[i].sv>V)
            {
                over_p[i].frt=cars[i].d;
                over_p[i].scd=L;
            }
            else if(cars[i].sv==V)
            {
                over_p[i].frt=cars[i].d+epss;
                over_p[i].scd=L;
            }
            else
            {
                over_time=(V-cars[i].sv)/cars[i].a;
                over_dis=over_time*(V+cars[i].sv)/2;
                over_p[i].frt=cars[i].d+over_dis+epss;
                over_p[i].scd=L;
            }
        }
    }
    for(ll i = 1;i <=n;i++)
        if(get_gting(over_p[i].frt)<=over_p[i].scd)
            isover[i]=1,cnt_ans1++;
    return;
}
bool cmp(ppppp aaa,ppppp bbb)
{
    return aaa.frt<bbb.frt;
}
void solve()
{
    sort(over_p+1,over_p+n+1,cmp);
    for(ll i = n;i >=1;i--)
    {
        if(!isover[over_p[i].bh])continue;
        set<double>::iterator it=lower_bound(usin.begin(),usin.end(),over_p[i].frt);
        if(it!=usin.end())
            if((*it)<=over_p[i].scd)
                continue;
        usin.insert(get_gting(over_p[i].frt));
    }
    printf("%lld %lld\n",cnt_ans1,m-usin.size());
    return;
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll T;scanf("%lld",&T);
    for(ll i = 1;i <=T;i++)
    {
        init();
        indata();
        getover();
        solve();
    }
    return 0;
}
