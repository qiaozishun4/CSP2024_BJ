#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1e5+7;
int d[N],v[N],a[N],p[N],ans,maxn;
int n,m,L,V;
void solve(){
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>v[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        if(v[i]>V&&p[m]>=d[i])ans++;
    }
    cout<<ans<<' '<<m-1<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

