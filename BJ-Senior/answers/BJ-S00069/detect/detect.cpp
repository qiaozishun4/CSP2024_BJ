#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+7;
const int B=3007;
int n,m,Len;
ll V;
ll d[maxn],v[maxn],a[maxn];
//Q1
int L[maxn],R[maxn];
int p[maxn];
//Q2
int dp[B][B];
int NL[maxn],NR[maxn];
int cnt=0;
inline void Read(){
    cnt=0;
    cin>>n>>m>>Len>>V;
    for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
    for(int i=1;i<=m;i++)cin>>p[i];
}
inline void GetRange(){
    for(int i=1;i<=n;i++){
        if(a[i]<0){
            L[i]=d[i];
            ll l=0,r=Len-d[i];
            if(v[i]<=V){
                L[i]=R[i]=-1;
                continue;
            }//never: a < 0
            r=min(1ll*r,(v[i]*v[i])/(-2*a[i]));
            while(l<r){
                int mid=l+r+1>>1;
                ll sp2=v[i]*v[i]+2*a[i]*mid;
                if(sp2>V*V)l=mid;
                else r=mid-1;
            }
            if(v[i]*v[i]+2*a[i]*l<=V*V){
                L[i]=R[i]=-1;
                continue;
            }
            R[i]=d[i]+l;
        }
        else if(a[i]>0){
            R[i]=Len;
            if(v[i]>V){
                L[i]=d[i];
                continue;
            }//Always:a > 0
            ll l=0,r=Len-d[i];
            while(l<r){
                int mid=l+r>>1;
                ll sp2=v[i]*v[i]+2*a[i]*mid;
                if(sp2<=V*V)l=mid+1;
                else r=mid;
            }
            if(v[i]*v[i]+2*a[i]*l<=V*V){
                L[i]=R[i]=-1;
                continue;
            }
            L[i]=d[i]+l;
        }
        else{
            if(v[i]<=V)L[i]=R[i]=-1;
            else L[i]=d[i],R[i]=Len;
        }
    }
}
inline void Q1(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(L[i]==-1)continue;
        int l=1,r=m;
        while(l<r){
            int mid=l+r>>1;
            if(p[mid]>=L[i])r=mid;
            else l=mid+1;
        }
        if(p[l]<L[i])continue;
        if(p[l]<=R[i]){
            int lll=1,rr=m;
            while(lll<rr){
                int mid=lll+rr+1>>1;
                if(p[mid]<=R[i])lll=mid;
                else rr=mid-1;
            }
            NL[++cnt]=l;NR[cnt]=lll;
            ans++;
        }
    }
    cout<<ans<<" "; 
}

vector<int> RG[maxn];
inline void Q2_Prework(){
    if(m>3000)return;
    for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)dp[i][j]=1e9;
    dp[0][0]=0;
    for(int i=1;i<=m;i++)RG[i].clear();
    for(int i=1;i<=cnt;i++)RG[NR[i]].push_back(NL[i]);
}
inline void Q2(){
    if(m>3000)return;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=m;j++)dp[i][j]=dp[i-1][j];
        int Lmx=0;
        for(auto l:RG[i])Lmx=max(Lmx,l);
        for(int j=Lmx;j<i;j++)dp[i][j]=dp[i-1][j];
        for(int j=0;j<Lmx;j++)dp[i][j]=1e9;
        for(int j=0;j<i;j++)dp[i][i]=min(dp[i][i],dp[i-1][j]+1);
    }
    int ans=1e9;
    for(int i=0;i<=m;i++)ans=min(ans,dp[m][i]);
    cout<<m-ans<<endl;
}
inline void slv(){
    Read();
    if(m>3000)return;
    GetRange();
    Q1();
    Q2_Prework();
    Q2();
}
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t=0;
    cin>>t;
    while(t--)slv();
    // cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    cout.flush();
}