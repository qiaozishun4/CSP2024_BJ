#include<bits/stdc++.h>
using namespace std;
int a[100005];
int vis[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=a[i];
    }
    int ans=n;
    sort(a+1,a+1+n);
    sort(vis+1,vis+n+1);
    for(int i=1;i<n;i++){
        int x=upper_bound(vis+i+1,vis+n,a[i])-vis;
        if(vis[x]<=a[i]){
            break;
        }
        //cout<<x<<" "<<vis[x]<<endl;
        vis[x]=0;
        ans--;
    }
    cout<<ans;
    return 0;
}
