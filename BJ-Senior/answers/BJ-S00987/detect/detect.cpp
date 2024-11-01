#include <bits/stdc++.h>
using namespace std;
int n,m,l,V,d[25],v[25],a[25],s[25];
bool open[25];
int calv(int d,int v,int a){
    if(v*v+2*a*d<=0)return 0;
    return ceil(sqrt(v*v+2*a*d));
}
int chk(){
    int ans=0;
    for(int i=1;i<=n;i++){
        bool flag=0;
        for(int j=1;j<=m;j++){
            if(s[j]<d[i])continue;
            if(!open[j])continue;
            if(calv(s[j]-d[i],v[i],a[i])>V){
                //cout<<"car "<<i<<" exceeded the speed limit,it's speed:"<<calv(s[j]-d[i],v[i],a[i])<<"\n";
                flag=1;
                break;
            }else if(calv(s[j]-d[i],v[i],a[i])==0)break;
        }
        ans+=flag;
    }
    return ans;
}
int num=0;
int ans=0;
int dfs(int jc){
    if(jc==m+1){
        return (chk()==ans?num:2147483647);
    }
    num++;
    open[jc]=1;
    int ret=dfs(jc+1);
    num--;
    open[jc]=0;
    ret=min(ret,dfs(jc+1));
    return ret;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>V;
        num=0;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>s[i],open[i]=1;
        ans=chk();
        cout<<ans<<" "<<m-dfs(1)<<"\n";
    }
    return 0;
}