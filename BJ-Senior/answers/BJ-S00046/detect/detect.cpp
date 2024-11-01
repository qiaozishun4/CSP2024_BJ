#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],d[100005],ans=0;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    while(T--){
        int n,m,l,v;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        for(int i=m;i>=1;i--) cin>>d[i];
        for(int i=1;i<=n;i++){
            if(c[i]>d[1]||b[i]<v) continue;
            else ans++;
        }
    }
    cout<<ans<<" "<<m-1;
    return 0;
}
