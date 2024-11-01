#include<iostream>
#include<cmath>
using namespace std;
int t,n,m,q,p,ans,num;
int d[100001],v[100001],a[100001],b[100001];
bool vis[100001];
void dfs(int x,int y){
    if(x==m+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            int fl=0;
            for(int j=1;j<=m;j++){
                if(vis[j]==1){
                    if(sqrt(v[i]*v[i]*1.0+2.0*a[i]*(b[j]-d[i]))>p&&b[j]>=d[i]){
                        fl=1;
                    }
                }
            }
            if(fl==1){
                cnt++;
            }
        }
        if(ans==cnt){
            num=min(num,y);
        }
        return;
    }
    dfs(x+1,y);
    vis[x]=1;
    dfs(x+1,y+1);
    vis[x]=0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int f=0,f2=0;
        cin>>n>>m>>q>>p;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]!=0){
                f=1;
            }
            if(a[i]<=0){
                f2=1;
            }
        }
        int maxx=0;
        for(int i=1;i<=m;i++){
            cin>>b[i];
            maxx=max(b[i],maxx);
        }
        if(f==0){
            for(int i=1;i<=n;i++){
                if(v[i]>p&&d[i]<=maxx){
                    ans++;
                }
            }
            if(ans!=0){
                cout<<ans<<" "<<m-1<<endl;
            }else{
                cout<<ans<<" "<<m<<endl;
            }
        }else if(f2==0){
            for(int i=1;i<=n;i++){
                if(d[i]<=maxx){
                    if(sqrt(v[i]*v[i]*1.0+2.0*a[i]*(maxx-d[i]))>p){
                        ans++;
                    }
                }
            }
            if(ans!=0){
                cout<<ans<<" "<<m-1<<endl;
            }else{
                cout<<ans<<" "<<m<<endl;
            }
        }else{
            ans=0;
            num=1000000;
            for(int i=1;i<=m;i++){
                vis[i]=0;
            }
            for(int i=1;i<=n;i++){
                int fl=0;
                for(int j=1;j<=m;j++){
                    if(sqrt(v[i]*v[i]*1.0+2.0*a[i]*(b[j]-d[i]))>p&&b[j]>=d[i]){
                        fl=1;
                    }
                }
                if(fl==1){
                    ans++;
                }
            }
            cout<<ans<<" ";
            dfs(1,0);
            cout<<m-num<<endl;
        }
    }
    return 0;
}
