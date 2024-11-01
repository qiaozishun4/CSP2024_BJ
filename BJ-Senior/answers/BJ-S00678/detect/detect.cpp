#include<bits/stdc++.h>
using namespace std;
double a[100005];
double d[100005];
double v[100005];
double p[100005];
double cmp[100005];
double  cmp1[100005];
double  x[100005];
double  flag=0;
double  n,m,l;
double V;
void dfs(int cur){
    if(flag) return ;
    if(cur>m){
        for(int i=1;i<=n;i++) cmp1[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]<d[i]) continue;
                if(x[j]==0) continue;
                double s=p[j]-d[i];
                double xx=sqrt(v[i]*v[i]+2*a[i]*s);
                if(xx>V){
                    cmp1[i]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            //cout<<cmp1[i]<<" ";
            if(cmp1[i]!=cmp[i]){
                return ;
            }
        }
        double cnt=0;
        for(int i=1;i<=m;i++){
            if(!x[i]) cnt++;
        }
        cout<<cnt<<endl;
        flag=1;
        return ;
    }
    for(int i=0;i<=1;i++){
        x[cur]=i;
        dfs(cur+1);
        if(flag) return ;
    }
}
void solve(){
    memset(cmp,0,sizeof(cmp));
    cin>>n>>m>>l>>V;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    double  cnt=0;
    for(int i=1;i<=n;i++){
        double  f=0;
        for(int j=1;j<=m;j++){
            if(p[j]<d[i]) continue;
            double s=p[j]-d[i];
            double xx=sqrt(v[i]*v[i]+2*a[i]*s);
            if(xx>V){
                f=1;
                cmp[i]=1;
                break;
                //cout<<j<<" ";
            }
        }
        //cout<<endl;
        cnt+=f;
    }
    cout<<cnt<<" ";
    flag=0;
    dfs(1);
}
int main (){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
