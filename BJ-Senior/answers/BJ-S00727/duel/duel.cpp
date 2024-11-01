#include <bits/stdc++.h>
using namespace std;
const int MAXN=10005;
int n;
int a[MAXN];
int vis[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    //i的攻击，j防御。
    for(int i=1;i<=MAXN;i++)
        vis[i]=1;
    int ans=n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(vis[j]&&a[j]<a[i]){
                ans--;
                vis[j]=0;
                j+=n-j+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
