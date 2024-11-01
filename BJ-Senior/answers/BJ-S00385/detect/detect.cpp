#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+5;
ll d[MAXN],v[MAXN],a[MAXN],p[MAXN],flag[MAXN][25],box[MAXN],vis[MAXN],t[MAXN],e[MAXN];
ll n,m,L,V,res;
ll T;
void dfs(ll cur,ll step){
    if(cur==step+1){
        ll fl=1;
        for(int i=1;i<=n;i++){
            if(t[i]==0 ) continue;
            ll tmp=0;
            for(int j=1;j<=step;j++){
                if(flag[i][box[j]]==1) tmp=1;
            }
            if(tmp==0){
                fl=0;
                return;
            }
        }
        if(fl==1){
            res=min(res,step);
        /*if(T==9){

        for(int i=1;i<=step;i++)    cout<<box[i]<<' ';
        cout<<"STT"<<endl;
        }*/
        }
    }
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            vis[i]=1;
            box[cur]=i;
            dfs(cur+1,step);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        ll flag1=0,flag2=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<=0)  flag1=1;
            if(a[i]!=0) flag2=1;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        ll ans=0;
        if(flag1==0){
            for(int i=1;i<=n;i++){
                if(d[i]>p[m])   continue;
                int dis=p[m]-d[i];
                if(v[i]*v[i]+2*dis*a[i]>V*V)  ans++;
            }
            if(ans==0)  cout<<0<<' '<<m<<endl;
            else cout<<ans<<' '<<m-1<<endl;
        }
        else if(flag2==0){
            for(int i=1;i<=n;i++){
                if(d[i]<=p[m] && v[i]>V){
                    ans++;
                }
            }
            if(ans==0)  cout<<0<<' '<<m<<endl;
            else cout<<ans<<' '<<m-1<<endl;
        }
        else{
            memset(flag,0,sizeof(flag));
            memset(vis,0,sizeof(vis));
            memset(t,0,sizeof(t));
            memset(e,0,sizeof(e));
            for(int i=1;i<=n;i++){
                /*if(a[i]==0){
                    if(d[i]<=p[m] && v[i]>V)    ans++;
                }
                else if(a[i]>0){
                    if(d[i]>p[m])   continue;
                    int dis=p[m]-d[i];
                    if(v[i]*v[i]+2*dis*a[i]>V*V)  ans++;
                }
                else{*/
                    for(int j=1;j<=m;j++){
                        if(d[i]>p[j])   continue;
                        int dis=p[j]-d[i];
                        if(v[i]*v[i]+2*dis*a[i]>V*V)   flag[i][j]=1,t[i]=1;
                    }
                //}
            }
            ll cnt=0;
            for(int i=1;i<=n;i++){
                int o=0;
                for(int j=1;j<=m;j++){
                    if(flag[i][j]==1)   o=1;
                }
                if(o==0 && flag[i][m]==1)   cnt++,e[i]=1;
            }
            res=m;
            for(int i=1;i<=m;i++) {
                dfs(1,i);
                if(res!=m)  break;
            }
            ll sum=0;
            for(int i=1;i<=m;i++)   if(t[i]==1) sum++;

            //if(ans==0 && cnt==0){
                 //   cout<<"STH";
                //cout<<sum<<' '<<res<<endl;
                cout<<ans+sum<<' '<<m-res<<endl;
           // }
           // else{
              //  cout<<ans+sum<<' '<<m-res-1;
           // }
            //if(T==9)  {
                   /* for(int i=1;i<=n;i++){
                        for(int j=1;j<=m;j++)   cout<<flag[i][j]<<' ';
                        cout<<endl;
                    }*/

            //}
            //cout<<' '<<"SSS"<<ans<<' '<<cnt<<' '<<sum<<' '<<res<<endl;
        }
    }
    return 0;
}
