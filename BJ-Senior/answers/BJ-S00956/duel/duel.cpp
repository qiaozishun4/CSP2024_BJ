#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N],vis[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int now=1;
    for(int i=1;i<=n;i++){
        vis[now]=1;
        while(now<=n&&(vis[now]||a[i]>=a[now])) now++;
        if(now>n) break;
        ans++;
        vis[now]=1;
    }
    printf("%d\n",n-ans);
    return 0;
}
