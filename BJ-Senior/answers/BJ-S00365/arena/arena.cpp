#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=550,LG=12;
int a0[N],a[N];
int b[N];
int c[N];int n,m;
vector<int> now;
int x[N];
int get[N<<2];
int d0[LG][N];
int d[N<<2],dp[N<<2];
int f[N<<2];
bool gtvl(int x,int l,int r,int mn,int mx){
    if(l==r){
        if(mn>mx) return 0;
        if(b[l]==-1) return 1; 
        if(mn<=b[l]&&b[l]<=mx) return 1;
        else return 0;
    }int mid=(l+r)/2;
    return gtvl(x*2,l,mid,mn,mx)&&gtvl(x*2+1,mid+1,r,mn,min(dp[x]-1,mx))
    ||gtvl(x*2+1,mid+1,r,mn,mx)&&gtvl(x*2,l,mid,mn,min(dp[x]-1,mx));
    
}
bool dfs(int x,int l,int r,int k,int mn,int mx){
    if(l==r){
        if(mn>mx) return 0;
        if(b[l]==-1) return 1; 
        if(mn<=b[l]&&b[l]<=mx) return 1;
        else return 0;
    }int mid=(l+r)/2;
    if(k<=mid){
        if(d[x]==0) return dfs(x*2,l,mid,k,dp[x],mx);
        else return dfs(x*2,l,mid,k,mn,mx)&&gtvl(x*2+1,mid+1,r,mn,min(mx,dp[x]-1));
    }else{
        if(d[x]==1) return dfs(x*2+1,mid+1,r,k,dp[x],mx);
        else return dfs(x*2+1,mid+1,r,k,mn,mx)&&gtvl(x*2,l,mid,mn,min(mx,dp[x]-1));
    }
}ll calc(int c){
    int len=0;
    while((1<<len)<c) len++;
    int dx=0;
    for(int i=len;i>=1;i--){
        for(int j=1;j<=(1<<(len-i));j++){
            d[++dx]=d0[i][j];dp[dx]=i-1;
        }
    }for(int i=1;i<=(1<<len);i++) if(i<=c) b[i]=a[i];else b[i]=-1;
    ll ans=0;
    for(int i=1;i<=(1<<len);i++){
        if(dfs(1,1,len,i,0,(1<<len)+1)) ans+=i;
    }return ans;
}int rd(int ln){
    vector<int> t1,t2;t1.clear();
    for(int i=1;i<=ln;i++) t1.push_back(i);
    int rg=0;
    while(t1.size()!=1){
        ++rg;t2.clear();int g=0;
        for(int i=0;i<t1.size();i+=2){
            ++g;int p=0;
            if(d0[rg][g]==0) p=b[t1[i]];
            else p=b[t1[i+1]];
            if(p>=rg){
                if(d0[rg][g]==0) t2.push_back(t1[i]);
                else t2.push_back(t1[i+1]);
            }else{
                if(d0[rg][g]==0) t2.push_back(t1[i+1]);
                else t2.push_back(t1[i]);
            }
        }t1=t2;
    }return t1[0];
}set<int> s;
void fd0(int x,int ln){
    if(x>ln){
        s.insert(rd(ln));
        return ;
    }
    if(b[x]!=-1) fd0(x+1,ln);
    else{
        for(int i=0;i<=3;i++) b[x]=i,fd0(x+1,ln);
    }
}ll calc2(int c){
    int len=0;
    while((1<<len)<c) len++;
    for(int i=1;i<=(1<<len);i++) if(i<=c) b[i]=a[i];else b[i]=-1;
    ll ans=0;s.clear(),fd0(1,(1<<len));
    for(auto ed:s){
        ans+=ed;
    }return ans;
}
void slv(){
    for(int i=0;i<=3;i++) cin>>x[i];
    for(int i=1;i<=n;i++) a[i]=a0[i]^x[i%4];
    ll ans=0;
    for(int i=1;i<=m;i++){
        ans^=calc2(c[i])*i;
        //cout<<calc2(c[i])<<' ';
    }cout<<ans<<endl;
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a0[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int len=0;while((1<<len)<n) len++;
    for(int i=1;i<=len;i++){
        string s;cin>>s;
        int ln=s.length();s=' '+s;
        for(int j=1;j<=ln;j++){
            d0[i][j]=s[j]-'0';
        }
    }
    int t;cin>>t;while(t--) slv();
    fclose(stdin);fclose(stdout);
    return 0;
}