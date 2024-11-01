#include <bits/stdc++.h>
using namespace std;
int n,a[100010],vis[100010],vis2[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int ans=0,maxx=0;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(vis[a[j]]>1 || vis[a[i]]>1 || vis2[a[j]]==1 || vis2[a[i]]==1 || a[i]==a[j])  continue;
            vis2[a[i]]++;
            vis[a[j]]++;
            ans++;
            for(int k=1;k<=n;k++){
                if(vis2[a[k]]==1 && i==n){
                    if(maxx<ans)  maxx=ans;
                    ans=0;
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}
