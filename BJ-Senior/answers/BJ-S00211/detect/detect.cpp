#include <bits/stdc++.h>
using namespace std;
struct node{
    int d,v,a;
}c[100008];
int n,t,m,l,v,ans,p[100008];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>l>>v;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            if(c[i].d<=p[m]&&c[i].v>v){
                ans++;
            }
        }
        m--;
        if(ans==0){
            m++;
        }
        cout<<ans<<" "<<m<<endl;
    }
    return 0;
}
