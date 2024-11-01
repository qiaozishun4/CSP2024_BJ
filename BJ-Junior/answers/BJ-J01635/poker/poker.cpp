#include <bits/stdc++.h>
using namespace std;
int vis[26][205];
const int d[]={2,3,7,18},ex[]={'A','T','J','Q','K'};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=0;cin>>n;
    while(n--){
        char a,b;cin>>a>>b;
        vis[a-'A'][b]=1;
    }
    for(int i=0;i<4;i++){
        for(int j='2';j<='9';j++) if(!vis[d[i]][j]) ans++;
        for(int j=0;j<5;j++) if(!vis[d[i]][ex[j]]) ans++;
    }
    cout<<ans;
    return 0;
}
//CSP rp++;
