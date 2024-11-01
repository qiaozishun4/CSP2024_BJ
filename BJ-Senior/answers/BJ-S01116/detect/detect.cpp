#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,l,v,d[maxn],vh[maxn],a[maxn],p[maxn],ans1=0,ans2=0,judge[maxn];
int dedect(int d1,int v1,int a1){//a1
    int user=0;
    if(a1<=0){
        for(int i=1;i<=m;i++){
            if(p[i]>=d1){
                if(sqrt(v1*v1+2*a1*(p[i]-d1))>v){
                    user=1;
                    judge[i]=1;
                    return user;
                }
            }
        }
    }
    else{
        if((d1+(v*v-v1*v1)/(2*a1))<p[m]){
            user=1;
            judge[m]=1;
        }
    }
    return user;
}
void solve(){
    cin>>n>>m>>l>>v;
    for(int i=1;i<=n;i++){
        cin>>d[i]>>vh[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        ans1+=dedect(d[i],vh[i],a[i]);
    }
    for(int i=1;i<=m;i++){
        if(judge[i]==0) ans2++;
    }
    cout<<ans1<<" "<<ans2<<endl;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}