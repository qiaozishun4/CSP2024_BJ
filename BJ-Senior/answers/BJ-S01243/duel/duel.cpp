#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100005];
int vis[100005], ans;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
        int p=upper_bound(a+i, a+n+1, a[i])-a;
        while(p<=n&&vis[p]!=0)
            p++;
        if(p<=n){
            vis[i]=-1;
            vis[p]=1;
            ans++;
        }
        else break;
    }
    cout<<n-ans<<endl;
    return 0;
}
