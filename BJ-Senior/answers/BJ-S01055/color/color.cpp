#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<string>
using namespace std;
int a[200010],b[200010];
int n,mx;
void dfs(int x){
    if(x>n){
        int ans=0;
        for(int i=1;i<=n;i++){
            int c=0;
            for(int j=i-1;j>=1;j--){
                if(b[j]==b[i]){
                    if(a[j]==a[i])c=a[i];
                    break;
                }
            }
            ans+=c;
        }
        mx=max(mx,ans);
        return;
    }
    b[x]=1;
    dfs(x+1);
    b[x]=0;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mx=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(0);
        cout<<mx<<endl;
    }
    return 0;
}
