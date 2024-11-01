#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,v,a;
}c[100005];
int p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].v>V) ans++;
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        cout<<ans<<endl;
        cout<<max(0,m-ans);
    }
    return 0;
}
