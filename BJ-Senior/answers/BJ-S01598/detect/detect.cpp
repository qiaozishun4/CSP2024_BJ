#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int t,n,m,l,v;
struct node{
    int d,v,ac;
}a[100005];
int p[100005];
bool check_0(){
    for(int i=1;i<=n;i++) if(a[i].ac!=0) return false;
    return true;
}
bool check_1(){
    for(int i=1;i<=n;i++) if(a[i].ac<0) return false;
    return true;
}bool check_2(){
    for(int i=1;i<=n;i++) if(a[i].ac>0) return false;
    return true;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].ac;
        for(int i=1;i<=m;i++) cin>>p[i];
        if(check_0()){
            for(int i=1;i<=n;i++){
                if(a[i].v>v&&a[i].d<=p[m]) ans++;
            }
            if(ans==0) m++;
            cout<<ans<<' '<<m-1<<'\n';
        }else if(check_1()){
            double r;
            for(int i=1;i<=n;i++){
                if(a[i].d>p[m]) continue;
                r=sqrt(a[i].v*a[i].v*1.0+a[i].ac*(p[m]-a[i].d)*2.0);
                if(r>v) ans++;
            }
            if(ans==0) m++;
            cout<<ans<<' '<<m-1<<'\n';
        }else{
            double r;
            for(int i=1;i<=n;i++){
                if(a[i].v<=v||a[i].d>p[m]) continue;
                r=sqrt(a[i].v*a[i].v*1.0+a[i].ac*(p[m]-a[i].d)*2.0);
                if(r<v) continue;
                ans++;
            }
            cout<<ans<<' '<<0<<'\n';
        }
    }
    return 0;
}
