#include<iostream>//100?
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<random>
#define use_freopen
//#define use_debug
using namespace std;
const int N=1e5+5;
typedef double doub;
const doub tiny=1e-8;
inline doub getspeed1(doub v0,doub a,doub t){return v0+a*t;}
inline doub getdist1(doub v0,doub a,doub t){return v0*t+0.5*a*t*t;}
inline doub getspeed2(doub v0,doub a,doub s){return sqrt(v0*v0+2*a*s);}
inline doub getdist2(doub v0,doub a,doub v1){return (v1*v1-v0*v0)/2/a;}
inline bool distreachable(doub v0,doub a,doub s){return a>=0||getdist2(v0,a,0)>=s;}
inline bool speedreachable(doub v0,doub a,doub s,doub v1){return (a==0&&v0>=v1+tiny)||(v0>=v1+tiny||(distreachable(v0,a,s)&&getspeed2(v0,a,s)>=v1+tiny));}
int n,m;
doub l,v;
doub b[N];
int ANS_TMP,ans;
inline void read_int(int& a)
{
    a=0;
    int z=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        z=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=a*10+(c-'0');
        c=getchar();
    }
    a=a*z;
}
inline void read_double_as_int(double& a)
{
    int b;
    read_int(b);
    a=b;
}
struct ISTREAM{} _cin;
ISTREAM operator>>(ISTREAM CIN,int& a){read_int(a);return CIN;}
ISTREAM operator>>(ISTREAM CIN,double& a){read_double_as_int(a);return CIN;}
struct car
{
    doub d,v0,a;
    doub lbound,rbound;
    int lpos,rpos;
    void input(){_cin>>d>>v0>>a;}
    void init(doub ll,doub rr){lbound=ll;rbound=rr;}
    void getbounds()
    {
        if(!speedreachable(v0,a,l-d,v))//dont need cameras
        {
            init(l,0);//nullarea
            //cout<<" d="<<d<<" v0="<<v0<<" a="<<a<<" area=nullarea"<<'\n';
            //cout<<"#"<<distreachable(v0,a,l-d)<<'\n';
            return;
        }
        if(v0>v+tiny)//begin with highspeed
            lbound=d;
        else//catches up
            lbound=getdist2(v0,a,v+tiny)+d;
        if(distreachable(v0,a,l-d))//reaches the end
            if(getspeed2(v0,a,l-d)>v+tiny)//with high speed
            {
                rbound=l+tiny;
                //cout<<"with high speed\n";
            }
            else//slowed down
            {
                rbound=getdist2(v0,a,v+tiny)+d;
                //cout<<"slowed down\n";
            }
        else//stops in middle
        {
            rbound=getdist2(v0,a,v+tiny)+d;
            //cout<<"stops in middle\n";
        }
        //cout<<" d="<<d<<" v0="<<v0<<" a="<<a<<" lbound="<<lbound<<" rbound="<<rbound<<'\n';
    }
    void INIT()
    {
        input();
        getbounds();
    }
    void INITINTEGERBOUNDS()
    {
        lpos=lower_bound(b+1,b+m+1,lbound)-b;
        rpos=lower_bound(b+1,b+m+1,rbound)-b-1;
        //cout<<" lbound="<<lbound<<" rbound="<<rbound<<" lpos="<<lpos<<" rpos="<<rpos<<'\n';
        if(lpos<=rpos) ANS_TMP++;
    }
} a[N];
bool cmp1(car a,car b)
{
    if(a.lpos>a.rpos) return false;
    if(b.lpos>b.rpos) return true;
    if(a.lpos<=b.rpos&&b.lpos<=a.rpos) return a.rpos<b.rpos;
    return a.lpos<=b.rpos;
}
void MAIN()
{
    ans=ANS_TMP=0;
    _cin>>n>>m>>l>>v;
    for(int i=1;i<=n;++i) a[i].INIT();
    for(int i=1;i<=m;++i) cin>>b[i];
    //sort(b+1,b+m+1);
    for(int i=1;i<=n;++i) a[i].INITINTEGERBOUNDS();
    sort(a+1,a+n+1,cmp1);
    if(a[1].lpos>a[1].rpos)
    {
        cout<<ANS_TMP<<' '<<m<<'\n';
        return;
    }
    for(int i=1;i<=n;)
    {
        int line=a[i].rpos;
        //cout<<"line="<<line<<'\n';
        while(a[i].lpos<=line&&a[i].lpos<=a[i].rpos&&line<=a[i].rpos&&i<=n)
        {
            //cout<<" dictated ("<<a[i].lpos<<"~"<<a[i].rpos<<'\n';
            ++i;
        }
        ans++;
        if(a[i].lpos>a[i].rpos||i>n) break;
    }
    cout<<ANS_TMP<<' '<<m-ans<<'\n';
}
int main()
{
    #ifdef use_freopen
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    #endif
    #ifdef use_debug
    freopen("/home/rdfz/CSP-S/detect/detect5.in","r",stdin);
    #endif
    //ios::sync_with_stdio(false);
    int t;
    _cin>>t;
    while(t--) MAIN();
    cout<<endl;
    return 0;
}
