#include<iostream>//version 100
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
int n,a[N],aa[N],m,b[N];
int cnt[N],cntdead;
int main()
{
    #ifdef use_freopen
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    #endif
    #ifdef use_debug
    freopen("/home/rdfz/CSP-S/duel/duel4.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        aa[i]=a[i];
    }
    sort(aa+1,aa+n+1);
    m=unique(aa+1,aa+n+1)-aa-1;
    for(int i=1;i<=n;i++)
    {
        b[i]=lower_bound(aa+1,aa+m+1,a[i])-aa;
        cnt[b[i]]++;
        //cout<<"b["<<i<<"]="<<b[i]<<'\n';
    }
    for(int i=1;i<=m;i++)
    {
        if(cnt[i]>=cntdead)
        {
            //cnt[i]-=cntdead;
            cntdead=0;
            //cout<<i<<" monster wins,remain "<<cnt[i]<<'\n';
        }
        else
        {
            cntdead-=cnt[i];
            //cout<<"static monster wins,remain "<<cntdead<<'\n';
        }
        cntdead+=cnt[i];
        //cout<<"static monsters have "<<cntdead<<" now.\n";
    }
    cout<<cntdead;
    cout<<endl;
    return 0;
}
