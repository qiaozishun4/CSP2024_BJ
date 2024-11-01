#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,w;
long long k;
long long d[100005],v[100005],a[100005],p[100005];
//int t[100005];
//bool f[100005];
int tmp[100005],ans;
void dfs(int step,int tot){
    if(step==m+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!tmp[j])continue;
                if(d[i]<=p[j]&&v[i]*v[i]*1LL+2*a[i]*(p[j]-d[i])*1LL>k*k){
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==w)ans=max(ans,tot);
        return;
    }
    if(m-step+tot<ans)return ;
    tmp[step]=1;
    dfs(step+1,tot);
    tmp[step]=0;
    dfs(step+1,tot+1);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        bool f1=1,f2=1;
        //memset(f,0,sizeof(f));
        cin>>n>>m>>l>>k;
        int cnt=0,maxx=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            //if(v[i]>k)cnt++;
            if(a[i]!=0)f1=0;
            if(a[i]<=0)f2=0;
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        if(f1){
            for(int i=1;i<=n;i++){
                if(v[i]>k&&d[i]<=p[m])cnt++;
            }
            if(cnt==0)cout<<cnt<<" "<<m<<endl;
            else cout<<cnt<<" "<<m-1<<endl;
        }
        else if(f2){
            for(int i=1;i<=n;i++){
                if(d[i]<=p[m]&&v[i]*v[i]*1LL+2*a[i]*(p[m]-d[i])*1LL>k*k){
                    cnt++;
                }
            }
            cout<<cnt<<" ";
            if(cnt>0)cout<<m-1<<endl;
            else cout<<m<<endl;
        }
        else {
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(d[i]<=p[j]&&v[i]*v[i]*1LL+2*a[i]*(p[j]-d[i])*1LL>k*k){
                        cnt++;
                        break;
                    }
                }
            }
            memset(tmp,0,sizeof(tmp));
            cout<<cnt<<" ";
            w=cnt;ans=0;
            dfs(1,0);cout<<ans<<endl;
        }
    }
    return 0;
}
