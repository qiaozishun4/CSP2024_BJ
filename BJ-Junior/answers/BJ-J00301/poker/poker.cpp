#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
bool vis[100000];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(vis[a*100+b]==0){
            vis[a*100+b]=1;
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
