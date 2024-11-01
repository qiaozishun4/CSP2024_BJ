#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n;
int a[N];
long long ans=0;
void dfs(int i,int z,int red,int blue){
    if(i>n){
        if(z>ans) ans=z;
        return;
    }
    if(red==a[i]){
        dfs(i+1,z+a[i],red,blue);
    }
    else if(blue==a[i]){
        dfs(i+1,z+a[i],red,blue);
    }
    else{
        dfs(i+1,z,a[i],blue);
        dfs(i+1,z,red,a[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        //memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
           cin>>a[i];
        }
        dfs(1,0,-1,-1);
        cout<<ans<<endl;
    }
    cout.flush();
    return 0;
}