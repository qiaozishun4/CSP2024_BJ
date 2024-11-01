#include<iostream>//20
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
const int A_=2005,A=1e6+5,N=2e5+5;
int ____________temp_T;
int lastt[N],nextt[N],pos[A];
int n,a[N];
long long ans;
inline int getvalonpos(int a,int k){return (a>>k)&1;}
void MAIN()
{
    cin>>n;
    ans=0;
    memset(pos,0,sizeof pos);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        nextt[pos[a[i]]]=i;
        lastt[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    if(n<=15)
    {
        for(int i=0;i<(1<<n);i++){
            long long anss=0;
            for(int j=1;j<=n;j++)
                if(lastt[j]&&getvalonpos(i,j-1)==getvalonpos(i,lastt[j]-1))
                    anss+=a[j];
            ans=max(anss,ans);
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    #ifdef use_freopen
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    #endif
    #ifdef use_debug
    freopen("/home/rdfz/CSP-S/color/color2.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    ____________temp_T=T;
    while(T--) MAIN();
    cout<<endl;
    return 0;
}
