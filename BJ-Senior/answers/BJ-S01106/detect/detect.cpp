#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
double d[N],vi[N],a[N];
double p[N];
int n,m,l,v;
bool vis[N];
int ans;
void solve1(int x,int s){
    if(x>m){
        bool flag1=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0)continue;
            bool flag=0;
            for(int j=1;j<=m;j++){
                if(((1<<(j-1))&s)==0)continue;
                int s1=p[j]-d[i];
                if(s1<0)continue;
                if(sqrt(vi[i]*vi[i]+2.0*a[i]*s1)>v){
                    flag=1;
                }
            }
            if(flag==0){
                flag1=1;
            }
        }
        if(flag1==0){
            int cnt=0;
            for(int i=1;i<=m;i++){
                if(((1<<(i-1))&s)==0)cnt++;
            }
            ans=max(ans,cnt);
        }
        return;
    }
    solve1(x+1,s+(1<<(x-1)));
    solve1(x+1,s);
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
        memset(vi,0,sizeof vi);
        memset(a,0,sizeof a);
        memset(p,0,sizeof p);
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>vi[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        if(n<=20&&m<=20){
            int ans1=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    double s=p[j]-d[i];
                    if(s<0)continue;
                    if(sqrt(vi[i]*vi[i]+2.0*a[i]*s)>v){
                        vis[i]=1;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(vis[i]==1){
                    ans1++;
                }
            }
            solve1(1,0);
            cout<<ans1<<" "<<ans<<endl;
            continue;
        }
        else if(a[1]==0){
            int ans1=0;
            for(int i=1;i<=n;i++){
                if(vi[i]>v&&d[i]<=p[m]){
                    vis[i]=1;
                }
            }
            for(int i=1;i<=n;i++){
                if(vis[i]==1){
                    ans1++;
                }
            }
            if(ans1==0)ans=m;
            else ans=m-1;
            cout<<ans1<<" "<<ans<<endl;
            continue;
        }
        else{
            int ans1=0;
            for(int i=1;i<=n;i++){
                double s=p[m]-d[i];
                if(s<0)continue;
                if(sqrt(vi[i]*vi[i]+2.0*a[i]*s)>v){
                    vis[i]=1;
                }
            }
            for(int i=1;i<=n;i++){
                if(vis[i]==1){
                    ans1++;
                }
            }
            if(ans1==0)ans=m;
            else ans=m-1;
            cout<<ans1<<" "<<ans<<endl;
            continue;
        }
    }
    return 0;
}
