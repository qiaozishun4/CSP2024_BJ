#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001],vis[1000001],cnt;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        cnt=0;
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(vis[a[i]])cnt+=a[i];
            vis[a[i]]=1;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}