#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m,L,V;
struct type{
    long long st,ed;
    bool operator< (const type& H){
        if(st==H.st) return ed<H.ed;
        return st<H.st;
    }
}s[100005];
long long p[100005];
void solve(){
    scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
    V=V*V;
    long long d,v,a;
    double tmp;
    for(long long i=1;i<=n;i++) s[i].st=0,s[i].ed=0;
    for(long long i=1;i<=m;i++) p[i]=0;
    for(long long i=1;i<=n;i++){
        scanf("%lld%lld%lld",&d,&v,&a);
        v=v*v-2*a*d;
        if(a==0){
            if(v>V) s[i].st=d,s[i].ed=L;
            else s[i].st=d,s[i].ed=d-1;
        }
        else{
            tmp=(V-v)/(2*a);
            if(a>0) s[i].st=max((long long)floor(tmp)+1,d),s[i].ed=L;
            else s[i].st=d,s[i].ed=min((long long)floor(tmp-1/(2*a)),L);
        }
    }
    sort(s+1,s+n+1);
    /*for(int i=1;i<=n;i++){
        cout<<s[i].st<<' '<<s[i].ed<<endl;
    }
    cout<<endl;*/
    for(long long i=1;i<=m;i++) scanf("%lld",&p[i]);
    long long ans1=0,ans2=0;
    for(long long i=1,j=1;i<=n;i++){
        while(p[j]<s[i].st&&j<=m+1) j++;
        if(s[i].st<=p[j]&&p[j]<=s[i].ed) ans1++;
        else s[i].st=L+1;
        //cout<<i<<' '<<j<<endl;
    }
    sort(s+1,s+n+1);
    /*for(int i=1;i<=n;i++){
        cout<<s[i].st<<' '<<s[i].ed<<endl;
    }
    cout<<endl;*/
    int now=L+1;
    for(long long i=n,j=m;i>=1;i--){
        if(s[i].st>L) continue;
        if(s[i].ed>=now)continue;
        while(p[j-1]>=s[i].st) j--;
        now=p[j],ans2++;
    }
    cout<<ans1<<' '<<m-ans2<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
