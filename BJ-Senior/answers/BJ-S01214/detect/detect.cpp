#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,v,a;
}aa[100005];
int b[100005],n,m,t,l,v,las;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>t;
    int ans=0;
    while(t--){
        las=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=100004;++i){
            aa[i].d=0,aa[i].v=0,aa[i].a=0,b[i]=0;
        }
        ans=0;
        for(int i=1;i<=n;++i){
            cin>>aa[i].d>>aa[i].v>>aa[i].a;
        }
        for(int i=1;i<=m;++i) cin>>b[i],las=max(las,b[i]);
        for(int i=1;i<=n;++i){
            if(sqrt(aa[i].v*aa[i].v+2*aa[i].a*(las-aa[i].d))>v&&aa[i].d<=las) ans++;
        }
        cout<<ans<<" "<<(ans==0?m:m-1)<<endl;
    }
}