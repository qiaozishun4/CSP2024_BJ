#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[200005];
bool a1[200005];
int dfs(int x,int red,int blue){
    if(x>n)return 0;
    int ans=0;
    ans=dfs(x+1,a[x],blue)+((a[x]==red)?a[x]:0);
    ans=max(ans,dfs(x+1,red,a[x])+((a[x]==blue)?a[x]:0));
    return ans;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        cout<<dfs(1,0,0)<<endl;
    }
    return 0;
}
