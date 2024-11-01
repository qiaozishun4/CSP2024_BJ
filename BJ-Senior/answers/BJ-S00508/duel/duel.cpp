#include <bits/stdc++.h>
using namespace std;
int n,a[100010],cnt=0,now=0,ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            now+=cnt;
            cnt=1;
        }
        else cnt++;
        if(now!=0){
            now--;
            ans++;
        }
    }
    cout<<n-ans;
    return 0;
}
