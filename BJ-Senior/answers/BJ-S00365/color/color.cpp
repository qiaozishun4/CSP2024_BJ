#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=2e5+10,N1=2200,V=25;
const ll INF=1e18+10;
ll f1[N1][N1][2],f2[N][V][2];
int a[N];int n,v;
void mg(int &a,int &b,int c){
    if(c>=a){
        b=a;a=c;
    }else if(c>=b){
        b=c;
    }
}void cmx(ll &a,ll b){
    if(b>a) a=b;
}void cmx(int &a,int b){
    if(b>a) a=b;
}map<int,int> q;
int to[N];
void dp1(){
    memset(f1,0,sizeof(f1));
    for(int i=0;i<=n;i++) for(int j=0;j<=v;j++) f1[i][j][0]=-INF,f1[i][j][1]=-INF;
    f1[1][0][0]=0,f1[1][0][1]=0;
    for(int i=2;i<=n;i++){
        ll m1=0;
        for(int j=0;j<=v;j++) m1=max(m1,f1[i-1][j][1]);
        f1[i][a[i-1]][0]=max(m1,f1[i-1][a[i]][1]+to[a[i]]);
        ll c=0;if(a[i]==a[i-1]) c=to[a[i]];
        for(int j=0;j<=v;j++) cmx(f1[i][j][0],f1[i-1][j][0]+c);
        m1=0;
        for(int j=0;j<=v;j++) m1=max(m1,f1[i-1][j][0]);
        f1[i][a[i-1]][1]=max(m1,f1[i-1][a[i]][0]+to[a[i]]);
        c=0;if(a[i]==a[i-1]) c=to[a[i]];
        for(int j=0;j<=v;j++) cmx(f1[i][j][1],f1[i-1][j][1]+c);
        /*for(int j=0;j<=v;j++){
            cout<<i<<' '<<j<<' '<<f1[i][j][0]<<' '<<f1[i][j][1]<<endl;
        }*/
    }ll ans=0;
    for(int i=0;i<=v;i++){
        cmx(ans,f1[n][i][0]);cmx(ans,f1[n][i][1]);
    }cout<<ans<<endl;
}void dp2(){
    memset(f2,0,sizeof(f2));
    for(int i=0;i<=n;i++) for(int j=0;j<=v;j++) f2[i][j][0]=-INF,f2[i][j][1]=-INF;
    f2[1][0][0]=0,f2[1][0][1]=0;
    for(int i=2;i<=n;i++){
        ll m1=0;
        for(int j=0;j<=v;j++) m1=max(m1,f2[i-1][j][1]);
        f2[i][a[i-1]][0]=max(m1,f2[i-1][a[i]][1]+to[a[i]]);
        ll c=0;if(a[i]==a[i-1]) c=to[a[i]];
        for(int j=0;j<=v;j++) cmx(f2[i][j][0],f2[i-1][j][0]+c);
        m1=0;
        for(int j=0;j<=v;j++) m1=max(m1,f2[i-1][j][0]);
        f2[i][a[i-1]][1]=max(m1,f2[i-1][a[i]][0]+to[a[i]]);
        c=0;if(a[i]==a[i-1]) c=to[a[i]];
        for(int j=0;j<=v;j++) cmx(f2[i][j][1],f2[i-1][j][1]+c);
        /*for(int j=0;j<=v;j++){
            cout<<i<<' '<<j<<' '<<f2[i][j][0]<<' '<<f2[i][j][1]<<endl;
        }*/
    }ll ans=0;
    for(int i=0;i<=v;i++){
        cmx(ans,f2[n][i][0]);cmx(ans,f2[n][i][1]);
    }cout<<ans<<endl;
}void slv(){
    cin>>n;q.clear();
    for(int i=1;i<=n;i++) cin>>a[i],q[a[i]]=1;
    int tp=0;for(auto &ed:q) ed.se=++tp,to[tp]=ed.fi;
    for(int i=1;i<=n;i++) a[i]=q[a[i]];
    v=0;for(int i=1;i<=n;i++) cmx(v,a[i]);
    if(n<=2100) dp1();
    else if(v<=12) dp2();
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;cin>>t;while(t--) slv();
    fclose(stdin);fclose(stdout);
    return 0;
}